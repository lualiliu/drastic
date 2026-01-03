// cpu.h - CPU管理
#ifndef CPU_H
#define CPU_H

#include "drastic_val.h"

#ifdef __cplusplus
extern "C" {
#endif

void reset_cpu(long param_1);
void initialize_cpu(long *param_1, long param_2, int param_3, long param_4);
void set_debug_mode(long param_1, undefined1 param_2);

#ifdef __cplusplus
}
#endif

#endif // CPU_H
