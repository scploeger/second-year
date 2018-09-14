#include <stdio.h>
#include <stdlib.h>
#include "LinkedListAPI.h"
#include "car.h"
/*
Tester file for a1 - cis2500, UOGuelph
By: Spencer Ploeger
	October 2017
*/


/*the testion functions for the program.  The print statements are descriptive enough
so no comments will be provided*/
int main(int argc, char ** argv)
{
	
	printf("Testing function 'initializeList' by sending it print, delete, and compare functions for car\n");
	printf("Expecting: List initialized.\n");
	
	List * testList1 = initializeList(&printCar, &deleteCar, &compareCar);
	
	if(testList1!=NULL)
	{
		printf("List Initialized!\n");
		printf("...................................................................TEST PASSED\n");
	}
	else
	{
		printf("List was null...\n");
		printf("...................................................................TEST FAILED\n");
	}

	printf("Testing function 'initializeNode' by sending it Car data\n");
	printf("Expecting: Node initialized!.\n");
	
	Car* testCar1 = createCar( 'N', 'L', 12.5 );
	Node * testNode1 = initializeNode(testCar1);
	
	if(testNode1!=NULL)
	{
		printf("Node Initialized!\n");
		printf("...................................................................TEST PASSED\n");
	}
	else
	{
		printf("Node was null...\n");
		printf("...................................................................TEST FAILED\n");
	}


	printf("Testing function 'insertFront' by sending it Car data and list of cars\n");
	printf("Expecting: Car data inserted to be at front of list.\n");
	
	Car* testCar2 = createCar( 'E', 'R', 4 );
	Car* testCar3 = createCar( 'S', 'R', 15 );
	List * testList2 = initializeList(&printCar, &deleteCar, &compareCar);
	insertFront(testList2, testCar2);
	insertBack(testList2, testCar3);
	
	if(testList2->head != NULL)
	{
		printf("Car data was found at the front of the list\n");
		printf("...................................................................TEST PASSED\n");
	}
	else
	{
		printf("Front of the list was null...\n");
		printf("...................................................................TEST FAILED\n");
	}

	printf("Testing function 'insertBack' by sending it Car data and list of cars\n");
	printf("Expecting: Car data inserted to be at back of list.\n");
	
	if(testList2->tail != NULL)
	{
		printf("Car data was found at the back of the list\n");
		printf("...................................................................TEST PASSED\n");
	}
	else
	{
		printf("Back of the list was null...\n");
		printf("...................................................................TEST FAILED\n");
	}

	printf("Testing function 'getFromFront' by sending it the previously created list\n");
	printf("Expecting: the data to be found at the front of the list\n");

	if(getFromFront(testList2) != NULL)
	{
		printf("Data was found at the front of the list!\n");
		printf("...................................................................TEST PASSED\n");
	}
	else
	{
		printf("No data was found at the front of the list!\n");
		printf("...................................................................TEST FAILED\n");
	}

	printf("Testing function 'getFromBack' by sending it the previously created list\n");
	printf("Expecting: the data to be found at the back of the list\n");

	if(getFromBack(testList2) != NULL)
	{
		printf("Data was found at the back of the list!\n");
		printf("...................................................................TEST PASSED\n");
	}
	else
	{
		printf("No data was found at the back of the list!\n");
		printf("...................................................................TEST FAILED\n");
	}

	printf("Testing function 'printForward' by sending it the previously created list\n");
	printf("Expecting: list to be printed forward\n");

	if(testList2 != NULL)
	{
		printForward(testList2);
		printf("...................................................................TEST PASSED\n");
	}
	else
	{
		printForward(testList2);
		printf("...................................................................TEST FAILED\n");
	}

	printf("Testing function 'printBackward' by sending it the previously created list\n");
	printf("Expecting: list to be printed backwards\n");

	if(testList2 != NULL)
	{
		printBackwards(testList2);
		printf("...................................................................TEST PASSED\n");
	}
	else
	{
		printBackwards(testList2);
		printf("...................................................................TEST FAILED\n");
	}

	printf("Testing function 'deleteList' by sending it the previously created list\n");
	printf("Expecting: no list found to be printed\n");
	deleteList(testList2);

	if(testList2->head == NULL)
	{
		printForward(testList2);
		printf("...................................................................TEST PASSED\n");
	}
	else
	{
		printForward(testList2);
		printf("...................................................................TEST FAILED\n");
	}


	

	return 0;
}
