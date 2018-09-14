CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -c -Iinclude

all:
	make build
	
main.o:
	$(CC) $(CFLAGS) src/main.c -o bin/main.o

store.o:
	$(CC) $(CFLAGS) src/store.c -o bin/store.o
	
boardgame.o:
	$(CC) $(CFLAGS) src/boardgame.c -o bin/boardgame.o
	
book.o:
	$(CC) $(CFLAGS) src/book.c -o bin/book.o

build: main.o store.o boardgame.o book.o
	$(CC) bin/main.o bin/store.o bin/boardgame.o bin/book.o -o bin/runMe
