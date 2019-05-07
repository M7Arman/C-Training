CC=gcc
CFlAG=-Wall -ansi

Main: LinkedList
	$(CC) $(CFlAG) main.c list.o -o main

LinkedList:
	$(CC) $(CFlAG) -c list/list.c -o list.o

clean:
	rm *.o main