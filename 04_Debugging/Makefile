CFLAGS=-O0 -g
GENERATES= range *.out

all: range

clean:
	rm -rf $(GENERATES)

test1: range
	gdb ./range -x test1.gdb | grep @@@ > output1.out
	@if cmp output1.out output1.test; then\
		echo "PASSED";\
	else \
		echo "FAILED";\
	fi

test2: range
	gdb ./range -x test2.gdb | grep @@@ > output2.out
	@if cmp output2.out output2.test; then\
		echo "PASSED";\
	else \
		echo "FAILED";\
	fi
test: test1 test2