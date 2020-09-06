# target: dependancies
# 	action
output:main.o array.o
	gcc main.o array.o -o output
main.o:main.c
	gcc -c main.c
array.o:array.c array.h
	gcc -c array.c
clean:
	rm *.o output
