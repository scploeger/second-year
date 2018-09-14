#include "store.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * A function to create a new store to hold an item
 * 
 * @param a boardgame or a book
 * @param a print function
 * 
 * @return an item
 * */
Store* createStore( void * item, void (* funct) (void *))
{
	Store* s = malloc(sizeof(Store));
    s->item  = item;
    s->fp = funct;
    
    return s;
}

/**
 * A function that displays the contents for stored items
 * 
 * @param stored item
 * 
 * @return void
 * */
 
void displayStore( Store * s)
{
	s->fp(s->item);
}

