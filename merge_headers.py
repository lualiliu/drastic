#!/usr/bin/env python3
# 合并 drastic_missing_functions.h 到 drastic_functions.h

# 读取 drastic_missing_functions.h
with open('/home/luali/github/drastic/drastic_missing_functions.h', 'r') as f:
    missing_content = f.read()

# 读取 drastic_functions.h
with open('/home/luali/github/drastic/drastic_functions.h', 'r') as f:
    functions_content = f.read()

# 从 missing_content 中提取需要的内容
# 移除头文件 guard 和 include 语句
lines = missing_content.split('\n')
merged_lines = []

# 跳过开头的 guard 和 include
skip_until_content = True
for line in lines:
    if skip_until_content:
        if line.startswith('// ==========') or line.startswith('// 从 source_ref.cpp'):
            skip_until_content = False
            merged_lines.append('')
            merged_lines.append('// ========== 从 drastic_missing_functions.h 合并的内容 ==========')
            merged_lines.append('')
        elif line.startswith('#include') or line.startswith('#ifndef') or line.startswith('#define'):
            continue
        else:
            continue
    else:
        # 跳过结尾的 guard
        if line.startswith('#endif // DRASTIC_MISSING_FUNCTIONS_H'):
            break
        merged_lines.append(line)

merged_content = '\n'.join(merged_lines)

# 将合并的内容添加到 drastic_functions.h 的末尾（在 #endif 之前）
if functions_content.rstrip().endswith('#endif // DRASTIC_FUNCTIONS_H'):
    # 在 #endif 之前插入合并的内容
    functions_content = functions_content.rstrip()[:-len('#endif // DRASTIC_FUNCTIONS_H')]
    functions_content += merged_content + '\n\n'
    functions_content += '#endif // DRASTIC_FUNCTIONS_H\n'
else:
    # 如果格式不同，尝试其他方式
    functions_content = functions_content.rstrip() + '\n\n' + merged_content + '\n'

# 写回 drastic_functions.h
with open('/home/luali/github/drastic/drastic_functions.h', 'w') as f:
    f.write(functions_content)

print("已成功合并 drastic_missing_functions.h 到 drastic_functions.h")

