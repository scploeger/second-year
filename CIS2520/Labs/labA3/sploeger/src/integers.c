#include "integers.h"
#include <stdio.h>
#include <stdlib.h>

/*Int functions*/


/**
 * A function to get the print the int
 * 
 * @param an int
 * 
 * @return void
 * */
void printInt( void * x )
{
	int v = *((int *)x);
	printf("%d\n", v);
}


void deleteIntPtr(void * toBeDeleted)
{
	int* b = (int*)toBeDeleted;
	free(b);
}

int compareInt(const void* first, const void* second)
{
	int int1 = *((int*)first);
	int int2 = *((int*)second);
	
	return(int1 - int2);
}
