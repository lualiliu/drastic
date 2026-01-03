// menu.h - 菜单系统
#ifndef MENU_H
#define MENU_H

#include "drastic_val.h"

#ifdef __cplusplus
extern "C" {
#endif

void menu(long param_1, int param_2);
void menu_bios_warning(long param_1);
void select_exit_current_menu(long *param_1, long param_2);
void select_load_game(long *param_1);
void select_save_state(long *param_1);
void select_quit(undefined8 *param_1);
int action_select_menu(long param_1, long param_2, int *param_3);
void destroy_select_menu(undefined8 param_1, long param_2);
void focus_savestate(void);
void modify_snapshot_bg(void);
void draw_menu_main(void);

#ifdef __cplusplus
}
#endif

#endif // MENU_H
