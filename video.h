// video.h - 视频和屏幕管理
#ifndef VIDEO_H
#define VIDEO_H

#include "drastic_val.h"

#ifdef __cplusplus
extern "C" {
#endif

void initialize_screen(uint param_1);
void set_screen_menu_off(void);
void set_screen_menu_on(void);
void clear_screen(void);
void set_screen_hires_mode(uint param_1, uint param_2);
void update_screens(void);
void reset_video(long *param_1);
void initialize_video(long param_1, long param_2); // 注意：参数类型与drastic_functions.h中的声明一致
void screen_copy16(ushort *param_1, undefined4 param_2);
void update_screen_menu(void);
void clear_screen_menu(undefined2 param_1);
void blit_screen_menu(long param_1, ulong param_2, int param_3, uint param_4, int param_5);
void set_font_narrow_small(void);
void set_font_narrow(void);
void set_font_wide(void);
void draw_menu_bg(undefined8 *param_1);
void print_string(undefined8 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5);
void load_logo(long *param_1);

#ifdef __cplusplus
}
#endif

#endif // VIDEO_H
