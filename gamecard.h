// gamecard.h - 游戏卡管理
#ifndef GAMECARD_H
#define GAMECARD_H

#include "drastic_val.h"

#ifdef __cplusplus
extern "C" {
#endif

void reset_gamecard(long param_1);
void initialize_gamecard(long param_1, long param_2);
undefined8 gamecard_load_program(long param_1);
void reset_backup(long param_1);
undefined4 load_nds(long param_1, char *param_2);
void backup_save(long param_1);

#ifdef __cplusplus
}
#endif

#endif // GAMECARD_H
