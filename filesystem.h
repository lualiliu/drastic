// filesystem.h - 文件系统
#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "drastic_val.h"

#ifdef __cplusplus
extern "C" {
#endif

long *nds_file_open(char *param_1, long param_2, int param_3, int param_4);
void nds_file_close(int *param_1);
int load_file(long *param_1, long *param_2, char *param_3);

#ifdef __cplusplus
}
#endif

#endif // FILESYSTEM_H
