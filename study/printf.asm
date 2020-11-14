;
; nasm -felf64 printf.asm && gcc -no-pie printf.o && ./a.out
;
; Displays powers of 2 from 2^0 to 2^31, one per line, to standard output.
;
; Reg order: rdi,  rsi, rdx, rcx, r8, r9).
; ----------------------------------------------------------------------------

        global main
        extern printf
        section .text

main:
        push    rdx                     ; callee-save registers
        push    rsi                     ; callee-save registers
        push    rdi

        mov     rsi, 1                  ; current value
        mov     rdi, 31                 ; counter

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

format: db      '%d %d', 10, 0
format2: db      "Hello world", 10, 0




