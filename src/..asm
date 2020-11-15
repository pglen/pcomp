;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;                                                                         
;   Compile with NASM                                                     
;                                                                         
                                                                          
        global main                                                       
        extern printf                                                     
        section .text                                                     
                                                                          
main:                                                                     
        push    rdx                     ; callee-save registers           
        push    rsi                     ; callee-save registers           
        push    rdi                                                       
                                                                          
        mov     rsi, 1                  ; current value                   
        mov     rdi, 10                 ; counter                         
                                                                          
L1:                                                                       
        push    rsi                     ; caller-save register            
        push    rdi                     ; caller-save register            
                                                                          
        mov     rdx, rdi                ; third rdx                       
                                        ; sec parm rsi (alread OK)        
        mov     rdi, format             ; set 1st parameter (format)      
                                                                          
        call    printf                                                    
                                                                          
        pop     rdi                                                       
        pop     rsi                                                       
                                                                          
        add     rsi, rsi                ; double value                    
        dec     rdi                     ; keep counting                   
                                                                          
        jne     L1                                                        
                                                                          
        pop     rdi                                                       
        pop     rsi                                                       
        pop     rdx                                                       
        ret                                                               
                                                                          
        section .data                                                     
                                                                          
format: db      '1826466040 0', 10, 0                                          
format2: db      "Hello world", 10, 0                                   
                                                                          
; Data

START_CODE:

; Code


END_CODE:
    ;End of program

