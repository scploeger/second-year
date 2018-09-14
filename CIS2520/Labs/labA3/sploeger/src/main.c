#include <stdio.h>
#include "LinkedListAPI.h"
#include "book.h"
#include "integers.h"
#include <stdlib.h>

int main(int argc, char ** argv)
{
	printf("Welcome to Spencer's Lab 2!\n\n\n");
	Book * book1 = createBook("Eating People is Wrong", 15.99);
	Book * book2 = createBook("The Manly Art of Knitting", 12.99);
	Book * book3 = createBook("Old Tractors and the Men Who Love Them", 22.99);
	Book * book4 = createBook("Pole Dancing to Gospel Hyms", 69.99);
	
	
	int* num1 = malloc(sizeof(int));
	int* num2 = malloc(sizeof(int));
	int* num3 = malloc(sizeof(int));
	int* num4 = malloc(sizeof(int));
	*num1 = 1034;
	*num2 = 67;
	*num3 = 15;
	*num4 = 45;
	
	
	
	List * bookList = initializeList(&printBook, &deleteBook, &compareBook);
	List * intList = initializeList(&printInt, &deleteIntPtr, &compareInt);
	
		
	insertSorted(bookList, book1);
	insertSorted(bookList, book2);
	insertSorted(bookList, book3);
	insertSorted(bookList, book4);
	
	insertSorted(intList, num1);
	insertSorted(intList, num2);
	insertSorted(intList, num3);
	insertSorted(intList, num4);
	
	printForward(intList);
	deleteNodeFromList(intList, num3);
	printBackwards(intList);
	
	return 0;
}
