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
var1: dd  0
var2: dd  200
var3: dw  500
var4: dw  0
var5: dd  0
tmp_1015_eee_tttt: dw 0
var6: dd  0
tmp_1020_qqq_ccc: dw 0
tmp_1022_ccc_www: dw 0

START_CODE:

    mov ax, 200 ;add
    add ax, 200
    mov [tmp_1004_200_200], ax
    mov [var4], ax
    mov ax, eee ;add
    add ax, tttt
    mov [tmp_1015_eee_tttt], ax
    mov ax, tmp_1015_eee_tttt ;assign
    mov [var3], ax ;assign
    mov ax, aaaa ;add
    add ax, bbbb
    mov [tmp_1018_aaaa_bbbb], ax
    mov [var6], ax
    mov ax, qqq ;add
    add ax, ccc
    mov [tmp_1020_qqq_ccc], ax
    mov ax, tmp_1020_qqq_ccc ;assign
    mov [aaaa], ax ;assign
    mov ax, ccc ;add
    add ax, www
    mov [tmp_1022_ccc_www], ax
    mov ax, tmp_1022_ccc_www ;assign
    mov [bbbb], ax ;assign


END_CODE:
    ;End of program

