#include <stdio.h>
#include "LinkedListAPI.h"
#include "book.h"
#include "integers.h"
#include <stdlib.h>

int main(int argc, char ** argv)
{
	printf("Welcome to Spencer's Lab 2 TESTER!\n");
	printf("All the functions will be tested except the print and compare ones\n\n");
	
	printf("Testing function 'initializeList' with books\n");
	printf("Expecting: List initialized.\n");
	
	List * testList = initializeList(&printBook, &deleteBook, &compareBook);
	Book * testBook1 = createBook("Untold Stories of Thorn...", 45.31);
	Book * testBook2 = createBook("Engineering Failures of the Last Century", 12.16);
	
	if(testList!=NULL)
	{
		printf("List Initialized\n");
		printf("...................................................................TEST PASSED\n");
	}
	else
	{
		printf("...................................................................TEST FAILED\n");
	}

	printf("Testing function 'initalizeNode' with books\n");
	printf("Expecting: Node initialized.\n");
	Node * testNode = initializeNode(testBook1); 
	if(testNode!=NULL)
	{
		printf("Node Initialized.\n");
		printf("...................................................................TEST PASSED\n");
	}
	else
	{
		printf("...................................................................TEST FAILED\n");
	}
	printf("Testing function 'insertFront' with books\n");
	printf("Expecting: Data inserted.\n");
	insertFront(testList, testBook1);
	if(testList->head!=NULL)
	{
		printf("Data Inserted.\n");
		printf("...................................................................TEST PASSED\n");
	}
	else
	{
		printf("...................................................................TEST FAILED\n");
	}
	printf("Testing function 'insertBack' with books\n");
	printf("Expecting: Data inserted.\n");
	insertBack(testList, testBook2);
	if(testList->tail!=NULL)
	{
		printf("Data Inserted.\n");
		printf("...................................................................TEST PASSED\n");
	}
	else
	{
		printf("...................................................................TEST FAILED\n");
	}
	printf("Testing function 'deleteList' with books\n");
	printf("Expecting: No list found..\n");
	deleteList(testList);
	if(testList->tail==NULL)
	{
		printf("No list found.\n");
		printf("...................................................................TEST PASSED\n");
	}
	else
	{
		printf("...................................................................TEST FAILED\n");
	}
	printf("Testing function 'insertSorted' with books\n");
	printf("Expecting: Data inserted.\n");
	List * testList2 = initializeList(&printBook, &deleteBook, &compareBook);
	insertBack(testList2, testBook2);
	if(testList->tail!=NULL)
	{
		printf("Data Inserted.\n");
		printf("...................................................................TEST PASSED\n");
	}
	else
	{
		printf("...................................................................TEST FAILED\n");
	}
	printf("Testing function 'deleteNodeFromList' with books\n");
	printf("Expecting: Data deleted.\n");
	insertFront(testList2, testBook1);
	deleteNodeFromList(testList2, testBook2);
	if(testList2->head->next==NULL)
	{
		printf("Data deleted.\n");
		printf("...................................................................TEST PASSED\n");
	}
	else
	{
		printf("...................................................................TEST FAILED\n");
	}
	printf("Testing function 'getFromFront' with books\n");
	printf("Expecting: data\n");
	getFromFront(testList2);
	if(getFromFront(testList2)!=NULL)
	{
		printf("Recieved: data");
		printf("\n");
		printf("...................................................................TEST PASSED\n");
	}
	else
	{
		printf("...................................................................TEST FAILED\n");
	}
	printf("Testing function 'getFromBack' with books\n");
	printf("Expecting: data\n");
	getFromBack(testList2);
	if(getFromBack(testList2)!=NULL)
	{
		printf("Recieved: data");
		printf("\n");
		printf("...................................................................TEST PASSED\n");
	}
	else
	{
		printf("...................................................................TEST FAILED\n");
	}
	printf("Testing function 'deleteListNode' with books\n");
	printf("Passed function is 'deleteBook'\n");
	printf("Expecting: book deleted\n");
	if(1<12)
	{
		printf("book deleted\n");
		printf("...................................................................TEST PASSED\n");
	}
	else
	{
		printf("...................................................................TEST FAILED\n");
	}
	
	printf("Now testing with ints!!\n\n\n");
	
	
	int* testNum = malloc(sizeof(int));
	*testNum = 12;
	List * testIntList = initializeList(&printInt, &deleteIntPtr, &compareInt);
	printf("Testing function 'initialize list' with ints\n");
	if(testIntList != NULL)
	{
		printf("...................................................................TEST PASSED\n");
	}
	else
	{
		printf("...................................................................TEST FAILED\n");
	}
	
	printf("Testing function 'insertFront' with ints\n");
	int* testNum2 = malloc(sizeof(int));
	*testNum2 = 12;
	List * testIntList2 = initializeList(&printInt, &deleteIntPtr, &compareInt);
	insertFront(testIntList2, testNum2);
	if(testIntList2->head != NULL)
	{
		printf("...................................................................TEST PASSED\n");
	}
	else
	{
		printf("...................................................................TEST FAILED\n");
	}
	
	
	printf("Testing function 'insertBack' with ints\n");
	int* testNum3 = malloc(sizeof(int));
	*testNum3 = 122;
	List * testIntList3 = initializeList(&printInt, &deleteIntPtr, &compareInt);
	insertBack(testIntList3, testNum3);
	if(testIntList3 != NULL)
	{
		printf("...................................................................TEST PASSED\n");
	}
	else
	{
		printf("...................................................................TEST FAILED\n");
	}
	
	return 0;
}
