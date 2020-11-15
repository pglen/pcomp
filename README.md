# pcomp      README

## Parallel compiler; Skeleton for a simple language

pcomp is generated in an attempt to simplify programming as a whole.

    * Features simple syntax and data types.
    * Support for locking and atomic access.
    * Easy integration of high level code and assembly.
    * Defines for conditional compilation, macro expansion
    * Macros for easy code substitution.

 Ongoing effort, check back later.

  This is a little ambitious here; we are trying to unify assembler, C, and a higher level
language into one comprehensive compiler.

 The ideal implementation would allow in line assembler into a c like language flow, and
a python like supervisor.

 The conditional compilation would let the assembler choose the correct processor.

 Even if the following snippet is largely hypothetical; it demonstrates the point:


    func memcopy(const ptr *src, ptr *dest, int len)
    {
    #ifdef CPU_NEUTRAL

        char *d = dest;
        const char *s = src;
            while (len--)
                *d++ = *s++;
            return dest;

    #elifdef  INTEL_64

        mov     rax, r11                ; Remember this is hypothetical
        mov     rdi, rcx                ;
        mov     rcx, r8                 ;
        mov     rsi, r10                ;
        rep     movsb                   ;
        ret

    #elifdef  ARM_9

        movs        r2, r2, lsl #31    ; Remember this is hypothetical
        ldrbne        r3, [r1], #1
        ldrbcs        r4, [r1], #1
        ldrbcs        ip, [r1]
        strbne        r3, [r0], #1
        strbcs        r4, [r0], #1
        strbcs        ip, [r0]

    #elifdef  RISC_5

        #warning "No code generated for RISC -- TODO"

    #else

        #error "Must specify a target processor"

    #endif
    }

  Please see SYNTAX for an ongoing attempt to describe the new language syntax,
 and the test directory as an accumulation of case tests.

 Where is the project today?

  lex and yacc skeleton done

  first stage parser operational

  some progress on the code generator

  updated debug subsys ... can observe preprocessor stages

  print options for lex / yacc stages / progress

  YEP -- this is a lot of work. Contributors are welcome.

// End of file