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
; Data
var_ccc: dd  	0
var_ddd: dd  	0
var_eee: dd  	0
tmp_1037_ddd_eee: dd  0
tmp_1041_ddd_eee: dd  0
tmp_1045_ddd_eee: dd  0
tmp_1049_ddd_eee: dd  0
tmp_1053_ddd_eee: dd  0
; Data
var_ccc: dd  	0
var_ddd: dd  	0
var_eee: dd  	0
var_fff: dd  	0
tmp_1061_eee_fff: dd  0
tmp_1062_ddd_tmp_1061_eee_fff: dd  0

START_CODE:

; Code
; Code
; Code
; Code
; Code
; Code
; Code
; Code
    mov eax, var_ddd ;add
    add eax, var_eee
    mov [var_tmp_1037_ddd_eee], eax
    mov eax, tmp_1037_ddd_eee ;assign
    mov [ccc], eax ;assign
    mov eax, var_ddd ;sub
    sub eax, var_eee
    mov [var_tmp_1041_ddd_eee], eax
    mov eax, tmp_1041_ddd_eee ;assign
    mov [ccc], eax ;assign
    mov eax, ddd ;mul
    mul  dword [eee]
    mov [var_tmp_1045_ddd_eee], eax
    mov eax, tmp_1045_ddd_eee ;assign
    mov [ccc], eax ;assign
    mov eax, ddd ;div
    div  dword [eee]
    mov [var_tmp_1049_ddd_eee], eax
    mov eax, tmp_1049_ddd_eee ;assign
    mov [ccc], eax ;assign
    mov eax, ddd ;div
    div  dword [eee]
    mov  eax, edx
    mov [var_tmp_1053_ddd_eee], eax
    mov eax, tmp_1053_ddd_eee ;assign
    mov [ccc], eax ;assign
; Code
    mov eax, eee ;mul
    mul  dword [fff]
    mov [var_tmp_1061_eee_fff], eax
    mov eax, var_ddd ;add
    add eax, var_tmp_1061_eee_fff
    mov [var_tmp_1062_ddd_tmp_1061_eee_fff], eax
    mov eax, tmp_1062_ddd_tmp_1061_eee_fff ;assign
    mov [ccc], eax ;assign


END_CODE:
    ;End of program

