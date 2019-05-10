CC=gcc
CFLAG=-Wall -ansi

Main: LinkedList
	$(CC) $(CFLAG) list.o main.c -o main

LinkedList:
	$(CC) $(CFLAG) -c list/list.c -o list.o

.PHONY: clean

clean:
	rm *.o main