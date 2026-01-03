// main.cpp - 主程序入口
// 注意：先包含标准库，再包含自定义头文件，避免类型冲突
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include <stdarg.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <pthread.h>
#include <wchar.h>
#include <getopt.h>
#include <SDL2/SDL.h>

// 包含自定义头文件（在标准库之后）
#include "drastic_val.h"
#include "drastic_functions.h"
#include "drastic_cpu.h"
#include "drastic_modules.h"

// SDL_Rect 前向声明（如果SDL.h中没有定义）
#ifndef SDL_Rect
struct SDL_Rect {
  int x, y, w, h;
};
#endif

// 声明缺失的函数
extern "C" {
void __stack_chk_fail();
char* __strcpy_chk(char* dest, const char* src, size_t destlen);
int __longjmp_chk(void* env, int val);
int __xstat(int version, const char* path, struct stat* buf);
int __snprintf_chk(char* str, size_t maxlen, int flag, size_t strlen, const char* format, ...);
}

int main(int param_1, char** param_2)
{
  int iVar1;
  undefined8 uVar2;
  
  printf("Starting DraStic (version %s)\n\n","r2.5.2.2");
  *(undefined8*)(nds_system + 0x57482784) = 0xffffffffffffffff;
  initialize_system((long)nds_system);
  //process_arguments((long)nds_system,param_1,param_2);
  initialize_screen(*(uint*)(nds_system + 0x3b2a9a9));
  if (param_1 < 2) {
    menu((long)nds_system,1);
  }
  else {
    uVar2 = *(undefined8 *)(param_2 + (long)param_1 * 8 + -8);
    printf("Loading gamecard file %s.\n",(char*)uVar2);
    iVar1 = load_nds(0x4fc320,(char*)uVar2);
    if (iVar1 != 0) {
      puts("Gamecard load failed.");
      return 0xffffffff;
    }
    set_screen_menu_off();
    reset_system((undefined8)nds_system);
  }
  _setjmp((__jmp_buf_tag *)(nds_system + 0x3b2a840));
  if (nds_system[0x3b2a9a8] == '\0') {
    cpu_next_action_arm7_to_event_update((long)nds_system);
  }
  else {
    printf("Calling recompiler event update handler (@ %p).\n",*(void**)(nds_system + 0x22847464));
    printf("Memory map offset %p, translate cache pointer %p\n",*(void**)(nds_system + 0x57482784),
                 (void*)0x588000);
    //recompiler_entry((long)nds_system,*(undefined8*)(nds_system + 0x57482784));
    cpu_next_action_arm7_to_event_update((long)nds_system);
  }
  return 0;
}
