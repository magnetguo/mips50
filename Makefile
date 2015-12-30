schedule: main.o mem.o instructions.o id.o
	gcc -o isa main.o mem.o instructions.o id.o -std=c99
main.o: main.c mem.h instructions.h id.h op_and_func.h
	gcc -c main.c -std=c99
mem.o: mem.c mem.h
	gcc -c mem.c -std=c99
instructions.o: instructions.c instructions.h
	gcc -c instructions.c -std=c99
id.o: id.c id.h
	gcc -c id.c -std=c99
