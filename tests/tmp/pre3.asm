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
var_cc1: dd  	2000
var_cc2: dd  	2000
var_cc3: dd  	2000
var_cc6: dd  	2000

START_CODE:

; Code


END_CODE:
    ;End of program

