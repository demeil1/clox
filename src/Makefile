clox:
	gcc *.h *.c -o clox

clean:
	rm -rf *.gch *.clox clox

rebuild:
	rm -rf *.gch clox
	gcc *.h *.c -o clox

debug:
	gcc -g *.h *.c -o clox 
	gdb ./clox

valgrind:
	gcc -g *.h *.c -o clox 
	valgrind --track-origins=yes ./clox input.clox
