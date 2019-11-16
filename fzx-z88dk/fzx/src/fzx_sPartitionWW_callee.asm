
; ===============================================================
; aralbrec - Nov 2013
; ===============================================================
;
; char *fzx_sPartitionWW(char *s, uint width)
;
; Finds longest prefix string of s that has pixel width less than
; or equal to "width" and whose words fit in the space allotted.
; Words are terminated by space, newline, \0 and AT sequences.
; Newline, \0, and AT indicator cause the iteration to stop.
;
; Returned pointer points at one char past the prefix.
; ie (return - s) is the number of chars in the prefix string.
;
; ===============================================================

XLIB fzx_sPartitionWW_callee
XDEF asm_fzx_sPartitionWW

LIB __fzx_glyph_width, _fzx

DEFC FONT = 0

fzx_sPartitionWW_callee:

   pop hl
   pop de
   ex (sp),hl
   ex de,hl

asm_fzx_sPartitionWW:

   ; enter : de = char *s
   ;         hl = allowed width in pixels
   ;
   ; exit  : hl = s + prefixlen(s)
   ;         ix = struct fzx_font *
   ;
   ;         carry reset if stopped with room available
   ;         de = remaining width in pixels
   ;
   ;         carry set if width exceeded
   ;         de = - remaining width in pixels
   ;
   ; uses  : af, bc, de, hl, ix
   
   ld ix,(_fzx + FONT)         ; ix = current font; struct fzx_font *

   push hl
   ld a,' '
   call __fzx_glyph_width
   ld c,a
   ld b,0                      ; bc = width of space in pixels
   pop hl
   
   dec de

loop_ws:

   ; ix = struct fzx_font *
   ; de = char *s - 1
   ; hl = remaining width
   ; bc = width of space

   inc de
   ld a,(de)
   or a
   jr z, end_string_ws
   
   cp ' '                      ; next word starting?
   jr nz, next_word

word_join:

   sbc hl,bc                   ; is there room for a space?
   jp nc, loop_ws              ; if yes, consume it
   
end_string_ws:

   ; ix = struct fzx_font *
   ; de = s + prefixlen
   ; hl = remaining width

   ex de,hl
   ret

next_word:

   push bc
   push de
   
   ; ix = struct fzx_font *
   ; de = char *s
   ; hl = remaining width
   ;  a = char
   ; stack = width of space, prefix ptr
   
loop_word:
   
   cp 13                       ; terminate at newline
   jr z, end_string_ww_accept
   
   cp 22                       ; terminate at AT sequence
   jr z, end_string_ww_accept
   
   cp ' '                      ; end of word?
   jr z, end_word

   push hl
   
   call __fzx_glyph_width
   ld c,a
   ld b,0                      ; bc = char width
   
   pop hl
   sbc hl,bc                   ; is there room for the char?
   jr c, end_string_ww_reject
   
   inc de
   ld a,(de)                   ; next char
   or a
   jp nz, loop_word

end_string_ww_accept:

   ex de,hl                    ; hl = s + prefixlen
   
   pop bc                      ; junk items on stack
   pop bc
   ret   

end_string_ww_reject:

   ex de,hl
   
   pop hl                      ; hl = s + prefixlen
   pop bc
   ret

end_word:

   ; word accepted
   
   pop bc
   pop bc                      ; bc = width of space
   jp word_join
