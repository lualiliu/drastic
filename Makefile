# Makefile for DraStic - 模块化编译

# 编译器设置
CXX = g++
CXXFLAGS = -g -fpermissive -I. -std=c++11
LDFLAGS = -lSDL2 -lpthread

# 源文件目录
SRCDIR = .
OBJDIR = obj

# 源文件列表（模块化）
SOURCES = main.cpp

# 模块文件列表
MODULE_FILES = file.cpp system.cpp screen.cpp cpu_module.cpp misc.cpp

# 检查哪些模块文件存在（非空文件）
EXISTING_MODULES = $(shell for f in $(MODULE_FILES); do if [ -f "$$f" ] && [ -s "$$f" ]; then echo "$$f"; fi; done)
SOURCES += $(EXISTING_MODULES)

# drastic.cpp包含所有函数的实现
# 当模块文件存在时，它们会提供部分函数的实现
# 链接器会优先使用模块文件中的实现
ifneq ($(wildcard drastic.cpp),)
    SOURCES += drastic.cpp
endif

# 对象文件列表
OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)

# 目标可执行文件
TARGET = drastic

# 默认目标
all: $(OBJDIR) $(TARGET)

# 创建对象文件目录
$(OBJDIR):
	mkdir -p $(OBJDIR)

# 链接目标
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)
	@echo "构建完成: $(TARGET)"

# 编译规则
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理
clean:
	rm -rf $(OBJDIR) $(TARGET)
	@echo "清理完成"

# 重新构建
rebuild: clean all

# 帮助信息
help:
	@echo "可用的make目标:"
	@echo "  all      - 构建项目（默认）"
	@echo "  clean    - 清理构建文件"
	@echo "  rebuild  - 重新构建项目"
	@echo "  help     - 显示此帮助信息"

.PHONY: all clean rebuild help
