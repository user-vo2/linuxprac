CFLAGS = -g -Wall -Wextra

bin_PROGRAMS=rhasher

rhasher_SOURCES=rhasher.c

TESTS=tests

tests:
	echo -n 'MD5 rhasher' | ./rhasher | tr '\n' ' ' > my1
	cat my1 | cut -d ' ' -f 3 > res
	tr '\n' ' ' < res > res1
	echo " ./rhasher" >> res1
	md5sum -c res1
	echo -n 'SHA1 rhasher' | ./rhasher | tr '\n' ' ' > my2
	cat my2 | cut -d ' ' -f 3 > res
	tr '\n' ' ' < res > res1
	echo " ./rhasher" >> res1
	sha1sum -c res1

gitclean:
	git clean -df