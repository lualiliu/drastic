# 模块化说明

## 项目结构

本项目已进行模块化重构，主要文件包括：

### 头文件
- `drastic_val.h` - 类型定义和全局变量声明
- `drastic_functions.h` - 函数声明（从反编译代码生成）
- `drastic_cpu.h` - CPU相关函数
- `drastic_modules.h` - 模块化函数声明（新增）

### 源文件
- `main.cpp` - 主程序入口（从drastic.cpp中提取）
- `file.cpp` - 文件操作模块（包含load_nds等函数）
- `system.cpp` - 系统初始化和重置模块（占位符）
- `screen.cpp` - 屏幕相关模块（占位符）
- `cpu_module.cpp` - CPU相关模块（占位符）
- `misc.cpp` - 其他杂项函数模块（占位符）
- `drastic.cpp` - 主源文件（包含所有函数实现，向后兼容）

### Makefile
- `Makefile` - 支持模块化编译的构建脚本

## 编译说明

### 基本编译
```bash
make
```

### 清理
```bash
make clean
```

### 重新构建
```bash
make rebuild
```

## 模块化策略

1. **渐进式迁移**：函数从`drastic.cpp`逐步迁移到对应的模块文件中
2. **向后兼容**：`drastic.cpp`保留所有函数实现，确保编译通过
3. **避免重复定义**：使用头文件保护和正确的包含顺序

## 注意事项

1. 头文件包含顺序很重要：先包含标准库，再包含自定义头文件
2. 类型定义顺序：基础类型（如ulong）必须在函数指针类型之前定义
3. 函数声明必须与`drastic_functions.h`中的声明一致

## 待完成工作

- [ ] 将更多函数从drastic.cpp迁移到对应模块
- [ ] 修复编译警告
- [ ] 完善模块间的依赖关系
