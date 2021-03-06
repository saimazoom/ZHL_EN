
// automatically generated by m4 from headers in proto subdir


#ifndef _UNISTD_H
#define _UNISTD_H

#ifndef NULL
#define NULL                   ((void*)(0))
#endif

#ifndef SEEK_SET
#define SEEK_SET               0
#endif

#ifndef SEEK_CUR
#define SEEK_CUR               1
#endif

#ifndef SEEK_END
#define SEEK_END               2
#endif

#define STDIN_FILENO           0
#define STDOUT_FILENO          1
#define STDERR_FILENO          2

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
typedef unsigned int           size_t;
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
typedef unsigned int           ssize_t;
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
typedef long                   off_t;
#endif

#ifndef _INTPTR_T_DEFINED
#define _INTPTR_T_DEFINED
typedef int                    intptr_t;
#endif

extern int __LIB__ __FASTCALL__ close(int fd);


extern int __LIB__ __FASTCALL__ dup(int fd);


extern int __LIB__ dup2(int fd,int fd2) __smallc;
extern int __LIB__ __CALLEE__ dup2_callee(int fd,int fd2) __smallc;
#define dup2(a,b) dup2_callee(a,b)


extern void __LIB__ __FASTCALL__ _exit(int status);


extern off_t __LIB__ lseek(int fd,off_t offset,int whence) __smallc;
extern off_t __LIB__ __CALLEE__ lseek_callee(int fd,off_t offset,int whence) __smallc;
#define lseek(a,b,c) lseek_callee(a,b,c)


extern ssize_t __LIB__ read(int fd,void *buf,size_t nbyte) __smallc;
extern ssize_t __LIB__ __CALLEE__ read_callee(int fd,void *buf,size_t nbyte) __smallc;
#define read(a,b,c) read_callee(a,b,c)


extern ssize_t __LIB__ write(int fd,const void *buf,size_t nbyte) __smallc;
extern ssize_t __LIB__ __CALLEE__ write_callee(int fd,const void *buf,size_t nbyte) __smallc;
#define write(a,b,c) write_callee(a,b,c)



#endif
