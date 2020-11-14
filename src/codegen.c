///////////////////////////////////////////////////////////////////////////
//
// Code generator for FASM output
//

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#include "symtab.h"
#include "codegen.h"

static int		gen_expr(Symbol *sp);
static Symbol 	*do_expr(Symbol *sp);

static	int		show_item(Symbol *sp, outstr **root);

static	int		decl_var(Symbol *sp);
static	int		decl_assign(Symbol *sp);
static	int		decl_arit(Symbol *sp, char *str, int mul);

static	int		decl_func(Symbol *sp);
static	int		decl_func_end(Symbol *sp);

static	char 	*typep2a(char *name, char *str, double *val, int *pri);
static	char	*get_regstr(int size, char rname);
static 	char	*get_sizestr(int size);
static  int		is_num(char *str);


static	char	tmp_str[128];

static	outstr *dataroot = 0;
static	outstr *fdataroot = 0;

static	outstr *coderoot = 0;
static	outstr *fcoderoot = 0;

static	outstr *varroot = 0;

static	outstr *stateroot = 0;

static	int 	compstate = 0;		// main code generator state
static	int 	errstate = 0;		// error variable

//////////////////////////////////////////////////////////////////////////
//

#define 	IN_FUNC 1
#define 	MAX(aa, bb) aa > bb ? aa : bb

int	gen_code()

{
    Symbol *sp ;

	//return;

	prologue();

	add_ddef(&dataroot, "; Data\n");
	add_ddef(&coderoot, "; Code\n");

    for (sp = symlist ; sp != (Symbol *) 0 ; sp = sp->next)
        {
		//show_item(sp);

		//if(state == 0)
			{
		   	if(sp->type == DECL_VARITEM)
		   		{
		   		// Add item
        		Symbol *sss = lookup_symtab(sp->name, DECL_VARITEM);

				//printf("sss %s %p -- sp %s %p\n", sss->name, sss,
				//		sp->name, sp);

    			if((sss != NULL) && (sss < sp) )
    				{
    				printf("Symbol already defined '%s'\n", sp->name);
    				errstate++;
    				break;
    				}
				add_ddef(&varroot, sp->name);
		   		}
		   	if(sp->type == DECL_VARLIST)
		   		{
		   		outstr *sp2; int pri;
				char *ttt = typep2a(sp->name, sp->var, &sp->u.dval, &pri);

				// Out all vars on this definition stack
    			for(sp2 = varroot; sp2 != NULL; sp2 = sp2->next)
        			{
        			Symbol *sss = lookup_symtab(sp2->line, DECL_VARITEM);

					sprintf(tmp_str, "var_%s:  %s  %d\n",  sp2->line, ttt, 0);
					add_ddef(&dataroot, tmp_str);
					}
				empty_ddef(&varroot);
		   		}

		   	if(sp->type == DECL_VAR)
		   		{
		   		decl_var(sp);
		   		}
		   	if(sp->type == DECL_CALL2)
		   		{
		   		decl_call(sp);
		   		}
		   	if(sp->type == DECL_CALL3)
		   		{
		   		decl_call(sp);
		   		}
		   	if(sp->type == RET_EXPR)
		   		{
		   		ret_expr(sp);
		   		}
		   	if(sp->type == DECL_CAST)
		   		{
		   		decl_cast(sp);
		   		}
		   	else if(sp->type == FUNC_DECL_NAME)
		   		{
		   		push_ddef(&stateroot, compstate);

		   		//push_ddef_ptr(&dataroot, dataroot);

		   		compstate = IN_FUNC;
		   		decl_func(sp);
		   		}
		   	else if(if_func(sp->type))
		   		{
		   		// Function done, emit it
		   		decl_func_end(sp);
		   		pop_ddef(&stateroot, &compstate);

		   		//pop_ddef_ptr(&dataroot, &funcroot);

		   		print_ddata(fdataroot);
		   		print_ddata(fcoderoot);
		   		}
		   	else if(sp->type == '=')
		   		{
		   		decl_assign(sp);
		   		}
		   	else if(sp->type == '+')
		   		{
		   		decl_arit(sp, "add", 0);
		   		}
		   	else if(sp->type == '-')
		   		{
		   		decl_arit(sp, "sub", 0);
		   		}
		   	else if(sp->type == '*')
		   		{
		   		decl_arit(sp, "mul", 1);
		   		}
		   	else if(sp->type == '/')
		   		{
		   		decl_arit(sp, "div", 1);
		   		}
		   	else if(sp->type == '%')
		   		{
		   		decl_arit(sp, "div", 2);
		   		}
			}

		if(errstate)
			break;
		}

		if(!errstate)
			{
			print_ddata(dataroot);
			fprintf(asmfp, "\nSTART_CODE:\n\n");
			print_ddcode(coderoot);
			fprintf(asmfp, "\n");

			epilogue();
			}

}

char *prolstr = "\
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n\
;                                                                         \n\
;   Compile with NASM                                                     \n\
;                                                                         \n\
                                                                          \n\
        global main                                                       \n\
        extern printf                                                     \n\
        section .text                                                     \n\
                                                                          \n\
main:                                                                     \n\
        push    rdx                     ; callee-save registers           \n\
        push    rsi                     ; callee-save registers           \n\
        push    rdi                                                       \n\
                                                                          \n\
        mov     rsi, 1                  ; current value                   \n\
        mov     rdi, 10                 ; counter                         \n\
                                                                          \n\
L1:                                                                       \n\
        push    rsi                     ; caller-save register            \n\
        push    rdi                     ; caller-save register            \n\
                                                                          \n\
        mov     rdx, rdi                ; third rdx                       \n\
                                        ; sec parm rsi (alread OK)        \n\
        mov     rdi, format             ; set 1st parameter (format)      \n\
                                                                          \n\
        call    printf                                                    \n\
                                                                          \n\
        pop     rdi                                                       \n\
        pop     rsi                                                       \n\
                                                                          \n\
        add     rsi, rsi                ; double value                    \n\
        dec     rdi                     ; keep counting                   \n\
                                                                          \n\
        jne     L1                                                        \n\
                                                                          \n\
        pop     rdi                                                       \n\
        pop     rsi                                                       \n\
        pop     rdx                                                       \n\
        ret                                                               \n\
                                                                          \n\
        section .data                                                     \n\
                                                                          \n\
format: db      \'%d %d\', 10, 0                                          \n\
format2: db      \"Hello world\", 10, 0                                   \n\
                                                                          \n\
";

int	prologue()

{
	if(noprologue)
		return;
    fprintf(asmfp, prolstr);
    return 0;
}


int	epilogue()

{
	if(noprologue)
		return;

fprintf(asmfp, "\
\nEND_CODE:\n    ;End of program\n\n"\
);
}

int		decl_assign(Symbol *sp)

{
		char *ttt = "none", *tttt = "none";
		int pri1 = 0, pri2 = 0;

		Symbol *sp3 = lookup_symtab(sp->name, DECL_VAR);
		//printf("sp3=%p\n", sp3);
		if(sp3)
			ttt = typep2a(sp3->name, sp3->var, &sp3->u.dval, &pri1);
		else
			{
			printf("Undefined variable '%s'\n", sp->name);
			errstate++;
			return 0;
			}

		Symbol *sp4 = lookup_symtab(sp->var, DECL_VAR);
		//printf("sp4=%p\n", sp4);
		if(sp4)
			tttt = typep2a(sp4->name, sp4->var, &sp4->u.dval, &pri2);

		char *accum = get_regstr(MAX(pri1, pri2), 'a');

		sprintf(tmp_str, "    mov %s, %s ;assign\n",  accum, sp->var);
		add_ddef(&coderoot, tmp_str);

		sprintf(tmp_str, "    mov [%s], %s ;assign\n",  sp->name, accum);
		add_ddef(&coderoot, tmp_str);
}


int		decl_arit(Symbol *sp, char *str, int mul)

{
		char *ttt = "dd", *tttt = "dd";  int pri1 = 0, pri2 = 0;
		int		emit = 1;  // flag to control emittion (case: const)

		Symbol *sp3 = lookup_symtab(sp->name, DECL_VAR);
		//printf("sp3=%p\n", sp3);
		if(sp3)
			ttt = typep2a(sp3->name, sp3->var, &sp3->u.dval, &pri1);

		Symbol *sp4 = lookup_symtab(sp->var, DECL_VAR);
		//printf("sp4=%p\n", sp4);
		if(sp4)
			tttt = typep2a(sp4->name, sp4->var, &sp4->u.dval, &pri2);

		// Determine larger variable
        char *ttttt = ttt;
		Symbol *sp5 = sp3;
		if(pri1 < pri2)
			sp5 = sp4, ttttt = tttt;

		char	*accum = get_regstr(MAX(pri1, pri2), 'a');
		char 	*opsize = get_sizestr(MAX(pri1, pri2));

		//printf("ttt '%s' tttt '%s' accum '%s' opsize '%s'\n",
		//						ttt, tttt, accum, opsize);

		//show_item(sp, &coderoot);

		// Declare temp var
		if(strncmp(sp->res, "tmp", 3) == 0)
			{
			sprintf(tmp_str, "%s: %s  %s\n",  sp->res, ttttt, "0");
			add_ddef(&dataroot, tmp_str);
			}
		if(mul == 2)
			{
			sprintf(tmp_str, "    mov %s, %s ;%s\n", accum, sp->name, str);
			add_ddef(&coderoot, tmp_str);

			sprintf(tmp_str, "    %s  %s [%s]\n",  str, opsize, sp->var);
			add_ddef(&coderoot, tmp_str);

			char	*deex = get_regstr(MAX(pri1, pri2), 'd');

			sprintf(tmp_str, "    mov  %s, %s\n", accum, deex, str, opsize, sp->var);
			add_ddef(&coderoot, tmp_str);
			}
		else if(mul == 1)
			{
			sprintf(tmp_str, "    mov %s, %s ;%s\n", accum, sp->name, str);
			add_ddef(&coderoot, tmp_str);

			sprintf(tmp_str, "    %s  %s [%s]\n",  str, opsize, sp->var);
			add_ddef(&coderoot, tmp_str);
			}
		else
			{
			// Constant, calc in line, no symtab
			if(is_num(sp->name) && is_num(sp->var))
				{
				int dec, sign;
				int resx = atoi(sp->name) + atoi(sp->var);

				char *resstr =  ecvt((float)resx, 16, &dec, &sign);
				resstr[dec] = '\0';
				printf("num %s %s %d %s\n", sp->name, sp->var, resx, resstr);
				emit = 0;
				}
			else
				{
				sprintf(tmp_str, "    mov %s, var_%s ;%s\n",  accum, sp->name, str);
				add_ddef(&coderoot, tmp_str);

				sprintf(tmp_str, "    %s %s, var_%s\n",  str, accum, sp->var);
				add_ddef(&coderoot, tmp_str);
				}
        	}

		if(emit)
			{
			sprintf(tmp_str, "    mov [var_%s], %s\n",  sp->res, accum);
			add_ddef(&coderoot, tmp_str);
			}

		Symbol *sp2 = lookup_res_symtab(sp->res, DECL_VAR);
        if(sp2)
        	{
			//sprintf(tmp_str, "    mov %s, ax\n",  sp->res);
			sprintf(tmp_str, "    mov [%s], %s\n",  sp2->name, accum);
			add_ddef(&coderoot, tmp_str);
        	}
        else
        	{
        	// See if it is emitted already

        	//printf("Error: undefined var '%s'\n", sp->res);
			//errstate++;

			//sprintf(tmp_str, "%s: %s 0\n",  sp->res, ttttt);
			//add_ddef(&dataroot, tmp_str);
        	}
}

///////////////////////////////////////////////////////////////////////////

int		decl_var(Symbol *sp)

{
	int	pri;

	// Conv type to assembler str
	char *ttt = typep2a(sp->name, sp->var, &sp->u.dval, &pri);

	//show_item(sp, &dataroot);

	if(strcmp(sp->res, "") == 0)
		{
		sprintf(tmp_str, "var_%s: %s  \t%d\n",  sp->name, ttt, 0);
		}
	else if(strncmp(sp->res, "tmp", 3) == 0)
		{
		//sprintf(tmp_str, "%s: %s  %s\n",  sp->res, ttt, "0");
		//printf("tmp decl %s\n", tmp_str);
		//add_ddef(&dataroot, tmp_str);

		sprintf(tmp_str, "var_%s: %s  %s\n",  sp->name, ttt, "0");
		//printf("tmp decl %s\n", tmp_str);
		}
	else
		{
		//printf("decl misc\n");
		sprintf(tmp_str, "var_%s: %s  \t%d\n",  sp->name, ttt, (int)sp->u.dval);
		}

    if(compstate == 1)
		add_ddef(&fdataroot, tmp_str);
	else
		add_ddef(&dataroot, tmp_str);
}

///////////////////////////////////////////////////////////////////////////

int		decl_func(Symbol *sp)

{
		show_item(sp, &coderoot);

		sprintf(tmp_str,
		"\n%s: ;-------- function %s -----------\n",
					sp->name, sp->name);
		add_ddef(&coderoot, tmp_str);
	    //state = IN_FUNC;
}

int		decl_func_end(Symbol *sp)

{
		//show_item(sp, &coderoot);

		//printf("    ret  ; end of %s\n",  sp->name);
		sprintf(tmp_str, "    ret    ;%s\n\n", sp->name);
		add_ddef(&coderoot, tmp_str);
	    compstate = 0;
}

///////////////////////////////////////////////////////////////////////////

int		decl_call(Symbol *sp)

{
		//show_item(sp, &coderoot);

		sprintf(tmp_str, "    call %s\n", sp->name);
		add_ddef(&coderoot, tmp_str);

		sprintf(tmp_str, "    mov [%s], ax\n", sp->res);
		add_ddef(&coderoot, tmp_str);

	    //state = IN_FUNC;
}

int		ret_expr(Symbol *sp)

{
		//show_item(sp, &coderoot);

		sprintf(tmp_str, "    mov ax, %s\n", sp->name);
		add_ddef(&coderoot, tmp_str);

	    //state = IN_FUNC;
}

int		decl_cast(Symbol *sp)

{
		sprintf(tmp_str, "    cwd %s ; cast %s to %s\n", sp->var, sp->name, "u8");

		add_ddef(&coderoot, tmp_str);

	    //state = IN_FUNC;
}

///////////////////////////////////////////////////////////////////////////

char *typep2a(char *name, char *str, double *val, int *pri)

{
	char *ret = "tnone";

	//printf("typep2a name='%s' str='%s' %p %p\n", name, str, val, pri);

	if(strcmp(str, "u32") == 0)
		{
		if(*val > U32_MAX)
			{
			printf("; Warning: %s value %d out of range for %s - truncating to %d\n",
			 name, (int)*val, str, U32_MAX);
			*val = U32_MAX;
			}

		ret = "dd";
		*pri = 32;
		}
	else if(strcmp(str, "u16") == 0)
		{
		if(*val > U16_MAX)
			{
			printf("; Warning: %s value %d out of range for %s - truncating to %d\n",
			name, (int)*val, str, U16_MAX);
			*val = U16_MAX;
			}

		ret = "dw";
		*pri = 16;
		}
	else if(strcmp(str, "u8") == 0)
		{
		if(*val > U8_MAX)
			{
			printf("; Warning: %s value %d out of range for %s - truncating to %d\n",
			name, (int)*val, str, U8_MAX);
			*val = U8_MAX;
			}
		ret = "db";
		*pri = 16;
		}
	else if(strcmp(str, "s32") == 0)
		{
		ret = "dd";
		*pri = 32;
		}
	else if(strcmp(str, "s16") == 0)
		{
		ret = "dw";
		*pri = 16;
		}
	else if(strcmp(str, "s8") == 0)
		{
		ret = "db";
		*pri = 16;
		}
	else if(strcmp(str, "float") == 0)
		{
		ret = "dd";
		*pri = 32;
		}
	else if(strcmp(str, "double") == 0)
		{
		ret = "dq";
		*pri = 64;
		}

	return ret;
}

//////////////////////////////////////////////////////////////////////////
//

int		add_ddef_state(char *str)

{
    if(compstate == 1)
		add_ddef(&fdataroot, tmp_str);
	else
		add_ddef(&dataroot, tmp_str);
}


//////////////////////////////////////////////////////////////////////////
//

int		gen_expr(Symbol *sp)

{
    Symbol *sp2 = sp;

    //printf("'%s\n", sp->name);

	show_item(sp, &coderoot);

	do_expr(sp2);
	printf("\n");
}

Symbol *do_expr(Symbol *sp)

{
	if(sp == NULL)
		return NULL;

	Symbol *sp3;
	for (sp3 = sp->next; sp3 != (Symbol *) 0 ; sp3 = sp3->next)
		{
		show_item(sp3, &coderoot);
		if(strcmp(sp->name, sp3->res) == 0)
			{
			do_expr(sp3);
			}
		if(strcmp(sp->var, sp3->res) == 0)
			{
			do_expr(sp3);
			}
		}
	return sp3;
}

///////////////////////////////////////////////////////////////////////////

int		show_item(Symbol *sp, outstr **root)

{
	// No showing is desired
	if(interlace_sym == 0)
	 	return 0;

	char *opstr; translate_type(sp->type, &opstr);

	sprintf(tmp_str, "        ;state %d '%s' '%s' %s(%d) -> '%s' %.2f\n",
					   compstate, sp->name, sp->var,
					 		opstr, sp->type, sp->res, sp->u.dval);

	 add_ddef(root, tmp_str);

	return 0;
}

///////////////////////////////////////////////////////////////////////////
//
// Get register name for different sizes

char	*get_regstr(int size, char rname)

{
	//printf("get_regstr %d %c\n", size, rname);

	char  *ret = (char *)malloc(12);

	strcpy(ret, "eax");

	if(size == 8)
		sprintf(ret, "%cl", rname);

	if(size == 16)
		sprintf(ret, "%cx", rname);

	if(size == 32)
		sprintf(ret, "e%cx", rname);

	//printf("get_regstr '%s'\n", ret);

	return ret;
}

// Get size name for different sizes

char	*get_sizestr(int size)

{
	//printf("get_sizestr %d\n", size);

	char *ret = "siznone";

	if(size == 8)
		ret = "byte";

	if(size == 16)
		ret = "word";

	if(size == 32)
		ret = "dword";

	return ret;
}

///////////////////////////////////////////////////////////////////////////

int		is_num(char *str)

{
	int ret = 0;

	char chh = str[0];

	if(chh >= '0' && chh <= '9')
		ret = 1;

	return ret;
}


