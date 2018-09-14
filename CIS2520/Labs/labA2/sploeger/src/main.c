#include "book.h"
#include "boardgame.h"
#include "store.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
	/*Create two books*/
    Book * book1 = createBook( "Nineteen Eighty-Four", 14.95);
    Book * book2 = createBook( "Enders Game", 15.95);


     /*Create two boardgames*/
    Boardgame * game1 = createBoardgame( "Monopoly", "Hasbro", 28.99);
    Boardgame * game2 = createBoardgame( "Risk", "Hasbro", 43.99);

    
    /*Create stores to hold each item*/
    Store * storeGame1 = createStore(book1, printBook);
    Store * storeGame2 = createStore(book2, printBook);
    Store * storeBook1 = createStore(game1, printBoardgame);
    Store * storeBook2 = createStore(game2, printBoardgame);


    /*print info from the store*/
    displayStore(storeGame1);
    displayStore(storeGame2);
    displayStore(storeBook1);
    displayStore(storeBook2);
    
    
    /*free boardgames and books*/
    free(game1);
    free(game2);
    free(book1);
    free(book2);
    free(storeBook1);
    free(storeBook2);
    free(storeGame1);
    free(storeGame2);
    return 0;
}
