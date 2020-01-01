
// automatically generated by m4 from headers in proto subdir


#ifndef _SETJMP_H
#define _SETJMP_H

#define setjmp(env)         l_setjmp(&(env))
#define longjmp(env, val)   l_longjmp(&(env), val)

#ifdef __CLANG

typedef struct
{

   void *ix;
   void *iy;
   void *sp;
   void *pc;

} jmp_buf;

#endif

#ifdef __SDCC

typedef struct
{

   void *ix;
   void *iy;
   void *sp;
   void *pc;

} jmp_buf;

#endif

#ifdef __SCCZ80

typedef struct
{

   void *sp;
   void *pc;

} jmp_buf;

#endif

// must not use callee or fastcall linkage

extern int __LIB__ l_setjmp(jmp_buf *env) __smallc;


extern void __LIB__ l_longjmp(jmp_buf *env,int val) __smallc;



#endif