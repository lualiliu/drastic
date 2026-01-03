// main.cpp - 主程序入口
// 注意：包含顺序很重要，先包含标准库，再包含自定义头文件
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include <SDL2/SDL.h>
#include "drastic_val.h"
#include "drastic_functions.h"
#include "drastic_cpu.h"
#include "system.h"
#include "video.h"
#include "gamecard.h"
#include "events.h"

extern "C" {
void __stack_chk_fail();
}

int main(int param_1, char** param_2)
{
  int iVar1;
  undefined8 uVar2;
  
  printf("Starting DraStic (version %s)\n\n","r2.5.2.2");
  *(undefined8*)(nds_system + 0x57482784) = 0xffffffffffffffff;
  initialize_system((long)nds_system);
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
    cpu_next_action_arm7_to_event_update((long)nds_system);
  }
  return 0;
}
