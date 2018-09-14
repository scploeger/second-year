CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -c -Iinclude

all:
	make build
	
main.o:
	$(CC) $(CFLAGS) src/main.c -o bin/main.o	

build: main.o
	$(CC) bin/main.o lib/libLinkedList.a -o bin/runMe
run:
	./bin/runMe
