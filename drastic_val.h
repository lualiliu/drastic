// drastic_globals.h
#ifndef DRASTIC_GLOBALS_H
#define DRASTIC_GLOBALS_H

//#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif
typedef unsigned char   undefined;
typedef void (*code)(void);  // 函数指针类型（无参数）
typedef void (*code1)(long);  // 函数指针类型（1个参数）
typedef void (*code2)(long, ulong);  // 函数指针类型（2个参数）
typedef int (*code3)(long, long, long);  // 函数指针类型（2个参数）
// CONCAT 宏定义（用于字符/值连接，反编译代码中的特殊操作）
// 这些宏是嵌套调用的，每个宏接受2个参数，其中第二个参数可能是另一个CONCAT调用
#define CONCAT11(a, b) ((char)((a) | (b)))
#define CONCAT12(a, b) CONCAT11(a, b)
#define CONCAT13(a, b) CONCAT11(a, b)
#define CONCAT14(a, b) CONCAT11(a, b)
#define CONCAT15(a, b) CONCAT11(a, b)
#define CONCAT16(a, b) CONCAT11(a, b)
#define CONCAT17(a, b) CONCAT11(a, b)


#define CONCAT22(a, b) ((short)((a) | (b)))  // 用于 short 类型
#define CONCAT24(a, b) ((short)((a) | (b)))  // 用于 short 类型
#define CONCAT26(a, b) ((short)((a) | (b)))  // 用于 short 类型


#define CONCAT44(a, b) ((int)((a) | (b)))  // 用于 int 类型

//typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned char    dwfenc;
typedef unsigned int    dword;
typedef long long    longlong;
typedef unsigned long    qword;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned long    undefined8;
typedef unsigned short    ushort;
//typedef int    wchar_t;
typedef unsigned short    word;


//Sundefined1 nds_system[62042112];

typedef struct RangeCoder RangeCoder, *PRangeCoder;

struct RangeCoder { // PlaceHolder Class Structure
};

// typedef pointer pointer __((offset(0x10))); // 已移除，pointer类型未定义且语法错误
typedef void* pointer; // 定义pointer为void*

typedef unsigned int    wchar32;
typedef struct PPM_CONTEXT PPM_CONTEXT, *PPPM_CONTEXT;

struct PPM_CONTEXT { // PlaceHolder Class Structure
};

typedef struct Blake2ThreadData Blake2ThreadData, *PBlake2ThreadData;

struct Blake2ThreadData { // PlaceHolder Class Structure
};

typedef struct MainHeader MainHeader, *PMainHeader;

struct MainHeader { // PlaceHolder Class Structure
};

typedef struct eh_frame_hdr eh_frame_hdr, *Peh_frame_hdr;

struct eh_frame_hdr {
byte eh_frame_hdr_version; // Exception Handler Frame Header Version
    dwfenc eh_frame_pointer_encoding; // Exception Handler Frame Pointer Encoding
    dwfenc eh_frame_desc_entry_count_encoding; // Encoding of # of Exception Handler FDEs
    dwfenc eh_frame_table_encoding; // Exception Handler Table Encoding
};

typedef struct fde_table_entry fde_table_entry, *Pfde_table_entry;

struct fde_table_entry {
dword initial_loc; // Initial Location
dword data_loc; // Data location
};

typedef void _IO_lock_t;

typedef struct _IO_marker _IO_marker, *P_IO_marker;

typedef struct _IO_FILE _IO_FILE, *P_IO_FILE;

typedef long __off_t;

typedef long __off64_t;

typedef ulong size_t;

#ifndef _IO_FILE_DEFINED
#ifdef __GLIBC__
// 系统已经定义了 _IO_FILE，跳过
#else
#define _IO_FILE_DEFINED
struct _IO_FILE {
int _flags;
    char *_IO_read_ptr;
    char *_IO_read_end;
    char *_IO_read_base;
    char *_IO_write_base;
    char *_IO_write_ptr;
    char *_IO_write_end;
    char *_IO_buf_base;
    char *_IO_buf_end;
    char *_IO_save_base;
    char *_IO_backup_base;
    char *_IO_save_end;
    struct _IO_marker *_markers;
    struct _IO_FILE *_chain;
int _fileno;
int _flags2;
    __off_t _old_offset;
ushort _cur_column;
char _vtable_offset;
    char _shortbuf[1];
    _IO_lock_t *_lock;
    __off64_t _offset;
    void *__pad1;
    void *__pad2;
    void *__pad3;
    void *__pad4;
    size_t __pad5;
int _mode;
    char _unused2[20];
};
#endif // __GLIBC__
#endif // _IO_FILE_DEFINED

#ifndef _IO_MARKER_DEFINED
#define _IO_MARKER_DEFINED
struct _IO_marker {
    struct _IO_marker *_next;
    struct _IO_FILE *_sbuf;
int _pos;
};
#endif

undefined1 nds_system[62042112];

#ifndef _STAT64_DEFINED
#ifdef __GLIBC__
// 系统已经定义了 stat64，跳过
// typedef struct stat64 stat64, *Pstat64; // 注释掉，避免与系统函数冲突
#else
#define _STAT64_DEFINED

typedef ulong __dev_t;

typedef ulong __ino64_t;

typedef ulong __nlink_t;

typedef uint __mode_t;

typedef uint __uid_t;

typedef uint __gid_t;

typedef long __blksize_t;

typedef long __blkcnt64_t;

typedef long __time_t;

#ifdef __GLIBC__
// 系统已经定义了 timespec，跳过
typedef struct timespec timespec, *Ptimespec;
#else
#ifndef _TIMESPEC_DEFINED
#define _TIMESPEC_DEFINED
typedef struct timespec timespec, *Ptimespec;
struct timespec {
    __time_t tv_sec;
long tv_nsec;
};
#else
typedef struct timespec timespec, *Ptimespec;
#endif
#endif // __GLIBC__

typedef struct stat64 stat64, *Pstat64;
struct stat64 {
    __dev_t st_dev;
    __ino64_t st_ino;
    __nlink_t st_nlink;
    __mode_t st_mode;
    __uid_t st_uid;
    __gid_t st_gid;
int __pad0;
    __dev_t st_rdev;
    __off_t st_size;
    __blksize_t st_blksize;
    __blkcnt64_t st_blocks;
    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
    long __unused[3];
};
#endif // __GLIBC__
#endif // _STAT64_DEFINED

#ifndef _STAT_DEFINED
#ifdef __GLIBC__
// 系统已经定义了 stat，跳过
// typedef struct stat stat, *Pstat; // 注释掉，避免与系统函数冲突
#else
#define _STAT_DEFINED

typedef ulong __ino_t;

typedef long __blkcnt_t;

typedef struct stat stat, *Pstat;

struct stat {
    __dev_t st_dev;
    __ino_t st_ino;
    __nlink_t st_nlink;
    __mode_t st_mode;
    __uid_t st_uid;
    __gid_t st_gid;
int __pad0;
    __dev_t st_rdev;
    __off_t st_size;
    __blksize_t st_blksize;
    __blkcnt_t st_blocks;
    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
    long __unused[3];
};
#endif // __GLIBC__
#endif // _STAT_DEFINED

typedef struct statvfs64 statvfs64, *Pstatvfs64;

typedef ulong __fsblkcnt64_t;

typedef ulong __fsfilcnt64_t;

struct statvfs64 {
    ulong f_bsize;
    ulong f_frsize;
    __fsblkcnt64_t f_blocks;
    __fsblkcnt64_t f_bfree;
    __fsblkcnt64_t f_bavail;
    __fsfilcnt64_t f_files;
    __fsfilcnt64_t f_ffree;
    __fsfilcnt64_t f_favail;
    ulong f_fsid;
    ulong f_flag;
    ulong f_namemax;
    int __f_spare[6];
};

typedef long __jmp_buf[8];

typedef struct _IO_FILE FILE;

typedef int __pid_t;

typedef __mode_t mode_t;

typedef long __ssize_t;

typedef long __suseconds_t;

typedef long __clock_t;

typedef int __int32_t;

typedef __ssize_t ssize_t;

typedef struct passwd passwd, *Ppasswd;

struct passwd {
    char *pw_name;
    char *pw_passwd;
    __uid_t pw_uid;
    __gid_t pw_gid;
    char *pw_gecos;
    char *pw_dir;
    char *pw_shell;
};

typedef struct evp_pkey_ctx_st evp_pkey_ctx_st, *Pevp_pkey_ctx_st;

typedef struct evp_pkey_ctx_st EVP_PKEY_CTX;

struct evp_pkey_ctx_st {
};

typedef struct ui_st ui_st, *Pui_st;

struct ui_st {
};

typedef struct ui_st UI;

#ifndef _PTHREAD_TYPES_DEFINED
#ifdef __GLIBC__
// 系统已经定义了 pthread 类型，跳过
typedef pthread_mutex_t pthread_mutex_t, *Ppthread_mutex_t;
#else
#define _PTHREAD_TYPES_DEFINED

typedef struct __pthread_internal_list __pthread_internal_list, *P__pthread_internal_list;

typedef struct __pthread_internal_list __pthread_list_t;

struct __pthread_internal_list {
    struct __pthread_internal_list *__prev;
    struct __pthread_internal_list *__next;
};

typedef struct __pthread_mutex_s __pthread_mutex_s, *P__pthread_mutex_s;

struct __pthread_mutex_s {
int __lock;
    uint __count;
int __owner;
    uint __nusers;
int __kind;
int __spins;
    __pthread_list_t __list;
};

#ifndef pthread_mutex_t
typedef union pthread_mutex_t pthread_mutex_t, *Ppthread_mutex_t;
union pthread_mutex_t {
    struct __pthread_mutex_s __data;
char __size[40];
long __align;
};
#else
typedef pthread_mutex_t pthread_mutex_t, *Ppthread_mutex_t;
#endif

typedef union pthread_mutexattr_t pthread_mutexattr_t, *Ppthread_mutexattr_t;

union pthread_mutexattr_t {
};

typedef union pthread_cond_t pthread_cond_t, *Ppthread_cond_t;

typedef struct _struct_16 _struct_16, *P_struct_16;

struct _struct_16 {
int __lock;
    uint __futex;
    ulonglong __total_seq;
    ulonglong __wakeup_seq;
    ulonglong __woken_seq;
    void *__mutex;
    uint __nwaiters;
    uint __broadcast_seq;
};

union pthread_cond_t {
    struct _struct_16 __data;
    longlong __align;
};

typedef ulong pthread_t;

typedef union pthread_attr_t pthread_attr_t, *Ppthread_attr_t;

union pthread_attr_t {
};

typedef union pthread_condattr_t pthread_condattr_t, *Ppthread_condattr_t;

union pthread_condattr_t {
};
#endif // __GLIBC__
#endif // _PTHREAD_TYPES_DEFINED

#ifdef __GLIBC__
// 系统已经定义了 dirent 和 dirent64，跳过
typedef struct dirent dirent, *Pdirent;
typedef struct dirent64 dirent64, *Pdirent64;
#else
#ifndef _DIRENT_DEFINED
#define _DIRENT_DEFINED
typedef struct dirent dirent, *Pdirent;

struct dirent {
    __ino_t d_ino;
    __off_t d_off;
ushort d_reclen;
    uchar d_type;
    char d_name[256];
};
#endif // _DIRENT_DEFINED

#ifndef _DIRENT64_DEFINED
#define _DIRENT64_DEFINED
typedef struct dirent64 dirent64, *Pdirent64;

struct dirent64 {
    __ino64_t d_ino;
    __off64_t d_off;
ushort d_reclen;
    uchar d_type;
    char d_name[256];
};
#endif // _DIRENT64_DEFINED
#endif // __GLIBC__

typedef struct __dirstream __dirstream, *P__dirstream;

typedef struct __dirstream DIR;

struct __dirstream {
};

typedef struct utimbuf utimbuf, *Putimbuf;

struct utimbuf {
    __time_t actime;
    __time_t modtime;
};

typedef struct lconv lconv, *Plconv;

struct lconv {
    char *decimal_point;
    char *thousands_sep;
    char *grouping;
    char *int_curr_symbol;
    char *currency_symbol;
    char *mon_decimal_point;
    char *mon_thousands_sep;
    char *mon_grouping;
    char *positive_sign;
    char *negative_sign;
char int_frac_digits;
char frac_digits;
char p_cs_precedes;
char p_sep_by_space;
char n_cs_precedes;
char n_sep_by_space;
char p_sign_posn;
char n_sign_posn;
char int_p_cs_precedes;
char int_p_sep_by_space;
char int_n_cs_precedes;
char int_n_sep_by_space;
char int_p_sign_posn;
char int_n_sign_posn;
};

// timezone 在系统头文件中是变量，不能定义同名结构体
// 使用条件编译避免冲突
#ifndef _TIMEZONE_STRUCT_DEFINED
#define _TIMEZONE_STRUCT_DEFINED
// 注意：如果系统头文件已经声明了 timezone 变量，这个定义会冲突
// 但为了保持代码兼容性，我们使用不同的名称空间
#ifdef __GLIBC__
// 在 glibc 中，timezone 是变量，我们需要使用不同的方法
// 暂时注释掉，如果需要使用，应该重命名
// typedef struct timezone timezone, *Ptimezone; // 注释掉，避免冲突
#else
typedef struct timezone timezone, *Ptimezone;

struct timezone {
int tz_minuteswest;
int tz_dsttime;
};
#endif // __GLIBC__
#endif // _TIMEZONE_STRUCT_DEFINED

typedef __time_t time_t;

#ifdef __GLIBC__
// 系统已经定义了 timeval，跳过
typedef struct timeval timeval, *Ptimeval;
#else
typedef struct timeval timeval, *Ptimeval;

struct timeval {
    __time_t tv_sec;
    __suseconds_t tv_usec;
};
#endif // __GLIBC__

typedef struct timezone *__timezone_ptr_t;

#ifdef __GLIBC__
// 系统已经定义了 tm，跳过
typedef struct tm tm, *Ptm;
#else
typedef struct tm tm, *Ptm;

struct tm {
int tm_sec;
int tm_min;
int tm_hour;
int tm_mday;
int tm_mon;
int tm_year;
int tm_wday;
int tm_yday;
int tm_isdst;
long tm_gmtoff;
    char *tm_zone;
};
#endif // __GLIBC__

typedef __clock_t clock_t;

#ifdef __GLIBC__
// 系统已经定义了 __jmp_buf_tag 和 __sigset_t，跳过
// 只声明类型别名，不重新定义
typedef struct __jmp_buf_tag __jmp_buf_tag, *P__jmp_buf_tag;
// typedef struct __sigset_t __sigset_t, *P__sigset_t; // 系统已定义，注释掉
#else
typedef struct __jmp_buf_tag __jmp_buf_tag, *P__jmp_buf_tag;

typedef struct __sigset_t __sigset_t, *P__sigset_t;

struct __sigset_t {
    ulong __val[16];
};

struct __jmp_buf_tag {
    __jmp_buf __jmpbuf;
int __mask_was_saved;
    struct __sigset_t __saved_mask;
};
#endif // __GLIBC__

#ifndef _GETOPT_H
struct option {
    const char *name;
    int has_arg;
    int *flag;
    int val;
};
#endif // _GETOPT_H


typedef uint wint_t;

typedef void (*__sighandler_t)(int);

typedef struct ui_string_st ui_string_st, *Pui_string_st;

struct ui_string_st {
};

typedef struct ui_string_st UI_STRING;

typedef undefined SCAN_DIRS;

typedef struct FindData FindData, *PFindData;

struct FindData { // PlaceHolder Structure
};

typedef struct DecodeTable DecodeTable, *PDecodeTable;

struct DecodeTable { // PlaceHolder Structure
};

typedef struct Archive Archive, *PArchive;

struct Archive { // PlaceHolder Structure
};

typedef undefined RAR_EXIT;

typedef struct DataSet DataSet, *PDataSet;

struct DataSet { // PlaceHolder Structure
};

typedef undefined HEADER_TYPE;

typedef struct ThreadPool ThreadPool, *PThreadPool;

struct ThreadPool { // PlaceHolder Structure
};

typedef struct SubAllocator SubAllocator, *PSubAllocator;

struct SubAllocator { // PlaceHolder Structure
};

typedef struct blake2s_state blake2s_state, *Pblake2s_state;

struct blake2s_state { // PlaceHolder Structure
};

typedef struct UnpackThreadData UnpackThreadData, *PUnpackThreadData;

struct UnpackThreadData { // PlaceHolder Structure
};

typedef struct CommandData CommandData, *PCommandData;

struct CommandData { // PlaceHolder Structure
};

typedef struct SecPassword SecPassword, *PSecPassword;

struct SecPassword { // PlaceHolder Structure
};

typedef struct RarLocalTime RarLocalTime, *PRarLocalTime;

struct RarLocalTime { // PlaceHolder Structure
};

typedef struct Unpack Unpack, *PUnpack;

struct Unpack { // PlaceHolder Structure
};

typedef struct VM_PreparedCommand VM_PreparedCommand, *PVM_PreparedCommand;

struct VM_PreparedCommand { // PlaceHolder Structure
};

typedef struct ScanTree ScanTree, *PScanTree;

struct ScanTree { // PlaceHolder Structure
};

typedef struct FragmentedWindow FragmentedWindow, *PFragmentedWindow;

struct FragmentedWindow { // PlaceHolder Structure
};

typedef struct ComprDataIO ComprDataIO, *PComprDataIO;

struct ComprDataIO { // PlaceHolder Structure
};

typedef struct RawRead RawRead, *PRawRead;

struct RawRead { // PlaceHolder Structure
};

typedef struct UnpackBlockHeader UnpackBlockHeader, *PUnpackBlockHeader;

struct UnpackBlockHeader { // PlaceHolder Structure
};

typedef struct HashValue HashValue, *PHashValue;

struct HashValue { // PlaceHolder Structure
};

typedef struct RarVM RarVM, *PRarVM;

struct RarVM { // PlaceHolder Structure
};

typedef struct QuickOpen QuickOpen, *PQuickOpen;

struct QuickOpen { // PlaceHolder Structure
};

typedef struct ModelPPM ModelPPM, *PModelPPM;

struct ModelPPM { // PlaceHolder Structure
};

typedef struct sha256_context sha256_context, *Psha256_context;

struct sha256_context { // PlaceHolder Structure
};

typedef struct unsigned_char unsigned_char, *Punsigned_char;

struct unsigned_char { // PlaceHolder Structure
};

typedef struct BitInput BitInput, *PBitInput;

struct BitInput { // PlaceHolder Structure
};

typedef struct blake2sp_state blake2sp_state, *Pblake2sp_state;

struct blake2sp_state { // PlaceHolder Structure
};

typedef struct StringList StringList, *PStringList;

struct StringList { // PlaceHolder Structure
};

typedef struct UnpackFilter UnpackFilter, *PUnpackFilter;

struct UnpackFilter { // PlaceHolder Structure
};

typedef struct BaseBlock BaseBlock, *PBaseBlock;

struct BaseBlock { // PlaceHolder Structure
};

typedef undefined VM_StandardFilters;

typedef struct UnpackBlockTables UnpackBlockTables, *PUnpackBlockTables;

struct UnpackBlockTables { // PlaceHolder Structure
};

typedef struct RarTime RarTime, *PRarTime;

struct RarTime { // PlaceHolder Structure
};

typedef struct Array Array, *PArray;

struct Array { // PlaceHolder Structure
};

typedef undefined RARFORMAT;

typedef struct hash_context hash_context, *Phash_context;

struct hash_context { // PlaceHolder Structure
};

typedef undefined HASH_TYPE;

typedef struct STATE STATE, *PSTATE;

struct STATE { // PlaceHolder Structure
};

typedef struct DataHash DataHash, *PDataHash;

struct DataHash { // PlaceHolder Structure
};

typedef struct Rijndael Rijndael, *PRijndael;

struct Rijndael { // PlaceHolder Structure
};

typedef struct RAROptions RAROptions, *PRAROptions;

struct RAROptions { // PlaceHolder Structure
};

typedef undefined RECURSE_MODE;

typedef undefined OVERWRITE_MODE;

typedef struct ErrorHandler ErrorHandler, *PErrorHandler;

struct ErrorHandler { // PlaceHolder Structure
};

typedef undefined CRYPT_METHOD;

typedef undefined MESSAGE_TYPE;

typedef struct FindFile FindFile, *PFindFile;

struct FindFile { // PlaceHolder Structure
};

typedef struct FileHeader FileHeader, *PFileHeader;

struct FileHeader { // PlaceHolder Structure
};

typedef undefined PASSWORD_TYPE;

typedef struct CryptData CryptData, *PCryptData;

struct CryptData { // PlaceHolder Structure
};

typedef struct CmdExtract CmdExtract, *PCmdExtract;

struct CmdExtract { // PlaceHolder Structure
};

typedef struct File File, *PFile;

struct File { // PlaceHolder Structure
};

typedef undefined RAR_CHARSET;

typedef struct VM_PreparedProgram VM_PreparedProgram, *PVM_PreparedProgram;

struct VM_PreparedProgram { // PlaceHolder Structure
};

typedef struct EncodeFileName EncodeFileName, *PEncodeFileName;

struct EncodeFileName { // PlaceHolder Structure
};

typedef struct bad_alloc bad_alloc, *Pbad_alloc;

struct bad_alloc { // PlaceHolder Structure
};

typedef struct QueueEntry QueueEntry, *PQueueEntry;

struct QueueEntry { // PlaceHolder Structure
};

#ifdef __GLIBC__
// 系统已经定义了 __compar_fn_t，跳过
// typedef int (*__compar_fn_t)(void *, void *); // 注释掉，避免冲突
#else
typedef int (*__compar_fn_t)(void *, void *);
#endif // __GLIBC__

typedef struct Elf64_Phdr Elf64_Phdr, *PElf64_Phdr;

typedef enum Elf_ProgramHeaderType_AARCH64 {
    PT_NULL=0,
    PT_LOAD=1,
    PT_DYNAMIC=2,
    PT_INTERP=3,
    PT_NOTE=4,
    PT_SHLIB=5,
    PT_PHDR=6,
    PT_TLS=7,
    PT_GNU_EH_FRAME=1685382480,
    PT_GNU_STACK=1685382481,
    PT_GNU_RELRO=1685382482,
    PT_AARCH64_ARCHEXT=1879048192
} Elf_ProgramHeaderType_AARCH64;

struct Elf64_Phdr {
    enum Elf_ProgramHeaderType_AARCH64 p_type;
dword p_flags;
qword p_offset;
qword p_vaddr;
qword p_paddr;
qword p_filesz;
qword p_memsz;
qword p_align;
};

typedef struct Elf64_Rela Elf64_Rela, *PElf64_Rela;

struct Elf64_Rela {
qword r_offset; // location to apply the relocation action
qword r_info; // the symbol table index and the type of relocation
qword r_addend; // a constant addend used to compute the relocatable field value
};

typedef struct Elf64_Shdr Elf64_Shdr, *PElf64_Shdr;

typedef enum Elf_SectionHeaderType_AARCH64 {
    SHT_NULL=0,
    SHT_PROGBITS=1,
    SHT_SYMTAB=2,
    SHT_STRTAB=3,
    SHT_RELA=4,
    SHT_HASH=5,
    SHT_DYNAMIC=6,
    SHT_NOTE=7,
    SHT_NOBITS=8,
    SHT_REL=9,
    SHT_SHLIB=10,
    SHT_DYNSYM=11,
    SHT_INIT_ARRAY=14,
    SHT_FINI_ARRAY=15,
    SHT_PREINIT_ARRAY=16,
    SHT_GROUP=17,
    SHT_SYMTAB_SHNDX=18,
    SHT_ANDROID_REL=1610612737,
    SHT_ANDROID_RELA=1610612738,
    SHT_GNU_ATTRIBUTES=1879048181,
    SHT_GNU_HASH=1879048182,
    SHT_GNU_LIBLIST=1879048183,
    SHT_CHECKSUM=1879048184,
    SHT_SUNW_move=1879048186,
    SHT_SUNW_COMDAT=1879048187,
    SHT_SUNW_syminfo=1879048188,
    SHT_GNU_verdef=1879048189,
    SHT_GNU_verneed=1879048190,
    SHT_GNU_versym=1879048191,
    SHT_AARCH64_ATTRIBUTES=1879048195
} Elf_SectionHeaderType_AARCH64;

struct Elf64_Shdr {
dword sh_name;
    enum Elf_SectionHeaderType_AARCH64 sh_type;
qword sh_flags;
qword sh_addr;
qword sh_offset;
qword sh_size;
dword sh_link;
dword sh_info;
qword sh_addralign;
qword sh_entsize;
};

typedef struct Elf64_Dyn_AARCH64 Elf64_Dyn_AARCH64, *PElf64_Dyn_AARCH64;

typedef enum Elf64_DynTag_AARCH64 {
    DT_NULL=0,
    DT_NEEDED=1,
    DT_PLTRELSZ=2,
    DT_PLTGOT=3,
    DT_HASH=4,
    DT_STRTAB=5,
    DT_SYMTAB=6,
    DT_RELA=7,
    DT_RELASZ=8,
    DT_RELAENT=9,
    DT_STRSZ=10,
    DT_SYMENT=11,
    DT_INIT=12,
    DT_FINI=13,
    DT_SONAME=14,
    DT_RPATH=15,
    DT_SYMBOLIC=16,
    DT_REL=17,
    DT_RELSZ=18,
    DT_RELENT=19,
    DT_PLTREL=20,
    DT_DEBUG=21,
    DT_TEXTREL=22,
    DT_JMPREL=23,
    DT_BIND_NOW=24,
    DT_INIT_ARRAY=25,
    DT_FINI_ARRAY=26,
    DT_INIT_ARRAYSZ=27,
    DT_FINI_ARRAYSZ=28,
    DT_RUNPATH=29,
    DT_FLAGS=30,
    DT_PREINIT_ARRAY=32,
    DT_PREINIT_ARRAYSZ=33,
    DT_RELRSZ=35,
    DT_RELR=36,
    DT_RELRENT=37,
    DT_ANDROID_REL=1610612751,
    DT_ANDROID_RELSZ=1610612752,
    DT_ANDROID_RELA=1610612753,
    DT_ANDROID_RELASZ=1610612754,
    DT_ANDROID_RELR=1879040000,
    DT_ANDROID_RELRSZ=1879040001,
    DT_ANDROID_RELRENT=1879040003,
    DT_GNU_PRELINKED=1879047669,
    DT_GNU_CONFLICTSZ=1879047670,
    DT_GNU_LIBLISTSZ=1879047671,
    DT_CHECKSUM=1879047672,
    DT_PLTPADSZ=1879047673,
    DT_MOVEENT=1879047674,
    DT_MOVESZ=1879047675,
    DT_FEATURE_1=1879047676,
    DT_POSFLAG_1=1879047677,
    DT_SYMINSZ=1879047678,
    DT_SYMINENT=1879047679,
    DT_GNU_XHASH=1879047924,
    DT_GNU_HASH=1879047925,
    DT_TLSDESC_PLT=1879047926,
    DT_TLSDESC_GOT=1879047927,
    DT_GNU_CONFLICT=1879047928,
    DT_GNU_LIBLIST=1879047929,
    DT_CONFIG=1879047930,
    DT_DEPAUDIT=1879047931,
    DT_AUDIT=1879047932,
    DT_PLTPAD=1879047933,
    DT_MOVETAB=1879047934,
    DT_SYMINFO=1879047935,
    DT_VERSYM=1879048176,
    DT_RELACOUNT=1879048185,
    DT_RELCOUNT=1879048186,
    DT_FLAGS_1=1879048187,
    DT_VERDEF=1879048188,
    DT_VERDEFNUM=1879048189,
    DT_VERNEED=1879048190,
    DT_VERNEEDNUM=1879048191,
    DT_AUXILIARY=2147483645,
    DT_FILTER=2147483647
} Elf64_DynTag_AARCH64;

struct Elf64_Dyn_AARCH64 {
    enum Elf64_DynTag_AARCH64 d_tag;
qword d_val;
};

typedef struct Elf64_Sym Elf64_Sym, *PElf64_Sym;

struct Elf64_Sym {
dword st_name;
byte st_info;
byte st_other;
word st_shndx;
qword st_value;
qword st_size;
};

typedef struct GnuBuildId GnuBuildId, *PGnuBuildId;

struct GnuBuildId {
dword namesz; // Length of name field
dword descsz; // Length of description field
dword type; // Vendor specific type
    char name[4]; // Vendor name
    byte hash[20];
};

typedef struct Elf64_Ehdr Elf64_Ehdr, *PElf64_Ehdr;

struct Elf64_Ehdr {
byte e_ident_magic_num;
    char e_ident_magic_str[3];
byte e_ident_class;
byte e_ident_data;
byte e_ident_version;
byte e_ident_osabi;
byte e_ident_abiversion;
    byte e_ident_pad[7];
word e_type;
word e_machine;
dword e_version;
qword e_entry;
qword e_phoff;
qword e_shoff;
dword e_flags;
word e_ehsize;
word e_phentsize;
word e_phnum;
word e_shentsize;
word e_shnum;
word e_shstrndx;
};

typedef struct NoteAbiTag NoteAbiTag, *PNoteAbiTag;

struct NoteAbiTag {
dword namesz; // Length of name field
dword descsz; // Length of description field
dword type; // Vendor specific type
    char name[4]; // Vendor name
dword abiType; // 0 == Linux
    dword requiredKernelVersion[3]; // Major.minor.patch
};

typedef struct group group, *Pgroup;

struct group {
    char *gr_name;
    char *gr_passwd;
    __gid_t gr_gid;
    char **gr_mem;
};



extern pointer typeinfo;
extern undefined1 nds_system[62042112];
extern undefined4 ErrHandler;
extern pointer __dso_handle;
extern undefined8 Cache;
extern undefined __tcf_0;
extern int DAT_004f4d44;
extern undefined4 DAT_004f5140;
extern undefined4 crc_tables;
extern undefined __libc_csu_fini;
extern undefined __libc_csu_init;
// undefined main; // 注释掉，main在drastic.cpp中定义
extern undefined1 completed_9126;
extern undefined8 mini_hash_accesses;
extern undefined8 mini_hash_misses;
extern undefined8 DAT_00269018;
extern undefined8 hash_accesses;
extern undefined8 DAT_00269020;
extern undefined8 DAT_00269028;
extern undefined8 hash_hit_lengths;
#ifdef __GLIBC__
// 系统已经定义了 stdout，跳过
// extern undefined stdout; // 注释掉，避免冲突
#else
extern undefined stdout;
#endif // __GLIBC__
undefined __stack_chk_guard = 0;
extern undefined DAT_0021aa98;
extern undefined DAT_0021aac0;
extern undefined DAT_0021aae0;
extern pointer long_options_11199;
#ifdef __GLIBC__
// 系统已经定义了 optarg，跳过
// extern undefined optarg; // 注释掉，避免冲突
#else
extern undefined optarg;
#endif // __GLIBC__
extern undefined cpu_next_action_arm9_to_arm7;
// cpu_next_action_arm7_to_event_update declared in drastic_functions.h
extern undefined1 polygon_sort_list_13776[790528];
extern undefined store_palette_deferred8;
extern undefined store_palette_deferred16;
extern undefined store_palette_deferred32;
extern undefined store_oam_deferred32;
extern undefined store_oam_deferred8;
extern undefined store_oam_deferred16;
extern ushort switchdataD_0021b858;
extern undefined UNK_0011187c;
extern undefined DAT_0021b988;
extern undefined DAT_0021c818;
extern undefined memory_get_code_bitmap_fine_direct;
extern undefined memory_get_code_bitmap_coarse_direct;
extern undefined memory_get_code_bitmap_null;
extern undefined load_gba_backup_16;
extern undefined store_gba_backup_8;
extern undefined load_gba_backup_32;
extern undefined load_gba_backup_8;
extern undefined store_gba_backup_32;
extern undefined store_gba_backup_16;
extern undefined load_rumble_8;
extern undefined store_rumble_8;
extern undefined load_rumble_16;
extern undefined store_rumble_16;
extern undefined store_rumble_32;
extern undefined load_rumble_32;
extern undefined load_motion_high_16;
extern undefined load_motion_high_32;
extern undefined load_motion_low_16;
extern undefined load_motion_low_8;
extern undefined load_motion_low_32;
extern undefined load_motion_high_8;
extern undefined load_motion_hb_low_8;
extern undefined load_motion_hb_high_16;
extern undefined load_motion_hb_low_32;
extern undefined load_motion_hb_low_16;
extern undefined load_motion_hb_high_32;
extern undefined load_motion_hb_high_8;
extern undefined load_cart_arm7_8;
extern undefined load_cart_arm9_8;
extern undefined load_cart_arm7_32;
extern undefined load_cart_arm7_16;
extern undefined load_cart_arm9_32;
extern undefined load_cart_arm9_16;
extern undefined memory_wram_arm9_get_page_pointer;
extern undefined store_io_register_arm9_8;
extern undefined load_io_register_arm9_8;
extern undefined memory_vram_get_code_bitmap_coarse;
extern undefined load_io_register_arm9_32;
extern undefined load_io_register_arm9_16;
extern undefined store_io_register_arm9_32;
extern undefined memory_vram_arm9_get_page_pointer_store;
extern undefined memory_wram_get_code_bitmap_fine;
extern undefined memory_vram_arm9_get_page_pointer;
extern undefined store_io_register_arm9_16;
extern undefined memory_wram_get_code_bitmap_coarse;
extern undefined memory_vram_get_code_bitmap_fine;
extern undefined load_wifi_8;
extern undefined store_io_register_arm7_8;
extern undefined memory_vram_arm7_get_page_pointer_store;
extern undefined load_wifi_16;
extern undefined store_wifi_32;
extern undefined load_wifi_32;
extern undefined memory_wram_arm7_get_page_pointer;
extern undefined store_io_register_arm7_16;
extern undefined store_wifi_16;
extern undefined load_io_register_arm7_8;
extern undefined store_wifi_8;
extern undefined store_io_register_arm7_32;
extern undefined load_io_register_arm7_16;
extern undefined memory_vram_arm7_get_page_pointer;
extern undefined load_io_register_arm7_32;
extern undefined store_palette_deferred_first16;
extern undefined store_oam_deferred_first32;
extern undefined store_oam_deferred_first8;
extern undefined load_palette_deferred_first32;
extern undefined store_palette_deferred_first32;
extern undefined store_palette_deferred_first8;
extern undefined load_palette_deferred_first8;
extern undefined load_oam_deferred_first8;
extern undefined store_oam_deferred_first16;
extern undefined load_palette_deferred_first16;
extern undefined load_oam_deferred_first32;
extern undefined load_oam_deferred_first16;
// extern undefined event_gamecard_irq_function;  // Now declared as function in drastic.cpp
// extern undefined event_hblank_start_function;  // Now declared as function in drastic.cpp
// event_force_task_switch_function declared in drastic_functions.h
// event_scanline_start_function declared in drastic_functions.h
extern undefined event_dma_complete_function;
// extern undefined event_timer_overflow_function;  // 已在 drastic_functions.h 中定义
void event_timer_overflow_function(long param_1,long *param_2);
extern undefined1 cycles_non_sequential_11154;
extern undefined1 cycles_sequential_11153[256];
extern undefined DAT_0021d610;
extern undefined DAT_0021d600;
extern undefined1 CSWTCH_70;
extern undefined1 cpu_modes_cpsr[28];
extern undefined1 psr_masks_11490[64];
undefined1 bit_count;
undefined4 triggered_flags_11721;
extern char DAT_040270ff;
extern undefined1 condition_source_flags_11246;
extern undefined8 icache_line_size_11647;
extern undefined8 dcache_line_size_11648;
extern undefined cpu_block_execution_compare_function;
extern undefined4 count_frames_11411;
extern undefined1 tick_history_11413;
extern undefined4 frames_total_11417;
extern undefined4 frames_rendered_11416;
extern undefined8 last_instructions_arm7_11415;
extern undefined8 last_instructions_arm9_11414;
extern undefined1 print_buffer_11412[128];
// extern undefined video_render_thread;  // 已在 drastic_functions.h 中定义
void video_render_thread(long param_1);
extern undefined1 polygon_sort_list_15121[1576960];
extern undefined DAT_0025f000;
extern undefined1 tile_coordinate_flip_table;
extern undefined1 mosaic_masks_11557[64];
extern undefined DAT_0021def1;
extern undefined obj_size_table_13328;
extern undefined render_scanline_affine_extended_ext;
extern undefined render_scanline_bitmap_8bpp;
extern undefined render_scanline_null;
extern undefined render_scanline_bitmap_16bpp;
extern undefined render_scanline_tiled_ext;
extern undefined render_scanline_affine_normal_ext;
extern undefined1 vertex_orders;
extern byte BYTE_ARRAY_0024947d[15];
extern undefined1 reciprocal_table[4096];
extern undefined1 reciprocal_table_u[4096];
extern dword DWORD_00249490;
extern undefined2 polygon_sort_counts_13777;
extern dword fde_0023e480;
extern dword DWORD_00249498;
extern dword fde_0024948c;
extern Elf64_Rela __DT_RELA[1482];
extern undefined2 polygon_sort_counts_15122;
extern byte BYTE_ARRAY_0024949d[19];
extern byte BYTE_ARRAY_002494c1[39];
extern byte BYTE_ARRAY_0024951d[131];
extern dword DWORD_002495d0;
extern undefined8 video_3d_thread;
extern undefined DAT_0021df58;
extern undefined video_3d_run_thread;
extern undefined video_3d_render_thread;
extern undefined DAT_04028130;
extern undefined4 scanline_3d_downsampled;
extern undefined1 face_mask_flip_table_11811;
extern Elf64_Sym __DT_SYMTAB[285];
undefined *dispatch_table_12077;
extern undefined1 geometry_command_parameters[128];
extern undefined1 geometry_command_cycles[256];
extern undefined DAT_0021e3d0;
extern undefined1 unique_color_map_11295[262144];
extern undefined1 zero_palette_11294;
extern undefined1 texels_per_hword_shift;
extern undefined1 bytes_per_dest_texel[9];
extern undefined1 copy_palette_11377[512];
extern undefined1 palette_sizes_11384[16];
extern undefined2 adpcm_step_table;
extern undefined8 adpcm_index_step_table;
extern undefined1 noise_samples;
extern undefined1 psg_samples[128];
extern undefined DAT_0021f028;
extern undefined1 command_parameter_counts_11153;
extern char* desmume_footer_str_11260;
extern undefined compare_game_entry_crc32;
extern undefined compare_game_entry_game_code;
extern undefined1 crc32_table;
extern undefined4 DAT_004ec27c;
FILE *DAT_004ec248;
extern undefined1 savestate_thread_data;
extern undefined8 DAT_004ec250;
extern undefined8 DAT_004ec258;
char *DAT_004ec260;
char *DAT_004ec268;
char *DAT_004ec270;
extern uint DAT_004ec278;
extern undefined DAT_004ebe40;
extern undefined DAT_004ec240;
extern undefined save_state_thread_function;
extern undefined DAT_00220328;
undefined *benchmark_phase_names;
extern undefined1 benchmark_phase_disable_names[56];
extern undefined1 favorite_colors;
extern undefined DAT_002217e8;
// extern undefined compare_file_info;  // 已在 drastic_functions.h 中定义
int compare_file_info(long *param_1,long *param_2);
undefined *PTR_s_filename_002603d8;
undefined *PTR_s_title_002603e0;
undefined *PTR_s_rom_title_002603e8;
//extern undefined compare_directory_names;
//extern undefined compare_file_names;
undefined *nds_ext;
//extern undefined draw_menu_option;
extern undefined draw_numeric_labeled;
extern undefined action_input;
extern undefined draw_input;
extern undefined draw_button_config;
extern undefined action_button_config;
extern undefined select_save_config_local;
extern undefined1 yes_no_labels_11875[16];
extern undefined1 orientation_labels_11877[24];
extern undefined select_delete_config_local;
extern undefined select_save_config_global;
extern undefined draw_menu_video_options;
// select_exit_current_menu declared in drastic_functions.h
extern undefined focus_menu_none;
extern undefined1 frameskip_labels_11876[24];
extern undefined1 yes_no_labels_11889[16];
extern undefined1 speed_override_labels_11890[64];
extern undefined1 slot2_device_type_labels_11891[48];
extern undefined draw_menu_options;
extern long UNK_00000038;
extern undefined select_restore_default_controls;
extern long UNK_00000040;
extern undefined1 UNK_00000048;
extern pointer input_names_11897;
extern undefined draw_menu_controls;
extern undefined4 options_to_config_map_11898;
extern pointer input_names_11914;
extern undefined4 options_to_config_map_11915;
extern undefined1 language_labels_11938[64];
extern undefined1 color_labels_11939[128];
extern undefined1 birthday_month_labels_11940[96];
extern undefined draw_menu_firmware;
// extern undefined draw_menu_main;  // 已在 drastic_functions.h 中定义
void draw_menu_main(void);
extern undefined1 speed_override_values_11981[32];
extern undefined compare_cheat_entry_game_code;
extern undefined DAT_00222f98;
extern undefined DAT_00222fa8;
undefined *cpu_mode_names;
extern undefined8 DAT_004ec288;
extern undefined8 DAT_004ec290;
extern undefined8 DAT_004ec298;
extern undefined8 DAT_004ec2a0;
extern undefined8 DAT_004ec2a8;
extern undefined8 DAT_004ec2b0;
extern undefined8 DAT_004ec2b8;
extern undefined8 _saved_reg;
extern undefined8 _metadata_ptr;
extern undefined DAT_00222538;
extern undefined DAT_00223368;
extern undefined DAT_00223d78;
extern undefined DAT_00223d80;
extern undefined1 obj_size_table_11495;
extern undefined DAT_002231e0;
extern undefined1 _command_11260[256];
extern undefined8 repeat_command_11261;
extern undefined DAT_002241f0;
#ifdef __GLIBC__
// 系统已经定义了 stdin，跳过
// extern undefined stdin; // 注释掉，避免冲突
#else
extern undefined stdin;
#endif // __GLIBC__
extern undefined DAT_00224241;
undefined *reg_names;
extern pointer shift_table;
extern undefined1 condition_table[128];
extern undefined1 data_proc_opcode_table[128];
extern undefined1 memory_transfer_op_type[16];
extern undefined1 memory_transfer_op2_type[64];
extern undefined DAT_00224320;
extern undefined1 psr_flags[128];
extern undefined1 block_memory_table[32];
extern undefined1 block_memory_op_type[16];
extern undefined DAT_00224350;
extern undefined1 coprocessor_register_transfer_type[16];
extern undefined1 psr_op_type[16];
extern undefined DAT_002243f8;
extern undefined DAT_002244c8;
extern undefined DAT_002244d0;
extern undefined1 long_multiply_type[32];
extern undefined DAT_002245e0;
extern undefined1 t_mem_op2_table[16];
extern undefined UNK_002245e8;
extern undefined DAT_002245f0;
extern undefined2 DAT_002245f8;
extern undefined1 t_alu_op_table[128];
extern undefined1 t_mem_op_table[16];
extern undefined1 t_alu_op_imm_table[32];
extern undefined1 t_mem_op_reg_table[32];
extern undefined DAT_00224718;
extern undefined1 t_mem_op_imm_table[32];
extern undefined1 t_mem_op2_reg_table[32];
extern undefined1 t_alu_op_hi_table[32];
extern undefined1 t_bmem_op_table[16];
extern undefined1 t_add_sub_table[16];
extern pointer current_font;
extern undefined1 font_a[9224];
extern undefined1 font_b[9224];
extern undefined4 font_c;
extern undefined8 DAT_004ec3f0;
extern undefined8 lua_state;
extern long DAT_004ec3e0;
extern long DAT_004ec3e8;
extern pointer lua_load_libs;
extern undefined DAT_004ec3f8;
undefined *lua_drastic_module;
extern pointer lua_constants;
extern undefined1 DAT_00224b20;
extern undefined UNK_0025e018;
extern undefined luaopen_base;
extern undefined1 DAT_004ec3f9;
extern undefined8 last_ticks_37385;
extern int DAT_040315a8;
undefined8 SDL_screen;
extern undefined DAT_04031528;
extern undefined DAT_04031540;
extern undefined1 DAT_04031541;
extern undefined8 DAT_04031580;
extern undefined8 DAT_04031598;
extern undefined8 DAT_04031578;
extern undefined DAT_040315cc;
extern undefined4 DAT_040315a0;
extern undefined DAT_040315c4;
extern uint DAT_040315a4;
extern undefined DAT_040315ac;
extern undefined8 DAT_04031530;
extern undefined DAT_04031558;
extern undefined1 DAT_04031568;
extern undefined8 DAT_04031570;
extern undefined8 DAT_040315d4;
extern undefined DAT_040315b4;
extern undefined DAT_040315b8;
extern undefined DAT_040315e4;
extern undefined DAT_040315bc;
extern int DAT_040315ec;
extern undefined8 DAT_040315dc;
extern undefined8 DAT_04031588;
extern undefined8 DAT_04031590;
extern undefined DAT_04031548;
undefined1 stylus_raw_1;
extern undefined1 DAT_04031569;
extern undefined8 UNK_04031550;
undefined1 stylus_raw_0[4096];
// void *DAT_04031598; // 已由undefined8声明
extern undefined DAT_040315c0;
extern undefined1 SDL_input[2112];
extern undefined8 DAT_040315f8;
extern undefined8 gui_actions;
extern undefined4 cursor_repeat_37536;
extern undefined8 button_repeat_timestamp_37534;
extern undefined4 button_repeat_state_37535;
// extern undefined audio_callback;  // 已在 drastic_functions.h 中定义
void audio_callback(ulong param_1,void *param_2,int param_3);
extern undefined arm64_msr_cpsr_low;
extern undefined arm64_msr_spsr;
extern undefined1 psr_mask_immr_12090;
extern undefined1 psr_mask_imms_12091[16];
extern undefined1 DAT_00227300;
extern undefined DAT_00227308;
extern undefined DAT_00227310;
extern undefined block_itcm_branch_arm;
extern undefined block_itcm_branch_thumb;
extern undefined block_indirect_branch;
extern undefined arm64_load_memory16_unsigned;
extern undefined arm64_load_memory16_signed;
extern undefined arm64_load_memory32_unsigned;
extern undefined arm64_load_memory64;
extern undefined arm64_load_ext8_unsigned;
extern undefined arm64_load_ext8_signed;
extern undefined arm64_load_ext16_unsigned;
extern undefined arm64_load_ext16_signed;
extern undefined arm64_load_ext32_unsigned;
extern undefined arm64_store_memory8_arm9;
extern undefined arm64_store_memory16_arm9;
extern undefined arm64_store_memory32_arm9;
extern undefined arm64_store_memory8_arm7;
extern undefined arm64_store_memory16_arm7;
extern undefined arm64_store_memory32_arm7;
extern undefined arm64_load_memory8_unsigned;
extern undefined arm64_load_memory8_signed;
undefined *arm64_load_block_functions;
extern undefined1 arm64_store_block_functions[128];
extern undefined arm64_spsr_restore;
extern undefined arm64_set_cpu_mode;
extern undefined arm64_shift_reg_flags_ror;
extern undefined block_halt;
extern undefined arm64_update_coprocessor_control;
extern undefined arm64_update_coprocessor_dtcm_control;
extern undefined arm64_update_coprocessor_itcm_control;
extern undefined arm64_shift_reg_flags_lsl;
extern undefined arm64_shift_reg_flags_lsr;
extern undefined arm64_shift_reg_flags_asr;
extern undefined1 disasm_labels[1280];
extern undefined DAT_00227368;
extern pointer cpu_type_str_12573;
extern undefined DAT_00227b38;
extern undefined DAT_00227b40;
extern undefined DAT_00227b48;
extern undefined DAT_0021dca0;
extern undefined DAT_00228150;
extern undefined DAT_00228160;
extern undefined DAT_00228170;
extern undefined DAT_00228180;
extern undefined DAT_00228190;
extern undefined DAT_002281a0;
extern undefined DAT_002281b0;
extern undefined DAT_002281c0;
extern undefined DAT_002281d0;
extern undefined DAT_002281e0;
extern undefined DAT_002281f0;
extern undefined DAT_00228200;
extern undefined DAT_00228210;
extern undefined DAT_00228220;
extern undefined DAT_00228230;
extern undefined1 condition_strs[128];
extern undefined1 l_strs[16];
extern undefined1 unconditional_branch_ops[56];
extern undefined1 load_store_size_strs[32];
extern undefined1 load_store_op_strs[32];
extern undefined1 load_store_option_strs[64];
extern undefined1 stp_ldp_strs[16];
extern undefined1 flag_strs[16];
extern undefined1 add_sub_strs[16];
extern undefined1 bitfield_op_strs[32];
extern undefined1 logical_op_strs[64];
extern undefined1 move_wide_strs[32];
extern undefined1 p_strs[16];
extern undefined1 ext_reg_option_strs[64];
extern undefined1 shift_reg_strs[32];
extern undefined1 adc_sbc_strs[16];
extern undefined1 csel_op_strs[32];
extern undefined1 dp1_op_strs[64];
extern undefined1 dp2_op_strs[128];
extern undefined1 dp3_op_strs[128];
extern undefined DAT_002247b8;
extern pointer n_strs;
extern undefined UNK_0019b5fc;
extern undefined UNK_0019b788;
extern undefined UNK_0019c9e4;
extern undefined UNK_0019cb70;
extern byte LAB_0019f27c;
byte LAB_0019f27c_p1;
byte LAB_0019f27c_p2;
byte LAB_0019f27c_p3;
extern uint DAT_004ec428;
extern undefined8 unrar_userdata;
extern uint DAT_004ec420;
extern uint DAT_004ec424;
extern undefined8 g_current_unpack_done;
extern pointer g_Alloc;
extern undefined8 g_current_unpack_size;
extern undefined BufferOutStream_Write;
extern undefined SzAllocTemp;
extern undefined SzFreeTemp;
// SzFree declared in drastic_functions.h
// SzAlloc declared in drastic_functions.h
extern undefined unzip_out_func;
extern undefined unzip_in_func;
extern undefined unrar_callback_extract_file;
extern undefined unrar_callback_extract_buffer;
extern undefined unrar_process_data_partial;
extern undefined8 g_CrcUpdate;
extern undefined1 g_CrcTable[1024];
extern undefined EXT_04032240;
extern undefined CrcUpdateT1;
extern char DAT_00267d11;
extern char DAT_00267d12;
extern char DAT_00267d13;
extern char DAT_00267d14;
extern char DAT_00267d15;
extern undefined1 k7zSignature;
extern undefined FileSeqInStream_Read;
extern undefined FileInStream_Seek;
extern undefined FileInStream_Read;
extern undefined FileOutStream_Write;
extern undefined LookToRead_Read;
extern undefined LookToRead_Look_Lookahead;
extern undefined LookToRead_Look_Exact;
extern undefined LookToRead_Skip;
extern undefined LookToRead_Seek;
extern undefined SecToLook_Read;
extern undefined SecToRead_Read;
extern undefined1 CSWTCH_33;
extern undefined UNK_002286f0;
extern undefined DAT_00228a38;
extern undefined DAT_002287f0;
extern undefined4 StrNum;
extern undefined1 StrTable[32768];
extern undefined DAT_00228888;
extern undefined1 DAT_002289e0;
extern undefined DAT_002289e8;
extern undefined DAT_002289f0;
extern undefined DAT_002289f8;
undefined *ConfPath;
pointer PTR_tilde_File_0025e458;
extern undefined Tell;
extern undefined Seek;
pointer PTR_tilde_Archive_0025e490;
extern undefined Read;
extern undefined1 DAT_00228a50;
extern undefined4 mask;
extern char DAT_004f446b;
extern undefined4 CachePos;
extern undefined1 InitSubstTable20;
extern undefined8 DAT_004f4478;
extern undefined8 DAT_004f4480;
extern undefined8 DAT_004f4488;
extern undefined DAT_004f4490;
extern undefined1 DAT_004f4694;
extern undefined8 DAT_004f4695;
extern undefined DAT_00228aa0;
extern undefined4 Count;
extern undefined4 DAT_004f5940;
extern undefined4 DAT_004f6940;
extern undefined DAT_00228b38;
extern undefined DAT_00228ba8;
extern undefined DAT_00228c08;
extern undefined1 LogName;
extern undefined4 BreakCount;
extern undefined ProcessSignal;
extern undefined1 rcon;
extern undefined1 S;
extern undefined1 U4;
extern undefined DAT_004f8e71;
extern undefined DAT_004f8e72;
extern undefined DAT_004f8e73;
extern undefined1 DAT_004f9271;
extern undefined2 DAT_004f9272;
extern undefined1 DAT_004f9671;
extern undefined1 DAT_004f9672;
extern undefined1 DAT_004f9673;
extern undefined1 DAT_004f9a71;
extern undefined1 DAT_004f9a72;
extern undefined1 DAT_004f9a73;
extern undefined1 U1;
extern undefined1 U2;
extern undefined1 U3;
extern undefined1 T5;
extern undefined DAT_004f9e71;
extern undefined DAT_004f9e72;
extern undefined1 T6;
extern undefined DAT_004f9e73;
extern undefined1 T7;
extern undefined1 DAT_004fa271;
extern undefined1 T8;
extern undefined1 DAT_004fa272;
extern undefined1 S5;
extern undefined1 DAT_004fa273;
extern undefined1 DAT_004fa671;
extern undefined1 DAT_004fa672;
extern undefined1 DAT_004fa673;
extern undefined1 DAT_004faa71;
extern undefined1 DAT_004faa72;
extern undefined1 DAT_004faa73;
extern undefined UNK_00228d2c;
extern undefined DAT_00228000;
extern undefined8 DAT_00267e48;
extern undefined8 EmptyHash;
extern undefined8 DAT_00267e50;
extern undefined8 DAT_00267e58;
extern undefined1 DAT_00229348;
extern undefined4 DecL2;
extern undefined1 PosL2[52];
extern undefined4 DecL1;
extern undefined1 PosL1[52];
extern undefined4 DecHf2;
extern undefined1 PosHf2[52];
extern undefined4 DecHf1;
extern undefined1 PosHf1[52];
extern undefined4 DecHf0;
extern undefined1 PosHf0[52];
extern undefined4 DecHf4;
extern undefined1 PosHf4[52];
extern undefined4 DecHf3;
extern undefined1 PosHf3[52];
extern undefined1 ExpEscape;
extern undefined1 LDecode[28];
extern undefined1 LBits[28];
extern undefined1 DDecode[192];
extern undefined1 DBits[48];
extern undefined8 SDDecode;
extern undefined8 SDBits;
extern undefined1 Masks[16];
extern undefined tilde_bad_alloc;
#ifdef __GLIBC__
// 系统已经定义了 memchr 函数，跳过
// extern undefined memchr; // 注释掉，避免冲突
#else
extern undefined memchr;
#endif // __GLIBC__
extern int DAT_004faf74;
extern undefined DAT_004faf80;
extern undefined DAT_004faf90;
extern undefined DAT_004fafa0;
extern undefined DAT_004fafb0;
extern undefined DAT_004fafc0;
extern undefined DAT_004fafd0;
extern undefined DAT_004fafe0;
extern undefined DAT_004faff0;
extern undefined DAT_004fb000;
extern undefined4 DBitLengthCounts;
extern undefined DAT_004fb010;
extern undefined DAT_004fb020;
extern undefined DAT_004fb030;
extern undefined DAT_004fb040;
extern undefined DAT_004fb050;
extern undefined DAT_004fb060;
extern undefined UnpackDecodeThread;
extern undefined PoolThread;
extern undefined4 GlobalPoolUseCount;
extern undefined8 GlobalPool;
extern undefined1 CSWTCH_143[80];
extern undefined DAT_00229350;
extern undefined DAT_002293e0;
extern undefined1 DAT_002286e8;
extern undefined1 kMaskToBitNumber;
extern undefined8 kMaskToAllowedStatus;
extern undefined1 DAT_00229500;
extern undefined4 DAT_00229568;
extern undefined1 blake2s_sigma;
extern undefined8 blake2s_IV;
extern undefined Blake2Thread;
extern undefined growstack;
extern undefined1 version_4688;
extern undefined8 luaO_nilobject_;
extern undefined DAT_00229c08;
extern undefined1 luaT_typenames_[88];
extern undefined f_call;
extern undefined1 DAT_002296a8;
extern undefined1 luaP_opmodes;
extern undefined DAT_00223198;
extern undefined UNK_002297c8;
extern undefined DAT_002297d0;
extern undefined DAT_002297d8;
extern undefined DAT_00229800;
extern undefined DAT_00229920;
extern undefined resume;
extern undefined f_parser;
extern undefined1 DAT_002299e8;
extern undefined DAT_002299f0;
extern undefined dothecall;
extern undefined1 log_2_6309;
extern undefined1 luai_ctype_;
extern undefined DAT_00229a78;
extern undefined DAT_00229aa0;
extern undefined DAT_0022a020;
extern undefined UNK_0022a0c1;
extern undefined1 priority;
extern undefined lua_newstate;
extern undefined f_luaopen;
extern undefined1 dummynode_;
extern pointer luaT_eventname_4611;
extern undefined DAT_0022a380;
extern undefined DAT_00224920;
#ifdef __GLIBC__
// 系统已经定义了 stderr，跳过
// extern undefined stderr; // 注释掉，避免冲突
#else
extern undefined stderr;
#endif // __GLIBC__
extern undefined1 DAT_0022a5c0;
extern undefined DAT_0022a5e8;
extern undefined DAT_0022a5f8;
extern undefined DAT_0022a600;
extern undefined DAT_0022a660;
extern undefined DAT_0022a798;
extern undefined DAT_0022a7a0;
extern undefined getF;
extern undefined DAT_0022a7c8;
extern undefined getS;
extern undefined DAT_0022a298;
extern undefined DAT_0022a810;
extern undefined DAT_0022a818;
extern undefined panic;
extern undefined l_alloc;
extern undefined DAT_0022a968;
extern undefined1 optsnum_5156;
undefined *opts_5155;
extern undefined finishpcall;
extern undefined generic_reader;
extern undefined dofilecont;
extern undefined luaB_next;
extern undefined ipairsaux_raw;
extern undefined ipairsaux;
extern undefined DAT_0021f5c0;
extern undefined DAT_00224cc8;
extern undefined luaB_type;
extern undefined1 base_funcs[400];
undefined *bitlib;
extern undefined io_noclose;
extern undefined io_fclose;
extern undefined io_pclose;
extern undefined io_readline;
extern undefined1 mode_5359;
undefined *modenames_5360;
extern undefined1 modenames_5351[32];
extern undefined DAT_0022ad50;
extern undefined1 mode_5350[12];
extern undefined1 iolib[192];
extern undefined1 flib[160];
extern undefined4 DAT_00227b30;
extern undefined DAT_0022aea0;
extern undefined DAT_0022aea8;
undefined *mathlib;
extern undefined gmatch_aux;
extern undefined writer;
extern undefined DAT_0022b0e8;
undefined *strlib;
extern undefined lua_rawgeti;
extern undefined lua_geti;
extern undefined lua_seti;
extern undefined lua_rawseti;
undefined *tab_funcs;
extern undefined iter_aux;
extern undefined1 limits_5057;
extern undefined DAT_0022b890;
extern undefined DAT_0022b900;
undefined *funcs;
extern undefined1 CLIBS;
extern undefined DAT_0022b9b0;
extern undefined DAT_0022b9b8;
extern undefined DAT_0022b9e0;
extern undefined DAT_0022b9e8;
extern undefined DAT_0022b9f0;
extern undefined DAT_0022b9f8;
extern undefined DAT_0022ba78;
extern undefined UNK_0025f008;
extern undefined DAT_0022a1d0;
extern pointer pk_funcs;
extern undefined1 ll_funcs[32];
extern undefined gctm;
extern undefined searcher_preload;
extern undefined1 DAT_00229790;
extern undefined DAT_0022bd48;
extern undefined DAT_0022bd50;
extern pointer luaX_tokens;
extern undefined UNK_0022bde0;
extern undefined UNK_0022bde8;
extern pointer __frame_dummy_init_array_entry;

// DAT_0021aa98
undefined DAT_0021aa98;

// DAT_0021aac0
undefined DAT_0021aac0;

// DAT_0021aae0
undefined DAT_0021aae0;

// DAT_004ec3f0
undefined8 DAT_004ec3f0;

// DAT_004ec3f8
undefined DAT_004ec3f8;

// DAT_004ec3f9
undefined1 DAT_004ec3f9;

// DAT_040270ff
char DAT_040270ff;

// DAT_04031528
undefined DAT_04031528;

// DAT_04031530
undefined8 DAT_04031530;

// DAT_04031540
undefined DAT_04031540;

// DAT_04031541
undefined1 DAT_04031541;

// DAT_04031548
undefined DAT_04031548;

// DAT_04031558
undefined DAT_04031558;

// DAT_04031568
undefined1 DAT_04031568;

// DAT_04031569
undefined1 DAT_04031569;

// DAT_04031570
undefined8 DAT_04031570;

// DAT_04031578
undefined8 DAT_04031578;

// DAT_04031580
undefined8 DAT_04031580;

// DAT_04031588
undefined8 DAT_04031588;

// DAT_04031590
undefined8 DAT_04031590;

// DAT_04031598
undefined8 DAT_04031598;

// DAT_040315a0
undefined4 DAT_040315a0;

// DAT_040315a4
uint DAT_040315a4;

// DAT_040315a8
int DAT_040315a8;

// DAT_040315ac
undefined DAT_040315ac;

// DAT_040315b4
undefined DAT_040315b4;

// DAT_040315b8
undefined DAT_040315b8;

// DAT_040315bc
undefined DAT_040315bc;

// DAT_040315c4
undefined DAT_040315c4;

// DAT_040315cc
undefined DAT_040315cc;

// DAT_040315d4
undefined8 DAT_040315d4;

// DAT_040315dc
undefined8 DAT_040315dc;

// DAT_040315e4
undefined DAT_040315e4;

// DAT_040315ec
int DAT_040315ec;

// DAT_040315f8
undefined8 DAT_040315f8;

#ifdef __cplusplus
}
#endif

#endif // DRASTIC_GLOBALS_H
