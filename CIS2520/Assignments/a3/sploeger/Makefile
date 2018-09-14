CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -c -Iinclude

all:
	make build
	make tester
	
main.o:
	$(CC) $(CFLAGS) src/main.c -o bin/main.o

testMain.o:
	$(CC) $(CFLAGS) src/testMain.c -o bin/testMain.o

hashTableAPI.o:
	$(CC) $(CFLAGS) src/hashTableAPI.c -o bin/hashTableAPI.o	
		
dictionary.o:
	$(CC) $(CFLAGS) src/dictionary.c -o bin/dictionary.o

fileIO.o:
	$(CC) $(CFLAGS) src/fileIO.c -o bin/fileIO.o

build: main.o hashTableAPI.o dictionary.o fileIO.o
	$(CC) bin/main.o bin/hashTableAPI.o bin/dictionary.o bin/fileIO.o -o bin/runMe

tester: testMain.o hashTableAPI.o dictionary.o fileIO.o
	$(CC) bin/testMain.o bin/hashTableAPI.o bin/dictionary.o bin/fileIO.o -o bin/testMe

run:
	./bin/runMe ./assets/dictionary.txt

test:
	./bin/testMe
