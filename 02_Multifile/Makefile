.PHONY: clean
GENERATES = prog prog-a prog-so README libout.a liboutput_static.a liboutput.so
TRASH = *.o *~ o.* *.out
CFLAGS = -Wall -fPIC

all:    README prog prog-a prog-so

.SECONDARY:	fun.o const.o

liboutput_static.a:	const.o fun.o
	ar -rcs liboutput_static.a const.o fun.o

liboutput.so: fun.o const.o
	$(CC) $^ -shared -o liboutput.so

prog: prog.o fun.o const.o
	$(CC) $^ -o prog

prog-a:	prog.o liboutput_static.a
	$(CC)  -L. $< -loutput_static -o $@

prog-so: prog.o liboutput.so
	$(CC)  -L. $< -loutput -o $@

README: prog prog-a prog-so
	./prog > $@ 2>&1
	./prog-a >> $@ 2>&1
	LD_LIBRARY_PATH=`pwd` ./prog-so >> $@ 2>&1

fun.o prog.o:  outlib.h

test: prog prog-a prog-so
	./prog $(foo) 1>file1.out 2>&1
	./prog-a $(foo) 1>file2.out 2>&1
	LD_LIBRARY_PATH=`pwd` ./prog-so $(foo) 1>file3.out 2>&1
	cmp file1.out file2.out
	cmp file1.out file3.out
	cmp file2.out file3.out

clean:
	rm -f $(TRASH)

distclean:      clean
	rm -rf $(GENERATES)
