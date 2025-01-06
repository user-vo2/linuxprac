CFLAGS=-O0 -g
GENERATES = esub *.o *.out

REGEX=(a)b(c)d(e)
SUBST=<\3\2\1>
STR=_abcdef_


all: esub

test: esub
	echo ${STR} | sed -E 's/${REGEX}/${SUBST}/' >sed.out
	./esub '${REGEX}' '${SUBST}' '${STR}' >esub.out
	cmp esub.out sed.out

clean:
	rm -rf $(GENERATES)