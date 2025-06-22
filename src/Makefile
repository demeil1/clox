clox:
	gcc chunk.c  chunk.h common.h main.c  memory.c  memory.h debug.c debug.h value.c value.h vm.c vm.h -o clox

clean:
	rm -rf *.gch clox

rebuild:
	make clean
	make clox
