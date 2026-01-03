// rtc.h - 实时时钟
#ifndef RTC_H
#define RTC_H

#include "drastic_val.h"

#ifdef __cplusplus
extern "C" {
#endif

void reset_rtc(long param_1, int param_2, time_t param_3);
void initialize_rtc(undefined8 *param_1, undefined8 param_2);
void get_ticks_us(long *param_1);
void delay_us(ulong param_1);

#ifdef __cplusplus
}
#endif

#endif // RTC_H
