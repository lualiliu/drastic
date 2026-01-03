#!/usr/bin/env python3
import re
import subprocess

# 获取所有 undefined reference 的函数名
result = subprocess.run(['bash', 'make.sh'], capture_output=True, text=True, cwd='/home/luali/github/drastic')
output = result.stderr

# 提取所有 undefined reference 的函数名
undefined_functions = set()
for line in output.split('\n'):
    if 'undefined reference to' in line:
        match = re.search(r"undefined reference to `([^']+)'", line)
        if match:
            func_name = match.group(1)
            undefined_functions.add(func_name)

# 读取 source_ref.cpp
with open('/home/luali/github/drastic/source_ref.cpp', 'r') as f:
    content = f.read()

# 查找每个函数和变量的定义
extracted_functions = []
extracted_variables = []

for symbol_name in sorted(undefined_functions):
    # 首先尝试查找函数定义
    # 查找函数定义，可能的形式：
    # void func_name(...)
    # int func_name(...)
    # long func_name(...)
    # undefined8 func_name(...)
    # 等等
    pattern = rf'^(void|int|long|undefined\d+|uint|ulong|char|float|double|.*\*)\s+{re.escape(symbol_name)}\s*\([^)]*\)'
    match = re.search(pattern, content, re.MULTILINE)
    if match:
        start_pos = match.start()
        # 找到函数体的结束位置（匹配大括号）
        brace_count = 0
        in_function = False
        end_pos = start_pos
        
        for i in range(start_pos, len(content)):
            if content[i] == '{':
                brace_count += 1
                in_function = True
            elif content[i] == '}':
                brace_count -= 1
                if in_function and brace_count == 0:
                    end_pos = i + 1
                    break
        
        func_code = content[start_pos:end_pos]
        extracted_functions.append((symbol_name, func_code, 'function'))
        print(f"找到函数: {symbol_name} (长度: {len(func_code)} 字符)")
    else:
        # 尝试查找变量声明
        # 变量可能的形式：
        # undefined8 var_name;
        # undefined1[28] var_name;
        # pointer var_name;
        # 注意：变量名可能使用点号，但代码中使用下划线
        # 例如：psr_masks.11490 在代码中使用 psr_masks_11490
        var_name_escaped = re.escape(symbol_name).replace('_', '[._]')
        pattern = rf'^(undefined\d+|int|long|uint|ulong|char|float|double|pointer|string|FILE\s*\*|.*\*)(\[[^\]]*\])?\s+{var_name_escaped}\s*;'
        match = re.search(pattern, content, re.MULTILINE)
        if match:
            var_code = content[match.start():match.end()]
            extracted_variables.append((symbol_name, var_code, 'variable'))
            print(f"找到变量: {symbol_name}: {var_code.strip()}")
        else:
            # 尝试查找带点号的变量名（如 psr_masks.11490）
            parts = symbol_name.split('_')
            if len(parts) > 1:
                # 尝试将最后一部分作为数字，前面用点号连接
                try:
                    num = int(parts[-1])
                    base_name = '_'.join(parts[:-1])
                    dot_name = f"{base_name}.{num}"
                    pattern = rf'^(undefined\d+|int|long|uint|ulong|char|float|double|pointer|string|FILE\s*\*)(\[[^\]]*\])?\s+{re.escape(dot_name)}\s*;'
                    match = re.search(pattern, content, re.MULTILINE)
                    if match:
                        var_code = content[match.start():match.end()]
                        # 将点号替换为下划线以匹配实际使用
                        var_code_fixed = var_code.replace(dot_name, symbol_name)
                        extracted_variables.append((symbol_name, var_code_fixed, 'variable'))
                        print(f"找到变量(带点号): {symbol_name}: {var_code_fixed.strip()}")
                except ValueError:
                    pass

# 写入头文件
with open('/home/luali/github/drastic/drastic_missing_functions.h', 'w') as f:
    f.write("#ifndef DRASTIC_MISSING_FUNCTIONS_H\n")
    f.write("#define DRASTIC_MISSING_FUNCTIONS_H\n\n")
    f.write("// 从 source_ref.cpp 提取的未定义函数和变量\n\n")
    
    # 先写入变量声明
    if extracted_variables:
        f.write("// ========== 变量和数据声明 ==========\n\n")
        for var_name, var_code, var_type in extracted_variables:
            f.write(f"// Variable: {var_name}\n")
            f.write(f"extern {var_code}\n\n")
    
    # 再写入函数定义
    if extracted_functions:
        f.write("// ========== 函数定义 ==========\n\n")
        for func_name, func_code, func_type in extracted_functions:
            f.write(f"// Function: {func_name}\n")
            f.write(func_code)
            f.write("\n\n")
    
    f.write("#endif // DRASTIC_MISSING_FUNCTIONS_H\n")

print(f"\n总共提取了 {len(extracted_functions)} 个函数")
print(f"总共提取了 {len(extracted_variables)} 个变量")
print(f"输出文件: drastic_missing_functions.h")

