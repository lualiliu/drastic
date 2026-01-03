// config.h - 配置管理
#ifndef CONFIG_H
#define CONFIG_H

#include "drastic_val.h"

#ifdef __cplusplus
extern "C" {
#endif

undefined8 load_config_file(long param_1, undefined8 param_2, undefined4 param_3);
void config_default(undefined4 *param_1);
void config_update_settings(long param_1);
void chomp_whitespace(char *param_1);
undefined8 load_directory_config_file(long param_1, undefined8 param_2);

#ifdef __cplusplus
}
#endif

#endif // CONFIG_H
