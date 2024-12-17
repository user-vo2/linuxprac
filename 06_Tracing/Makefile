CFLAGS=-O0 -g
CFLAGS = -Wall -Wextra
GENERATES= move *.in *.out *.log *.so

all: test_all

remove.so: remove.c
	gcc remove.c -shared -fPIC -o remove.so

test:	move
	cat move.c > in.txt
	./move in.txt 2>1.log || test "$$?" = "1"
	rm -rf *.txt
	cat move.c > in.txt
	strace -P out.txt -e fault=openat ./move in.txt out.txt 2>2.log || test "$$?" = "2" && test -f in.txt && ! test -f out.txt
	rm -rf *.txt
	cat move.c > in.txt
	strace -P in.txt -e fault=openat ./move in.txt out.txt 2>3.log || test "$$?" = "2" && test -f in.txt && ! test -f out.txt
	rm -rf *.txt
	cat move.c > in.txt
	strace -P in.txt -e fault=close ./move in.txt out.txt 2>4.log || test "$$?" = "3" && test -f in.txt && ! test -f out.txt
	rm -rf *.txt
	cat move.c > in.txt
	strace -P in.txt -e fault=unlink ./move in.txt out.txt 2>5.log || test "$$?" = "4" && test -f in.txt && test -f out.txt
	rm -rf *.txt
	cat move.c > in.txt
	strace -P in.txt -e fault=read ./move in.txt out.txt 2>6.log || test "$$?" = "5" && test -f in.txt && ! test -f out.txt
	rm -rf *.txt
	cat move.c > in.txt
	strace -e fault=write ./move in.txt out.txt 2>7.log || test "$$?" = "6" && test -f in.txt && ! test -f out.txt
	rm -rf *.txt
	
test_protected: move remove.so
	cat move.c > in_PROTECTED.txt
	LD_PRELOAD=./remove.so ./move in_PROTECTED.txt out.txt 2> protected.log || test -f in_PROTECTED.txt || test -f out.txt
	rm -rf *.txt

test_all: test test_protected

clean::
	rm -rf $(GENERATES)