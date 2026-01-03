// audio.h - 音频系统
#ifndef AUDIO_H
#define AUDIO_H

#include "drastic_val.h"

#ifdef __cplusplus
extern "C" {
#endif

void reset_spu(long param_1);
void initialize_spu(long param_1, long param_2);
void audio_reset_buffer(void *param_1);
char audio_pause(long param_1);
void audio_revert_pause_state(undefined8 param_1, int param_2);
undefined8 initialize_audio(long param_1);
void audio_callback(ulong param_1, void *param_2, int param_3);

#ifdef __cplusplus
}
#endif

#endif // AUDIO_H
