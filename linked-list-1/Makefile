CC=gcc
CFLAG=-Wall -ansi

Main: main.c LinkedList
	$(CC) $(CFLAG) list.o main.c -o main

LinkedList:
	$(CC) $(CFLAG) -c list/list.c

.PHONY: clean

clean:
	rm *.o main
