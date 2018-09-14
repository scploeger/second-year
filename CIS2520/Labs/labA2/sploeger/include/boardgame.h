/**
 * Stores boardgame information.
 */
typedef struct boardgame {
    double price;
    char *name;
    char *brandName;
} Boardgame;

Boardgame* createBoardgame( char * name, char * brandname, double price );
double getPriceBoardgame( Boardgame * b );
char* getNameBoardgame( Boardgame *b );
char* getBrandname( Boardgame *b );
void printBoardgame( void * b );
