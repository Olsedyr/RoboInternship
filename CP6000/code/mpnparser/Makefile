CC        = gcc
LEX       = flex
YACC      = bison
CCFLAGS   = -O0 -pg -g3 -save-temps
#CCFLAGS   = -O2 -fomit-frame-pointers
INCLUDES  = -I../libmpnrobot/libmpnrobot
LDFLAGS   = -L../libmpnrobot/libmpnrobot -lmpnrobot -lm -lstdc++

.PHONY: all
all: mpnparser

stmparser.tab.c: stmparser.y
	$(YACC) -p stm -v -d $<

lex.stm.c: stmscanner.lex stmparser.tab.c
	$(LEX) -Pstm $<

dioparser.tab.c: dioparser.y
	$(YACC) -p dio -v -d $<

lex.dio.c: dioscanner.lex dioparser.tab.c
	$(LEX) -Pdio $<

ppparser.tab.c: ppparser.y
	$(YACC) -p pp -v -d $<

lex.pp.c: ppscanner.lex ppparser.tab.c
	$(LEX) -Ppp $<

parse:  lex.dio.c
	$(CC) $(CCFLAGS) $(INCLUDES) $(LDFLAGS) $^ -o $@

# General rule for code generation

%.o: %.c %.h
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@

mpnparser: stmtree.o lex.dio.o dioparser.tab.o lex.pp.o ppparser.tab.o lex.stm.o stmparser.tab.o main.c stmpretty.o symbol.o stmweed.o stmcollectsymbols.o stmtypecheck.o diotree.o dioweed.o diocollect.o pptree.o ppweed.o ppcollect.o
	$(CC) $(CCFLAGS) $(INCLUDES) $^ -o $@ $(LDFLAGS)

.PHONY: clean
clean:
	- $(RM) *.o *.i *.s *.output
	- $(RM) *~
	- $(RM) stmparser.tab.[ch] dioparser.tab.[ch] ppparser.tab.[ch] lex.dio.c lex.stm.c lex.pp.c
	- $(RM) mpnparser

libmpnparser.a: stmtree.o lex.dio.o dioparser.tab.o lex.pp.o ppparser.tab.o lex.stm.o stmparser.tab.o stmpretty.o symbol.o stmweed.o stmcollectsymbols.o stmtypecheck.o diotree.o dioweed.o diocollect.o pptree.o ppweed.o ppcollect.o
	rm -f libmpnparser.a
	$(AR) rcs libmpnparser.a $^
