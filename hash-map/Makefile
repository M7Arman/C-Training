Main: HashMap
	$(CC) $(CFLAG) main.c hashmap.o map.o -o main

HashMap: Map
	$(CC) $(CFLAG) -c hashmap/hashmap.c -o hashmap.o

Map:
	$(CC) $(CFLAG) -c hashmap/map/map.c -o map.o

.PHONY: clean

clean:
	rm *.o main