# Makefile for DraStic Emulator

# 编译器设置
CXX = g++
CXXFLAGS = -g -fpermissive -I. -I./SDL2
LDFLAGS = -lSDL2 -L/usr/lib/x86_64-linux-gnu

# 源文件
MAIN_SRC = main.cpp
SYSTEM_SRC = system.cpp
VIDEO_SRC = video.cpp
MEMORY_SRC = memory.cpp
AUDIO_SRC = audio.cpp
INPUT_SRC = input.cpp
GAMECARD_SRC = gamecard.cpp
EVENTS_SRC = events.cpp
CONFIG_SRC = config.cpp
MENU_SRC = menu.cpp
FILESYSTEM_SRC = filesystem.cpp
CPU_SRC = cpu.cpp
RTC_SRC = rtc.cpp
SPI_SRC = spi.cpp

# 所有源文件（保留drastic.cpp作为主要实现文件，逐步迁移）
# 注意：由于代码重构需要时间，目前主要实现仍在drastic.cpp中
# 模块文件暂时为空或只包含声明，避免重复定义
SOURCES = $(MAIN_SRC) \
          drastic.cpp

# 目标文件
OBJECTS = $(SOURCES:.cpp=.o)

# 可执行文件
TARGET = drastic

# 默认目标
all: $(TARGET)

# 链接可执行文件
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# 编译规则
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理
clean:
	rm -f $(OBJECTS) $(TARGET)

# 重新编译
rebuild: clean all

.PHONY: all clean rebuild
