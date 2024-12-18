GENERATES= maze_gen_patch* *.o maze_gen

all: clean maze_gen maze_gen_patch1 maze_gen_patch2 maze_gen_patch3

maze_gen:
	gcc maze_gen.c -o maze_gen

maze_gen_patch1: maze_gen
	patch maze_gen.c 1.patch -o maze_gen_patch1.c
	gcc maze_gen_patch1.c -o maze_gen_patch1

maze_gen_patch2: maze_gen
	patch maze_gen_patch1.c 2.patch -o maze_gen_patch2.c
	gcc maze_gen_patch2.c -o maze_gen_patch2

maze_gen_patch3: maze_gen
	patch maze_gen_patch2.c 3.patch -o maze_gen_patch3.c
	gcc maze_gen_patch3.c -o maze_gen_patch3


run: all
	./maze_gen
	./maze_gen_patch1 7
	./maze_gen_patch2 " %" 7
	./maze_gen_patch3 42 " %" 7

clean:
	rm -f $(GENERATES)