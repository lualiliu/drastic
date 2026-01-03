// memory.h - 内存管理
#ifndef MEMORY_H
#define MEMORY_H

#include "drastic_val.h"

#ifdef __cplusplus
extern "C" {
#endif

void reset_memory(long *param_1);
void initialize_memory(long *param_1, long param_2);
void reset_translation_cache(long param_1);
int initialize_translation_cache(void *param_1);
void reset_cpu_block(long param_1);
long cpu_block_lookup_base(long param_1, ulong param_2);
void apply_cycle_adjustment_hacks(long param_1);

#ifdef __cplusplus
}
#endif

#endif // MEMORY_H
