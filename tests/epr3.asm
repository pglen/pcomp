;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;                                                                         
;   Compile with FASM                                                     
;                                                                         
                                                                          
use32                                                                     
               org    0x0                                                 
                                                                          
               db    'SIMOS01'               ; 8 byte id                  
               dd     0x01                   ; header version             
               dd     START_CODE             ; start of code              
               dd     END_CODE               ; size of image              
               dd     0x100000               ; memory for app             
               dd     0x7fff0                ; esp                        
               dd     0x0 , 0x0              ; I_Param , I_Icon           
; Data
; Data
; Data
; Data
var_bbb: dw  	500
var_ddd: dd  	10
; Data
var_aaa: dd  	0
var_bbb: dw  	0
var_ccc: db  	0
var_ddd: dd  	0
var_eee: dw  	0
var_fff: db  	0
var_ggg: dd  	0
var_hhh: dq  	0
; Data
; Data
var_ccc: dd  	0
var_ddd: dd  	0
var_eee: dd  	0
var_fff: dd  	0

START_CODE:

; Code
; Code
; Code
; Code
; Code
; Code
; Code


END_CODE:
    ;End of program

