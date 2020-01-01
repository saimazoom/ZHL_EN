
// automatically generated by m4 from headers in proto subdir


#ifndef _INTRINSIC_H
#define _INTRINSIC_H

#ifdef __SDCC

// disable warnings connected to intrinsics

#pragma disable_warning 84
#pragma disable_warning 112

#endif

#ifdef __CLANG

#define intrinsic_label(name)  { extern void intrinsic_label_##name(void); intrinsic_label_##name(); }
#define intrinsic_load16(address)  ((unsigned int)intrinsic_load16_##address())
#define intrinsic_store16(address,value)  ((unsigned int)(intrinsic_store16_address_##address(),intrinsic_store16_value_##value()))

#endif

#ifdef __SDCC

#define intrinsic_label(name)  { extern void intrinsic_label_##name(void) __preserves_regs(a,b,c,d,e,h,l); intrinsic_label_##name(); }
#define intrinsic_load16(address)  ((unsigned int)intrinsic_load16_##address())
#define intrinsic_store16(address,value)  ((unsigned int)(intrinsic_store16_address_##address(),intrinsic_store16_value_##value()))

#endif

#ifdef __SCCZ80

#define intrinsic_label(name)  asm(#name":")
#define intrinsic_load16(address)  ((unsigned int)intrinsic_load16_##address())
#define intrinsic_store16(address,value)  ((unsigned int)(intrinsic_store16_address_##address(),intrinsic_store16_value_##value()))

#endif

extern void intrinsic_stub(void) __preserves_regs(a,b,c,d,e,h,l);


extern void intrinsic_di(void) __preserves_regs(a,b,c,d,e,h,l);

extern void intrinsic_ei(void) __preserves_regs(a,b,c,d,e,h,l);

extern void intrinsic_halt(void) __preserves_regs(a,b,c,d,e,h,l);

extern void intrinsic_reti(void) __preserves_regs(a,b,c,d,e,h,l);

extern void intrinsic_retn(void) __preserves_regs(a,b,c,d,e,h,l);

extern void intrinsic_im_0(void) __preserves_regs(a,b,c,d,e,h,l);

extern void intrinsic_im_1(void) __preserves_regs(a,b,c,d,e,h,l);

extern void intrinsic_im_2(void) __preserves_regs(a,b,c,d,e,h,l);

extern void intrinsic_nop(void) __preserves_regs(a,b,c,d,e,h,l);


extern void intrinsic_ex_de_hl(void) __preserves_regs(a,b,c);

extern void intrinsic_exx(void) __preserves_regs(a);


extern void *intrinsic_return_bc(void) __preserves_regs(a,b,c,d,e);

extern void *intrinsic_return_de(void) __preserves_regs(a,b,c,d,e);


extern unsigned int intrinsic_swap_endian_16(unsigned long n) __preserves_regs(b,c,d,e);
extern unsigned int intrinsic_swap_endian_16_fastcall(unsigned long n) __preserves_regs(b,c,d,e) __z88dk_fastcall;
#define intrinsic_swap_endian_16(a) intrinsic_swap_endian_16_fastcall(a)


extern unsigned long intrinsic_swap_endian_32(unsigned long n) __preserves_regs(b,c);
extern unsigned long intrinsic_swap_endian_32_fastcall(unsigned long n) __preserves_regs(b,c) __z88dk_fastcall;
#define intrinsic_swap_endian_32(a) intrinsic_swap_endian_32_fastcall(a)


extern unsigned long intrinsic_swap_word_32(unsigned long n) __preserves_regs(a,b,c);
extern unsigned long intrinsic_swap_word_32_fastcall(unsigned long n) __preserves_regs(a,b,c) __z88dk_fastcall;
#define intrinsic_swap_word_32(a) intrinsic_swap_word_32_fastcall(a)



#endif