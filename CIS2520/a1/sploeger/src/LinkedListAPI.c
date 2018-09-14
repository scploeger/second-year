#include "LinkedListAPI.h"
#include <stdlib.h>
#include <stdio.h>

/*the content of Spencer's linked list API
(the comments describing each function can be found in the LinkedListAPI.h file)
By: Spencer Ploeger
A1 - cis2520, uoguelph
October 2017
*/

List *initializeList(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second))
{
	List * itemList = malloc(sizeof(List));
	itemList->head = NULL;
	itemList->tail = NULL;
	
	itemList->printNode = printFunction;
	itemList->compare = compareFunction;
	itemList->deleteNode = deleteFunction;
	
	return itemList;
}

Node *initializeNode(void *data)
{
	Node * itemNode = malloc(sizeof(Node));
	itemNode->next = NULL;
	itemNode->previous = NULL;
	itemNode->data = data;
	
	return itemNode;
	
}

void insertFront(List *list, void *toBeAdded)
{	
	Node * node = initializeNode(toBeAdded);
	
	if(list->head == NULL)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		list->head->previous = node;
		node->next = list->head;
		list->head = node;
	}
}

void insertBack(List *list, void *toBeAdded)
{	
	Node * node = initializeNode(toBeAdded);
	
	if(list->tail == NULL)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		list->tail->next = node;
		node->previous = list->tail;
		list->tail = node;
	}
}

void insertSorted(List *list, void *toBeAdded)
{

}

void deleteList(List *list)
{
	Node * current = list->head;
	Node * next = NULL;
	
	if(list->head==NULL)
	{
		printf("No List Found to Delete!\n");
	}
	else{
		while(current != NULL)
		{
			next = current->next;
			list->deleteNode(current);
			current = next;
		}
		free(list);
	}
}

int deleteNodeFromList(List *list, void *toBeDeleted)
{
	return 0;
}

void *getFromFront(List *list)
{
	return list->head->data;
}

void *getFromBack(List *list)
{
	return list->tail->data;
}

void printForward(List *list)
{
	Node * current = list->head;
	Node * next = NULL;
	
	if(list->head==NULL)
	{
		printf("No List Found to Print Forward!\n");
	}
	else{

		while(current != NULL)
		{
			next = current->next;
			list->printNode(current->data);
			current = next;
		}
	}
}
void printBackwards(List *list)
{
	Node * current = list->tail;
	Node * previous = NULL;

	if(list->head==NULL)
	{
		printf("No List Found to Print Backwards!\n");
	}
	else{
	
		while(current != NULL)
		{
			previous = current->previous;
			list->printNode(current->data);
			current = previous;
		}
	}
}

void printNode(void *toBePrinted)
{

}
int compare(const void *first,const void *second)
{
	return 1;
}
void deleteListNode(void *toBeDeleted)
{

}
