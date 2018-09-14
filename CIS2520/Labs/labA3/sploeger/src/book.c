#include "book.h"
#include <stdio.h>
#include <stdlib.h>

/*Book functions*/
/**
 * A function to create a new book
 * 
 * @param title of book
 * @param price of book
 * 
 * @return a book
 * */
Book* createBook( char * title, double price )
{
	Book* b = malloc(sizeof(Book));
    b->price  = price;
    b->name = title;
    return b;
}

/**
 * A function to get the price of a book
 * 
 * @param a book
 * 
 * @return price of the book
 * */
double getPrice( Book * b )
{
	return b->price;
}

/**
 * A function to get the print book info
 * 
 * @param a book
 * 
 * @return price of the book
 * @return title of a book
 * */
void printBook( void * b )
{
	printf("%s : %f\n", getName(b), getPrice(b) );
}

/**
 * A function to get the name of a book
 * 
 * @param a book
 * @return title of a book
 * */
char* getName( Book *b )
{
	return b->name;
}

void deleteBook(void* toBeDeleted)
{
	Book* b = (Book*)toBeDeleted;
	free(b);
}

int compareBook(const void* first, const void* second)
{
	Book* book1 = (Book*)first;
	Book* book2 = (Book*)second;
	
	return(book1->price-book2->price);
}
