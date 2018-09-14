CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -c -Iinclude

all:
	make build
	make tester
	
main.o:
	$(CC) $(CFLAGS) src/main.c -o bin/main.o

BinarySearchTreeAPI.o:
	$(CC) $(CFLAGS) src/BinarySearchTreeAPI.c -o bin/binarySearchTreeAPI.o	
		
build: main.o BinarySearchTreeAPI.o
	$(CC) bin/main.o bin/BinarySearchTreeAPI.o -o bin/runMe

run:
	./bin/runMe