CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -c -Iinclude

all:
	make build
	make tester
	
main.o:
	$(CC) $(CFLAGS) src/main.c -o bin/main.o
		
priorityQueue.o:
	$(CC) $(CFLAGS) src/priorityQueue.c -o bin/priorityQueue.o	

patient.o:
	$(CC) $(CFLAGS) src/patient.c -o bin/patient.o

fileIO.o:
	$(CC) $(CFLAGS) src/fileIO.c -o bin/fileIO.o	

testMain.o:
	$(CC) $(CFLAGS) src/testMain.c -o bin/testMain.o

build: main.o priorityQueue.o fileIO.o patient.o
	$(CC) bin/main.o bin/priorityQueue.o bin/fileIO.o bin/patient.o -o bin/runMe

tester: testMain.o priorityQueue.o fileIO.o patient.o
	$(CC) bin/testMain.o bin/priorityQueue.o bin/patient.o bin/fileIO.o -o bin/testMe

run:
	./bin/runMe ./assets/data.txt

test:
	./bin/testMe
