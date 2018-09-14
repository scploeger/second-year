#include <stdio.h>
#include <stdlib.h>
#include "priorityQueue.h"
#include "patient.h"
/*
Tester file for a2 - cis2500, UOGuelph
By: Spencer Ploeger
	October 2017
*/


/*the testion functions for the program.  The print statements are descriptive enough
so no comments will be provided*/
	int main(int argc, char ** argv)
	{
		printf("Testion function: initializeQueue\n");
		printf("Expecting: Queue to be Initialized\n");
		List * testQueue = initializeQueue(&printPatient, &deletePatient, &comparePatient);
		if(testQueue != NULL)
		{
			printf("Result: Queue initialized successfully\n");
			printf("....................................................TEST PASSED\n");
		}
		else
		{
			printf("Result: Queue not initialized\n");
			printf("....................................................TEST FAILED\n");
		}



		printf("Testion function: initializeNode\n");
		printf("Expecting: Node to be Initialized\n");
		Node * testNode = initializeNode("test data");
		insertBack(testQueue, testNode);
		if(testNode != NULL)
		{
			printf("Result: Node initialized successfully\n");
			printf("....................................................TEST PASSED\n");
		}
		else
		{
			printf("Result: Node not initialized\n");
			printf("....................................................TEST FAILED\n");
		}


		printf("Testion function: deleteList with a list that already exists\n");
		printf("Expecting: if list exisits, list to be deleted and set to null\nif list does not exist, print error messsage\n");
		deleteList(testQueue);
		if(testQueue->head == NULL)
		{
			printf("Result: List deleted successfully\n");
			printf("....................................................TEST PASSED\n");
		}
		else
		{
			printf("Result: List not deleted\n");
			printf("....................................................TEST FAILED\n");
		}

		printf("Testion function: deleteList with a list that does not exist\n");
		printf("Expecting: if list exisits, list to be deleted and set to null\nif list does not exist, print error messsage\n");
		deleteList(testQueue);

		if(testQueue->head == NULL){
			printf("....................................................TEST PASSED\n");
		}
		else
		{
			printf("....................................................TEST FAILED\n");
		}




		Patient* patient1 = createPatient("TestPatient1", 5, "MH");
		Patient* patient2 = createPatient("TestPatient2", 4, "GI");
		Patient* patient3 = createPatient("TestPatient3", 2, "TR");
		List* patientQueue = initializeQueue(&printPatient, &deletePatient, &comparePatient);
		insertSorted(patientQueue, patient1);
		insertSorted(patientQueue, patient2);
		insertSorted(patientQueue, patient3);

		printf("Testion function: insertSorted with patients with non ordereded priorities\n");
		printf("Expecting: Queue's head's priority to be higher than the tails\n");
		if(comparePatient(patientQueue->head->data, patientQueue->tail->data) == 2){
			printf("Head had a higher priority than tail.\n");
			printf("....................................................TEST PASSED\n");
		}
		else
		{
			printf("Head did not have a higher priority than tail.\n");
			printf("....................................................TEST FAILED\n");
		}





		Patient* patient4 = createPatient("TestPatient4", 1, "MH");
		insertBack(patientQueue, patient4);

		printf("Testing function: insertBack with a patient with highest priority out of the rest of the patients in the list\n");
		printf("Expecting: Queue's head's priority to be lower than the tails (since a top priority patient was inserted in the back)\n");
		if(comparePatient(patientQueue->head->data, patientQueue->tail->data) == 1){
			printf("Tail had a higher priority than head.\n");
			printf("....................................................TEST PASSED\n");
		}
		else
		{
			printf("tail did not have a higher priority than head.\n");
			printf("....................................................TEST FAILED\n");
		}







		printf("Testing function: printForward with a previously initialized list\n");
		printf("Expecting: The list to be printed forward\n");
		if(1 == 1){
			printForward(patientQueue);
			printf("....................................................TEST PASSED\n");
		}
		else
		{
			printf("Could not print list\n");
			printf("....................................................TEST FAILED\n");
		}




		printf("Testing function: getFromFront with a previously initialized list\n");
		printf("Expecting: The front node to hava data\n");
		if(getFromFront(patientQueue) != NULL){
			printf("Data was found at the front of the list\n");
			printf("....................................................TEST PASSED\n");
		}
		else
		{
			printf("No data found at the front of the list\n");
			printf("....................................................TEST FAILED\n");
		}



		printf("Testing function: getFromBack with a previously initialized list\n");
		printf("Expecting: The back node to hava data\n");
		if(getFromBack(patientQueue) != NULL){
			printf("Data was found at the back of the list\n");
			printf("....................................................TEST PASSED\n");
		}
		else
		{
			printf("No data found at the back of the list\n");
			printf("....................................................TEST FAILED\n");
		}

		return 0;
	}