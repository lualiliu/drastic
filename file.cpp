// file.cpp - 文件操作模块
// 注意：先包含标准库，再包含自定义头文件，避免类型冲突
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "drastic_modules.h"

// 声明缺失的符号
extern undefined __stack_chk_guard;
extern void __stack_chk_fail();

// --- 函数: load_nds ---
undefined4 load_nds(long param_1,char *param_2)
{
  long lVar1;
  undefined1 *puVar2;
  int iVar3;
  ::FILE *__s;
  size_t sVar4;
  long lVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 uVar8;
  long lVar9;
  undefined *puVar10;
  char acStack_c48 [1056];
  undefined1 auStack_828 [2080];
  long local_8;
  
  lVar9 = *(long *)(param_1 + 0x918);
  local_8 = (long)__stack_chk_guard;
  lVar1 = lVar9 + 0x8a780;
  snprintf((char*)auStack_828,0x820,"%s%cunzip_cache",(char*)lVar1,0x2f);
  puVar2 = auStack_828;
  if (*(int *)(lVar9 + 0x85a24) == 0) {
    puVar2 = (undefined1 *)0x0;
  }
  if (*(long *)(param_1 + 0x920) == 0) {
LAB_0016fe48:
    lVar5 = (long)nds_file_open(param_2,(long)puVar2,*(int *)(lVar9 + 0x85a3c),
                          *(int *)(lVar9 + 0x85a28));
  }
  else {
    if (*(int *)(param_1 + 0x2d84) == 0) {
      iVar3 = *(int *)(param_1 + 0x8dc);
    }
    else {
      backup_save(param_1 + 0x968);
      iVar3 = *(int *)(param_1 + 0x8dc);
    }
    if (((iVar3 != 0) && (*(char *)(param_1 + 0x8e3) != '\0')) && (*(long *)(param_1 + 0x8c8) != 0))
    {
      __s = ::fopen((char *)(param_1 + 0x4a0),"wb");
      if (__s == (::FILE *)0x0) {
        printf("ERROR: Couldn\'t save GBA backup %s\n",(char *)(param_1 + 0x4a0));
      }
      else {
        puts("Saving GBA backup file.");
        sVar4 = fwrite(*(void **)(param_1 + 0x8c8),(ulong)*(uint *)(param_1 + 0x8d4),1,__s);
        if (sVar4 != 1) {
          puts("ERROR: Couldn\'t write all of GBA backup.");
        }
        fclose(__s);
      }
    }
    free(*(void **)(param_1 + 0x2d90));
    *(undefined8 *)(param_1 + 0x2d90) = 0;
    nds_file_close(*(undefined8 *)(param_1 + 0x920));
    *(undefined8 *)(param_1 + 0x920) = 0;
    if (*(int *)(param_1 + 0x93c) < 0) goto LAB_0016fe48;
    close(*(int *)(param_1 + 0x93c));
    lVar5 = (long)nds_file_open(param_2,(long)puVar2,*(int *)(lVar9 + 0x85a3c),
                          *(int *)(lVar9 + 0x85a28));
  }
  if ((lVar5 == 0) &&
     ((*(int *)(lVar9 + 0x85a24) != 0 ||
      (lVar5 = (long)nds_file_open(param_2,(long)auStack_828,*(int *)(lVar9 + 0x85a3c),
                             *(int *)(lVar9 + 0x85a28)), lVar5 == 0)))) {
    uVar8 = 0xffffffff;
    printf("ERROR: Could not open %s\n",param_2);
    goto LAB_0016ff3c;
  }
  *(long *)(param_1 + 0x920) = lVar5;
  if (*(uint *)(lVar5 + 0x10) < 0x200) {
    uVar8 = 0xffffffff;
    printf("%s does not have a valid gamecard_header.\n",param_2);
    goto LAB_0016ff3c;
  }
  pcVar6 = strrchr(param_2,0x2f);
  pcVar7 = param_2;
  if (pcVar6 != (char *)0x0) {
    pcVar7 = pcVar6 + 1;
  }
  pcVar7 = strncpy(acStack_c48,pcVar7,0x400);
  pcVar7 = strrchr(pcVar7,0x2e);
  if (pcVar7 != (char *)0x0) {
    *pcVar7 = '\0';
  }
  strncpy((char *)(lVar9 + 0x8a380),param_2,0x400);
  *(undefined1 *)(lVar9 + 0x8a77f) = 0;
  pcVar6 = strrchr(param_2,0x2f);
  pcVar7 = (char *)(lVar9 + 0x8b380);
  if (pcVar6 != (char *)0x0) {
    param_2 = pcVar6 + 1;
  }
  strncpy(pcVar7,param_2,0x400);
  *(undefined1 *)(lVar9 + 0x8b77f) = 0;
  memcpy((void *)(lVar9 + 0x8af80),pcVar7,0x400);
  pcVar6 = strrchr(pcVar7,0x2e);
  if (pcVar6 != (char *)0x0) {
    *pcVar6 = '\0';
  }
  pcVar6 = getcwd((char *)(lVar9 + 0x855e4),0x400);
  if (pcVar6 == (char *)0x0) {
    uVar8 = 0xffffffff;
    goto LAB_0016ff3c;
  }
  if (*(int *)(lVar9 + 0x85a50) == 0) {
LAB_0016ff38:
    uVar8 = 0;
  }
  else {
    // Lua脚本加载代码已注释
  }
LAB_0016ff3c:
  if (local_8 != (long)__stack_chk_guard) {
    __stack_chk_fail();
  }
  return uVar8;
}
