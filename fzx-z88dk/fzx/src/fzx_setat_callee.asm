
; ===============================================================
; aralbrec - Nov 2013
; ===============================================================
;
; int fzx_setat(uchar y, uchar x)
;
; Set print position to indicated (x,y) pixel coordinate.
;
; ===============================================================

XLIB fzx_setat_callee
XDEF asm_fzx_setat

LIB _fzx

DEFC MARGIN = 2
DEFC P_COL = 4
DEFC P_LIN = 5

fzx_setat_callee:

   pop hl
   pop de
   ex (sp),hl
   
   ld h,l
   ld l,e
   
asm_fzx_setat:

   ; enter : h = y coord
   ;         l = x coord
   ; exit  : carry reset if coords are out of range
   ;         else set current print position  
   ; uses  : af

   ld a,h
   cp 192
   ret nc
   
   ld a,(_fzx + MARGIN)
   cp l
   jr c, no_change
   ld l,a                      ; set x coord to left margin

no_change:

   ld (_fzx + P_COL),hl
  
   scf
   ret
