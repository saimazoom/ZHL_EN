
; ===============================================================
; aralbrec - Nov 2013
; ===============================================================

XLIB __fzx_glyph_width
LIB __fzx_char_metrics

__fzx_glyph_width:

   ; Return width of char's glyph in pixels.
   ; Unprintable char treated as '?'
   ; 
   ; enter : ix = struct fzx_font *
   ;          a = char
   ;
   ; exit  :  a = total glyph width
   ;            = width + tracking - kern
   ;          b = kern
   ;          carry reset
   ;
   ; uses  : af, bc, hl
   
   ; ix = struct fzx_font *
   ;  a = char

   call __fzx_char_metrics
   jr nc, have_metric
   
   ld a,'?'
   call __fzx_char_metrics

have_metric:

   ; ix = struct font *
   ;  a = shift_width_1
   ; bc = kern_offset

   and $0f
   inc a
   ld c,a                      ; c = glyph width

   ld a,b
   rlca
   rlca
   and $03
   ld b,a                      ; b = kern
   neg                         ; a = -kern
   
   add a,(ix+1)                ; add font tracking
   add a,c                     ; add glyph width

   ret   
