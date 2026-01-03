# 编译说明

## 代码组织

代码已按功能模块整理到不同的文件中：

### 主要模块

- **main.cpp** - 主程序入口
- **system.cpp/h** - 系统初始化和重置
- **video.cpp/h** - 视频和屏幕管理
- **memory.cpp/h** - 内存管理
- **audio.cpp/h** - 音频系统
- **input.cpp/h** - 输入处理
- **gamecard.cpp/h** - 游戏卡管理
- **events.cpp/h** - 事件系统
- **config.cpp/h** - 配置管理
- **menu.cpp/h** - 菜单系统
- **filesystem.cpp/h** - 文件系统
- **cpu.cpp/h** - CPU管理
- **rtc.cpp/h** - 实时时钟
- **spi.cpp/h** - SPI外设

### 核心文件

- **drastic.cpp** - 主要实现文件（包含大部分函数实现）
- **drastic_val.h** - 类型定义和全局变量声明
- **drastic_functions.h** - 函数声明
- **drastic_cpu.h** - CPU相关函数实现

## 编译要求

1. **编译器**: g++ (支持C++11)
2. **依赖库**: SDL2
3. **编译选项**: -fpermissive (允许一些不严格的类型转换)

## 编译步骤

### 安装SDL2

```bash
# Ubuntu/Debian
sudo apt-get install libsdl2-dev

# 或者指定SDL2库路径
export SDL2_PATH=/usr/lib/x86_64-linux-gnu
```

### 编译

```bash
make clean
make
```

### 如果SDL2库路径不同

修改Makefile中的LDFLAGS，添加正确的库路径：

```makefile
LDFLAGS = -lSDL2 -L/path/to/sdl2/lib
```

## 注意事项

1. 当前代码结构保持向后兼容，主要实现仍在drastic.cpp中
2. 模块文件（system.cpp, video.cpp等）目前为空或只包含声明
3. 可以逐步将drastic.cpp中的函数迁移到对应的模块文件中
4. 所有函数声明已在对应的头文件中定义

## 编译状态

- ✅ 代码结构已模块化
- ✅ 头文件组织完成
- ✅ Makefile已创建
- ✅ 编译错误已修复（除SDL2库链接外，这是环境问题）
