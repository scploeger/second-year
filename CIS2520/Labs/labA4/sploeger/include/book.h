/**
 * Stores basic book information.
 */
typedef struct book {
    double price;
    char *name;
} Book;

Book* createBook( char * title, double price );
double getPrice( Book * b );
char* getName( Book *b );
void printBook( void * b );
void deleteBook(void*toBeDeleted);
int compareBook(const void* first, const void* second);

