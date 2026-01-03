#ifndef DRASTIC_MODULES_H
#define DRASTIC_MODULES_H

// 模块化头文件 - 统一管理所有模块的声明
// 避免重复定义和编译错误

#include "drastic_val.h"

#ifdef __cplusplus
extern "C" {
#endif

// ========================================================================
// 系统模块 (system.cpp)
// ========================================================================
void initialize_system(long param_1);
void reset_system(undefined8 *param_1);
void process_arguments(long param_1, undefined4 param_2, char** param_3);
void quit(long param_1);
void platform_initialize(void);

// ========================================================================
// 文件模块 (file.cpp)
// ========================================================================
undefined4 load_nds(long param_1, char *param_2);
long *nds_file_open(char *param_1, long param_2, int param_3, int param_4);
void nds_file_close(int *param_1);
void backup_save(long param_1);

// ========================================================================
// 屏幕模块 (screen.cpp)
// ========================================================================
void initialize_screen(uint param_1);
void set_screen_menu_off(void);
void set_screen_menu_on(void);
void clear_screen(void);
void set_screen_hires_mode(uint param_1, uint param_2);
void set_screen_orientation(uint param_1);
void set_screen_swap(uint param_1);
void update_screens(void);

// ========================================================================
// CPU模块 (cpu_module.cpp)
// ========================================================================
void cpu_next_action_arm7_to_event_update(long param_1);
void recompiler_entry(long param_1, undefined8 param_2);
void reset_cpu(long param_1);
void reset_cpu_block(long param_1);
long cpu_block_lookup_base(long param_1, ulong param_2);
void execute_arm_raise_interrupt(long param_1);

// ========================================================================
// 视频模块 (video.cpp)
// ========================================================================
void initialize_video(long param_1, long param_2);
void reset_video(long *param_1);
void event_scanline_start_function(long *param_1);
void event_hblank_start_function(long param_1);

// ========================================================================
// 音频模块 (audio.cpp)
// ========================================================================
undefined8 initialize_audio(long param_1);
void initialize_spu(long param_1, long param_2);
void reset_spu(long param_1);
void audio_reset_buffer(void *param_1);
char audio_pause(long param_1);

// ========================================================================
// 输入模块 (input.cpp)
// ========================================================================
void initialize_input(long param_1, undefined8 param_2);
void reset_input(long param_1);
void input_log_record(long param_1, char *param_2);
void input_log_playback(void *param_1, char *param_2);

// ========================================================================
// 菜单模块 (menu.cpp)
// ========================================================================
void menu(long param_1, int param_2);
void draw_menu_main(void);
void select_exit_current_menu(long *param_1, long param_2);
void clear_screen_menu(undefined2 param_1);
void load_logo(long *param_1);
undefined8 *create_menu_main(long param_1);

// ========================================================================
// 配置模块 (config.cpp)
// ========================================================================
undefined8 load_config_file(long param_1, undefined8 param_2, undefined4 param_3);
undefined8 load_directory_config_file(long param_1, undefined8 param_2);
void config_default(undefined4 *param_1);
void config_update_settings(long param_1);
void chomp_whitespace(char *param_1);

// ========================================================================
// 内存模块 (memory.cpp)
// ========================================================================
void initialize_memory(long *param_1, long param_2);
void reset_memory(long *param_1);
int initialize_translation_cache(void* param_1);
void reset_translation_cache(long param_1);

// ========================================================================
// 游戏卡模块 (gamecard.cpp)
// ========================================================================
void initialize_gamecard(long param_1, long param_2);
void reset_gamecard(long param_1);
undefined8 gamecard_load_program(long param_1);
void event_gamecard_irq_function(undefined8 param_1, long param_2);

// ========================================================================
// 事件模块 (event.cpp)
// ========================================================================
void initialize_event_list(long param_1, long param_2);
void reset_event_list(long param_1);
void execute_events(long param_1);
void event_force_task_switch_function(long param_1);

// ========================================================================
// 其他模块
// ========================================================================
void initialize_system_directories(undefined8 param_1);
void initialize_spi_peripherals(long param_1, long param_2);
void reset_spi_peripherals(long param_1);
void initialize_rtc(undefined8 param_1, undefined8 param_2);
void reset_rtc(long param_1, int param_2, time_t param_3);
void initialize_cpu(long *param_1, long param_2, int param_3, long param_4);
void apply_cycle_adjustment_hacks(long param_1);
void reset_backup(long param_1);
void get_ticks_us(long *param_1);
void set_debug_mode(long param_1, undefined1 param_2);
void menu_bios_warning(long param_1);
void screen_copy16(ushort *param_1, undefined4 param_2);
void set_font_narrow(void);
void set_font_narrow_small(void);

// Lua相关
undefined8 initialize_lua(long param_1);
undefined4 lua_load_script(long param_1);
void lua_on_load_game(undefined8 param_1);

#ifdef __cplusplus
}
#endif

#endif // DRASTIC_MODULES_H
