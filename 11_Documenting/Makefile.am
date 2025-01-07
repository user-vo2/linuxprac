AM_CFLAGS = -g -Wall -Wextra

@DX_RULES@

all-local:doxygen-clean doxygen-doc

man1_MANS = doxygen-doc/man/man1/guess.1
bin_PROGRAMS=guess
pkgdata_DATA = ./ru/LC_MESSAGES/guess.mo

doxygen-clean:
	rm -rf doxygen-doc

doxygen-doc: doxygen-clean
	doxygen Doxyfile

doxygen-doc/man/man1/guess.1: doxygen-doc

install-data-local:
	mkdir -p $(DESTDIR)/$(docdir)
	cp -a doxygen-doc/html $(DESTDIR)/$(docdir)

http: doxygen-doc
	python3 -m http.server --directory $</html 5000

ru/LC_MESSAGES/guess.mo: russian.po
	mkdir -p `dirname $@`
	msgfmt $< -o $@

russian.po:	lines.pot
	msgmerge -U $@ $<

lines.pot:	orig.pot guess.c
	xgettext --keyword=_ -c guess.c -o lines.pot
	msgmerge -U lines.pot orig.pot

gitclean:
	git clean -df