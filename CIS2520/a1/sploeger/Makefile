CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -c -Iinclude

all:
	make build
	make tester
	
main.o:
	$(CC) $(CFLAGS) src/main.c -o bin/main.o
		
LinkedListAPI.o:
	$(CC) $(CFLAGS) src/LinkedListAPI.c -o bin/LinkedListAPI.o	

car.o:
	$(CC) $(CFLAGS) src/car.c -o bin/car.o

fileIO.o:
	$(CC) $(CFLAGS) src/fileIO.c -o bin/fileIO.o	

testMain.o:
	$(CC) $(CFLAGS) src/testMain.c -o bin/testMain.o	

build: main.o LinkedListAPI.o car.o fileIO.o
	$(CC) bin/main.o bin/LinkedListAPI.o bin/car.o bin/fileIO.o -o bin/runMe

tester: testMain.o LinkedListAPI.o car.o fileIO.o
	$(CC) bin/testMain.o bin/LinkedListAPI.o bin/car.o bin/fileIO.o -o bin/testMe

run:
	./bin/runMe ./assets/data.txt

test:
	./bin/testMe
