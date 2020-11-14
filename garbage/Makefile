#--------------------------------------------------------------------------
# Makefile for pcomp
# Uncomment debug macros before delivery

#CC = gcc

# Debug
#CC = gcc -g -nodefaultlibs
CC = gcc -g

#YACC = bison -y
BISON = bison -v
LEX = flex

#LDFLAGS = -s -v
#LDFLAGS =

LIBS = -lm -lrt
#LIBS =

# Debug
#LIBS = -Wl,--no-as-needed -lefence -lm -lrt -lc
#LIBS = -lefence -lm -lrt -lc -lpthread -l/lib/ld-linux.so.2 \
#LIBS =  -lm -lrt -lc -lpthread -l/lib/ld-linux.so.2 \

# Debug
#CFLAGS =  -DSETPROCTITLE -Wformat=no
#CFLAGS =  -Wformat=no
CFLAGS =  -w

DEPENDSON =  symtab.c symtab.h codegen.c codegen.h emalloc.c emalloc.h \
			 Makefile

OBJS = emalloc.o codegen.o pmath.o symtab.o

#all: pcomp

pcomp: pcomp.y pcomp.f ppre.y ppre.f ${DEPENDSON}
	mkdir -p parser
	${BISON} -p conf pcomp.y -o parser/pcomp.yacc.c
	${BISON} -p pre ppre.y  -o parser/ppre.yacc.c
	${LEX} -Pconf -o parser/pcomp.lex.c  pcomp.f
	${LEX} -Ppre -oppre.c -o parser/ppre.lex.c ppre.f
	${CC} ${CFLAGS} codegen.c -c -o codegen.o
	${CC} ${CFLAGS} pmath.c -c -o pmath.o
	${CC} ${CFLAGS} symtab.c -c -o symtab.o
	${CC} ${CFLAGS} emalloc.c -c -o emalloc.o
	${CC} ${CFLAGS} ${LDFLAGS} ppre.c pcomp.c  ${OBJS} \
				 -o pcomp  ${LIBS}

clean:
	rm -f *.o  parser/* pcomp.c pcomp.tab.c core pcomp \#*



