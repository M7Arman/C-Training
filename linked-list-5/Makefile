CC=gcc
CFLAG=-Wall -ansi

Main: LinkedList
	$(CC) $(CFLAG) main.c list.o -o main

LinkedList: 
	$(CC) $(CFLAG) -c list/list.c -o list.o

.PHONY:
	clean

clean:
	rm *.o main