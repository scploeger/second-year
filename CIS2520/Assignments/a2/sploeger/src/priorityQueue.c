#include "priorityQueue.h"
#include <stdlib.h>
#include <stdio.h>
#include "patient.h"

/*the content of Spencer's linked list API
(the comments describing each function can be found in the LinkedListAPI.h file)
By: Spencer Ploeger
A1 - cis2520, uoguelph
October 2017
*/

List *initializeQueue(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(void *first,void *second))
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
	itemNode->data = data;
	
	return itemNode;
	
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
		list->tail = node;
	}
}

void insertSorted(List *list, void *toBeAdded)
{
	Node * node = initializeNode(toBeAdded);
	Node * before = NULL;
	Node * after = NULL;

	if(list->head == NULL && list->tail == NULL)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{

		if(list->compare(node->data,list->head->data)==2){
			node->next = list->head;
			list->head = node;
			return;
		}

		before = list->head;
		after = list->head->next;
		while(after != NULL)
		{
			if(list->compare(node->data,after->data) == 2){
				node->next = before->next;
				before->next = node;
				return;
			}
			before = after;
			after = after->next;

		}

		list->tail->next = node;
		list->tail = node;
		return;

	}

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

void printNode(void *toBePrinted)
{

}
int compare(void *first, void *second)
{
	return 1;
}
void deleteListNode(void *toBeDeleted)
{

}
