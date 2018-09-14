/**
 * Stores item information.
 */
typedef struct store {
    void * item;
    void (*fp)(void *);
} Store;

Store* createStore( void * item, void (* funct) (void *));
void displayStore( Store * s);

