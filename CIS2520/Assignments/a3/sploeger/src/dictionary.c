#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashTableAPI.h"
#include <ctype.h>


/**Hashes a given alphabetic key
*@pre key must be alphabetic
*@param the key
*@return the inex
**/
int hashFunction(char* toHash)
{
	int firstLetter = toHash[0];
	int lastLetter = toHash[strlen(toHash)-1];
	int key = firstLetter + lastLetter;
	key = key - 130;
	return key;
}

/**prints void datac
*@param data to be printed
**/
void printNode(void *toBePrinted)
{
	char* printThis = (char*)toBePrinted;
	printf("%s", printThis);
}

/**deletes and frees a data
*@param data
**/
void deleteNode(void *data)
{
	Node* deleteThis = (Node*)data;
	deleteThis->data = NULL;
	deleteThis->key = NULL;
	deleteThis->next = NULL;
}