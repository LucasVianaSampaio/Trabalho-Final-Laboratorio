all: main.e

main.e: main.o func_LAB.o
		gcc -o main.e main.o func_LAB.o

main.o: main.c 
	gcc -o main.o -c main.c

func_LAB.o: func_LAB.c
	gcc -o func_LAB.o -c func_LAB.c

clean:
	rm -f *.o main.e