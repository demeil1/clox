clox:
	gcc compiler.c compiler.h  scanner.c scanner.h chunk.c  chunk.h common.h main.c  memory.c  memory.h debug.c debug.h value.c value.h vm.c vm.h -o clox

clean:
	rm -rf *.gch clox

rebuild:
	rm -rf *.gch clox
	gcc compiler.c compiler.h  scanner.c scanner.h chunk.c  chunk.h common.h main.c  memory.c  memory.h debug.c debug.h value.c value.h vm.c vm.h -o clox
