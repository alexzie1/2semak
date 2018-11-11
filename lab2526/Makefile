CC = gcc
CFLAG = -g -std=c99 -w -pipe -03

all: queue_main

queue_main: queue_array.o sort.o queue_main.o
		$(CC) $^ -o $@

clean: 
	rm -f *.o

cleanall: 
	rm -f *.o queue_main


