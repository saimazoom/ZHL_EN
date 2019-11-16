;
;
;       ZX Maths Routines
;
;       9/12/02 - Stefano Bodrato
;
;       $Id: dleq.asm,v 1.5 2016-06-22 19:59:18 dom Exp $
;


IF FORzx
		INCLUDE  "zxfp.def"
ENDIF
IF FORzx81
		INCLUDE  "81fp.def"
ENDIF
IF FORlambda
		INCLUDE  "lambdafp.def"
ENDIF

                SECTION  code_fp
                PUBLIC    dleq

                EXTERN	fsetup
                EXTERN	f_yesno

.dleq
        call    fsetup
	defb	ZXFP_SUBTRACT
	defb	ZXFP_GREATER_0
IF FORlambda
	defb	ZXFP_NOT + 128
ELSE
	defb	ZXFP_NOT
	defb	ZXFP_END_CALC
ENDIF
	
	jp	f_yesno
