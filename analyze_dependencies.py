#!/usr/bin/env python3
import re

# 读取头文件
with open('/home/luali/github/drastic/drastic_missing_functions.h', 'r') as f:
    content = f.read()

# 提取所有函数名和它们的定义位置
functions = {}
function_pattern = r'^// Function: (\w+)\s*\n((?:void|int|long|undefined\d+|uint|ulong|char|float|double|.*\*)\s+\1\s*\([^)]*\)\s*\{[^}]*\})'
matches = list(re.finditer(r'^// Function: (\w+)', content, re.MULTILINE))

for match in matches:
    func_name = match.group(1)
    start_pos = match.start()
    # 找到函数体的结束
    brace_count = 0
    in_function = False
    end_pos = start_pos
    
    # 找到函数签名
    sig_match = re.search(rf'^(void|int|long|undefined\d+|uint|ulong|char|float|double|.*\*)\s+{re.escape(func_name)}\s*\([^)]*\)', content[start_pos:], re.MULTILINE)
    if sig_match:
        func_start = start_pos + sig_match.start()
        for i in range(func_start, len(content)):
            if content[i] == '{':
                brace_count += 1
                in_function = True
            elif content[i] == '}':
                brace_count -= 1
                if in_function and brace_count == 0:
                    end_pos = i + 1
                    break
        func_body = content[func_start:end_pos]
        functions[func_name] = {
            'start': func_start,
            'end': end_pos,
            'body': func_body
        }

print(f"找到 {len(functions)} 个函数")

# 分析每个函数调用了哪些其他函数
dependencies = {}
for func_name, func_info in functions.items():
    called_functions = set()
    func_body = func_info['body']
    
    # 查找函数调用（函数名后跟括号）
    for other_func in functions.keys():
        if other_func != func_name:
            # 查找函数调用模式：函数名( 或 函数名\n
            pattern = rf'\b{re.escape(other_func)}\s*\('
            if re.search(pattern, func_body):
                called_functions.add(other_func)
    
    dependencies[func_name] = called_functions
    if called_functions:
        print(f"{func_name} 调用: {', '.join(called_functions)}")

# 拓扑排序：按照依赖关系排序
def topological_sort(funcs, deps):
    # 计算每个函数的入度（被多少函数依赖）
    in_degree = {f: 0 for f in funcs}
    for func, deps_set in deps.items():
        for dep in deps_set:
            if dep in in_degree:
                in_degree[dep] += 1
    
    # 找到所有入度为0的函数（没有依赖的函数）
    queue = [f for f in funcs if in_degree[f] == 0]
    sorted_funcs = []
    
    while queue:
        func = queue.pop(0)
        sorted_funcs.append(func)
        
        # 减少被这个函数依赖的函数的入度
        for other_func, deps_set in deps.items():
            if func in deps_set and other_func in in_degree:
                in_degree[other_func] -= 1
                if in_degree[other_func] == 0:
                    queue.append(other_func)
    
    # 添加剩余的循环依赖函数
    remaining = [f for f in funcs if f not in sorted_funcs]
    sorted_funcs.extend(remaining)
    
    return sorted_funcs

sorted_functions = topological_sort(list(functions.keys()), dependencies)

print(f"\n排序后的函数顺序（前10个）:")
for i, func in enumerate(sorted_functions[:10]):
    print(f"{i+1}. {func}")

# 生成新的头文件
with open('/home/luali/github/drastic/drastic_missing_functions.h', 'w') as f:
    f.write("#ifndef DRASTIC_MISSING_FUNCTIONS_H\n")
    f.write("#define DRASTIC_MISSING_FUNCTIONS_H\n\n")
    f.write("// 从 source_ref.cpp 提取的未定义函数\n")
    f.write("// 已按依赖关系排序\n\n")
    
    # 先添加所有函数的前向声明
    f.write("// ========== 前向声明 ==========\n\n")
    for func_name in sorted_functions:
        func_info = functions[func_name]
        # 提取函数签名
        sig_match = re.search(r'^((?:void|int|long|undefined\d+|uint|ulong|char|float|double|.*\*)\s+\w+\s*\([^)]*\))', func_info['body'], re.MULTILINE)
        if sig_match:
            f.write(f"{sig_match.group(1)};\n")
    f.write("\n")
    
    # 按排序后的顺序添加函数定义
    f.write("// ========== 函数定义 ==========\n\n")
    for func_name in sorted_functions:
        func_info = functions[func_name]
        f.write(f"// Function: {func_name}\n")
        f.write(func_info['body'])
        f.write("\n\n")
    
    f.write("#endif // DRASTIC_MISSING_FUNCTIONS_H\n")

print(f"\n已重新生成头文件，函数已按依赖关系排序")

