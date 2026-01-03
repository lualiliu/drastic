// events.h - 事件系统
#ifndef EVENTS_H
#define EVENTS_H

#include "drastic_val.h"

#ifdef __cplusplus
extern "C" {
#endif

void reset_event_list(long param_1);
void initialize_event_list(long param_1, long param_2);
void execute_events(long param_1);
void event_force_task_switch_function(long param_1);
void event_scanline_start_function(long *param_1);
void event_hblank_start_function(long param_1);
void event_gamecard_irq_function(undefined8 param_1, long param_2);
void event_timer_overflow_function(long param_1, long *param_2);
// void event_dma_complete_function(long param_1); // 已在drastic_val.h中声明
void execute_arm_raise_interrupt(long param_1);
void cpu_next_action_arm7_to_event_update(long param_1);

#ifdef __cplusplus
}
#endif

#endif // EVENTS_H
