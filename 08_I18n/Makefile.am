AM_CFLAGS = -g -Wall -Wextra

bin_PROGRAMS=guess

russian.po:	lines.pot
	msgmerge -U $@ $<

lines.pot:	orig.pot guess.c
	xgettext --keyword=_ -c guess.c -o lines.pot
	msgmerge -U lines.pot orig.pot

gitclean:
	git clean -df