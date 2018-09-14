CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -c -Iinclude

all:
	make build
	make tester
	
main.o:
	$(CC) $(CFLAGS) src/main.c -o bin/main.o
		
book.o:
	$(CC) $(CFLAGS) src/book.c -o bin/book.o
	
integers.o:
	$(CC) $(CFLAGS) src/integers.c -o bin/integers.o
	
testMain.o:
	$(CC) $(CFLAGS) src/testMain.c -o bin/testMain.o	

build: main.o book.o integers.o
	$(CC) bin/main.o bin/book.o bin/integers.o lib/libLinkedList.a -o bin/runMe

tester: testMain.o book.o integers.o
	$(CC) bin/testMain.o bin/book.o bin/integers.o lib/libLinkedList.a -o bin/testMe

run:
	./bin/runMe

test:
	./bin/testMe
