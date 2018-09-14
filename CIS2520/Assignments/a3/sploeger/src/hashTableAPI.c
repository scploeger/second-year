/**
 * @file HashTableAPI.h
 * @author Michael Ellis
 * @date February 2017
 * @brief File containing the function definitions of a hash table
 */


#include <stdio.h>
#include <stdlib.h>
#include "hashTableAPI.h"
 #include "dictionary.h"


/**Function to point the hash table to the appropriate functions. Allocates memory to the struct and table based on the size given.
*@return pointer to the hash table
*@param size size of the hash table
*@param hashFunction function pointer to a function to hash the data
*@param destroyData function pointer to a function to delete a single piece of data from the hash table
*@param printNode function pointer to a function that prints out a data element of the table
**/
HTable *createTable(size_t size, int (*hashFunction)(char* toHash),void (*destroyData)(void *data),void (*printNode)(void *toBePrinted))
{
	HTable * newTable = malloc(sizeof(HTable));

	if(newTable != NULL)
	{
		newTable->size = size;
		newTable->table = malloc(sizeof(Node*)*size);
		newTable->hashFunction = hashFunction;
		newTable->destroyData = destroyData;
		newTable->printNode = printNode;
	}
	return newTable;
}

/**Function for creating a node for the hash table.
*@pre Node must be cast to void pointer before being added.
*@post Node is valid and able to be added to the hash table
*@param key integer that represents the data (eg 35->"hello")
*@param data is a generic pointer to any data type.
*@return returns a node for the hash table
**/
Node *createNode(char* key, void *data)
{
	Node * newNode = malloc(sizeof(Node));
	newNode->key = key;
	newNode->data = data;
	newNode->next = NULL;

	return newNode;

}

/** Deletes the entire hash table and frees memory of every element.
*@pre Hash Table must exist.
*@param hashTable pointer to hash table containing elements of data
**/
void destroyTable(HTable *hashTable)
{
	int x = 0;
	if(hashTable == NULL)
	{
		printf("List does not exist\n");
		return;
	}

	for(x = 0; x < hashTable->size; x++)
	{
		if(hashTable->table[x] == NULL)
 		{
			free(hashTable->table[x]);
		}
		else
		{	Node * curNode = hashTable->table[x];
			Node * tempNode;

			while(curNode->next != NULL)
			{
				tempNode = curNode->next;
				curNode = NULL;
				free(curNode);
				curNode = tempNode;

			}
			free(hashTable->table[x]);
		}
	}


	hashTable = NULL;
	free(hashTable);
}

/**Inserts a Node in the hash table.
*@pre hashTable type must exist and have data allocated to it
*@param hashTable pointer to the hash table
*@param key integer that represents the data (eg 35->"hello")
*@param data pointer to generic data that is to be inserted into the list
**/
void insertData(HTable *hashTable, char* key, void *data)
{
	if(lookupData(hashTable, data) != NULL)
	{
		printf("Word already exists in dictionary!\n");
		return;
	}
		int index = hashFunction(key);

		if(hashTable->table[index] == NULL)
		{
			hashTable->table[index] = createNode(key, data);
		}
		else
		{
			Node * tempNode = hashTable->table[index];
			while(tempNode != NULL)
			{
				if(tempNode->next == NULL)
				{
					break;
				}
				tempNode = tempNode->next;
			}
			
			Node * newNode = createNode(key, data);

			tempNode->next = newNode;
	}
}

/** THIS FUNCTION IS NOT MANDATORY, users call this function to insert a Node in the hash table.
* It's meant as a wrapper for insertData so the users don't need to generate the key when adding.
*@pre hashTable type must exist and have data allocated to it
*@param hashTable pointer to the hash table
*@param data pointer to generic data that is to be inserted into the list
**/
void insertDataInMap(HTable *hashTable, void *data)
{
	insertData(hashTable, data, data);
}

/**Function to remove a node from the hash table 
 *@pre Hash table must exist and have memory allocated to it
 *@post Node at key will be removed from the hash table if it exists.
 *@param hashTable pointer to the hash table struct
 *@param key integer that represents a piece of data in the table (eg 35->"hello")
 **/
 void removeData(HTable *hashTable, char* key)
 {
 	if(lookupData(hashTable, key) == NULL)
 		{
 			printf("This word does not exist in the dictionary!\n");
 			return;
 		}
 	int index = hashFunction(key);
 	Node * tempNode = hashTable->table[index];
 	if(hashTable->table[index] == NULL)
 	{
 		/*printf("Nothing at that index to delete\n");*/
 		printf("Word deleted sucessfully!\n");
 		return;
 	}
 	else if(tempNode != NULL && tempNode->next == NULL)
 	{
 		deleteNode(tempNode);
 		free(hashTable->table[index]);
 		hashTable->table[index] = NULL;
 		/*printf("deleted from a node where it was the only entry at the index\n");*/
 		printf("Word deleted sucessfully!\n");
 		return;
 	}
 	else if(tempNode != NULL && tempNode->next != NULL && strcmp(tempNode->data, key) == 0)
 	{
 		Node * newHead = tempNode->next;
 		deleteNode(tempNode);
 		free(hashTable->table[index]);
 		hashTable->table[index] = NULL;
 		hashTable->table[index] = newHead;
 		printf("Word deleted sucessfully!\n");
 		/*printf("deleted from a node where the one after it exists and has to be the new head\n");*/
 		return;
 	}
 	else if(tempNode != NULL && tempNode->next != NULL && strcmp(tempNode->data, key) != 0) /*if it is in the middle or does not exist*/
 	{
 		Node * thisNode = tempNode;
 		Node* prevNode;
 		while(tempNode->next != NULL)
 		{
 			
 			if(strcmp(key, thisNode->key) == 0)
 			{
 				if(thisNode->next == NULL)
 				{
 					deleteNode(thisNode);
 					prevNode->next = NULL;
 					printf("Word deleted sucessfully!\n");
 					/*printf("found a thing at the end of list index\n");*/
 					return;
 				}

 				prevNode->next = thisNode->next;
 				deleteNode(thisNode);
 				printf("Word deleted sucessfully!\n");
 				/*printf("found a thing to deelete in the middle of a table index\n");*/
 				return;
 			}
 			prevNode = thisNode;
 			thisNode = thisNode->next;
 		} 		
 	}
 }

/**Function to return the data from the key given.
 *@pre The hash table exists and has memory allocated to it
 *@param hashTable pointer to the hash table containing data nodes
 *@param key integer that represents a piece of data in the table (eg 35->"hello")
 *@return returns a pointer to the data in the hash table. Returns NULL if no match is found.
 **/
 void *lookupData(HTable *hashTable, char* key)
 {

 	if(hashTable == NULL)
 	{
 		printf("Table was empty!\n");
 		return NULL;
	}
	else
	{

 	Node * tempNode = hashTable->table[hashFunction(key)];
 	while(tempNode != NULL)
 	{
 		if(strcmp(tempNode->key, key) == 0)
 		{
 			return tempNode->data;
 		}
 		tempNode = tempNode->next;
 	}
 	}
 	return NULL;
 }


 int hashNode(char* toBeHashed)
 {
 	return 1;
 }

 void destroyNodeData(void *data)
 {

 }

 void printNodeData(void *toBePrinted)
 {

 }
