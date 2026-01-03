// input.h - 输入处理
#ifndef INPUT_H
#define INPUT_H

#include "drastic_val.h"

#ifdef __cplusplus
extern "C" {
#endif

void reset_input(long param_1);
void initialize_input(long param_1, undefined8 param_2);
uint get_gui_input(long param_1, uint *param_2);
void input_log_record(long param_1, const char *param_2);
void input_log_playback(void *param_1, const char *param_2);
uint platform_get_config_input(void);
void platform_set_default_controls(undefined8 *param_1, undefined8 *param_2);

#ifdef __cplusplus
}
#endif

#endif // INPUT_H
