#--------------------------------------------------------------------------
# Makefile for pcomp
# Uncomment debug macros before delivery

#CC = gcc

# Debug
#CC = gcc -g -nodefaultlibs -lc -lrt
CC = gcc -g
#CC = gcc

#YACC = bison -y
BISON = bison -v
LEX = flex

#LDFLAGS = -s -v
#LDFLAGS =

#LIBS = -lm -lefence
LIBS = -lm

# Debug
#LIBS = -Wl,--no-as-needed -lefence -lm -lrt -lc
#LIBS = -lefence -lm -lrt -lc -lpthread -l/lib/ld-linux.so.2 \
#LIBS =  -lm -lrt -lc -lpthread -l/lib/ld-linux.so.2 \

# Debug
#CFLAGS =  -DSETPROCTITLE -Wformat=no
#CFLAGS =  -Wformat=no
CFLAGS =  -w

DEPENDSON =  symtab.c symtab.h codegen.c codegen.h emalloc.c emalloc.h \
             pmath.c Makefile parser/pcomp.yacc.c parser/ppre.yacc.c \
             parser/pcomp.lex.c parser/ppre.lex.c

OBJS = emalloc.o codegen.o pmath.o symtab.o

#.c.o:
#	${CC} ${CFLAGS} pmath.c -c -o pmath.o

#.c.o :
#	$(CC) $(CFLAGS) –c $@c

#all: pcomp
#${CC} ${CFLAGS} codegen.c -c -o codegen.o
#${CC} ${CFLAGS} pmath.c -c -o pmath.o
#${CC} ${CFLAGS} symtab.c -c -o symtab.o
#${CC} ${CFLAGS} emalloc.c -c -o emalloc.o
#

pcomp: pcomp.y pcomp.f ppre.y ppre.f ${OBJS} ${DEPENDSON}
	mkdir -p parser
	${CC} ${CFLAGS} codegen.c -c -o codegen.o
	${CC} ${CFLAGS} pmath.c -c -o pmath.o
	${CC} ${CFLAGS} symtab.c -c -o symtab.o
	${CC} ${CFLAGS} emalloc.c -c -o emalloc.o
	${CC} ${CFLAGS} ${LDFLAGS} parser/pcomp.lex.c parser/ppre.lex.c \
            ${OBJS} -o pcomp  ${LIBS}

parser/ppre.lex.c: ppre.f  ppre.y
	${LEX} -Ppre -oppre.c -o parser/ppre.lex.c ppre.f

parser/pcomp.lex.c: pcomp.f  pcomp.y
	${LEX} -Pconf -o parser/pcomp.lex.c  pcomp.f

parser/pcomp.yacc.c:  pcomp.y pcomp.f
	${BISON} -p conf pcomp.y -o parser/pcomp.yacc.c

parser/ppre.yacc.c:  ppre.y ppre.f
	${BISON} -p pre ppre.y  -o parser/ppre.yacc.c

clean:
	rm -f *.o  parser/* pcomp.c pcomp.tab.c core pcomp \#*

test: pcomp
	./pcomp ../tests/comment.pc






