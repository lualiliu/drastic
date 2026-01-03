// system.h - 系统初始化和重置
#ifndef SYSTEM_H
#define SYSTEM_H

#include "drastic_val.h"

#ifdef __cplusplus
extern "C" {
#endif

void initialize_system(long param_1);
void reset_system(undefined8 *param_1);
void initialize_system_directories(undefined8 param_1);
void quit(long param_1);
void platform_initialize();

#ifdef __cplusplus
}
#endif

#endif // SYSTEM_H
