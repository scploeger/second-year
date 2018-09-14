#include "boardgame.h"
#include <stdio.h>
#include <stdlib.h>

/*Boardgame Functions*/

/**
 * A function to create a new boardgame
 * 
 * @param name of a boardgame
 * @param brandname of boardgame
 * @param price of a boardgame
 * 
 * @return a boardgame
 * */
Boardgame* createBoardgame( char * name, char * brandName, double price )
{
	Boardgame* g = malloc(sizeof(Boardgame));
    g->price  = price;
    g->brandName = brandName;
    g->name = name;
    return g;
}

/**
 * A function to get the price of a boardgame
 * 
 * @param a boardgame
 * 
 * @return price of the boardgame
 * */
double getPriceBoardgame( Boardgame * b )
{
	return b->price;
}


/**
 * A function to get the name of a boardgame
 * 
 * @param a boardgame
 * 
 * @return name of the boardgame
 * */
char* getNameBoardgame( Boardgame *b )
{
	return b->name;
}

/**
 * A function to get the brandname of a boardgame
 * 
 * @param a boardgame
 * 
 * @return brandname of the boardgame
 * */
char* getBrandname( Boardgame *b )
{
	return b->brandName;
}

/**
 * A function to get the print boadgame info
 * 
 * @param a boardgame
 * 
 * @return void
 * */
void printBoardgame( void * b )
{
	printf("%s	%lf	%s\n", getNameBoardgame(b), getPriceBoardgame(b), getBrandname(b));
}
