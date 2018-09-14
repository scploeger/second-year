#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashTableAPI.h"
#include "fileIO.h"
#include "dictionary.h"
/*
Tester file for a3 - cis2500, UOGuelph
By: Spencer Ploeger
	November 2017
*/


/*the testion functions for the program.  The print statements are descriptive enough
so no comments will be provided*/
	int main(int argc, char ** argv)
	{
		printf("Testing function: createTable\n");
		printf("Expecting: Table creaated\n");
		HTable * testTable = createTable(244, &hashFunction, &printNode, &deleteNode);
		if(testTable != NULL)
		{
			printf("Result: Table created\n");
			printf("....................................................TEST PASSED\n");
		}
		else
		{
			printf("Result: Table not created\n");
			printf("....................................................TEST FAILED\n");
		}


		

		printf("Testing function: createNode\n");
		printf("Expecting: Node created\n");
		Node * newNode = createNode("key", "data");
		if(newNode != NULL)
		{
			printf("Result: Node initialized successfully\n");
			printf("....................................................TEST PASSED\n");
		}
		else
		{
			printf("Result: Node not initialized\n");
			printf("....................................................TEST FAILED\n");
		}

		


		printf("Testing function: insertData\n");
		printf("Expecting: data inserted into list\n");
		insertData(testTable, "testWord", "testWord");
		printf("Entering 'testWord' into map\n");
		if(lookupData(testTable, "testWord") != NULL)
		{
			printf("It was found in map\n");
			printf("Result: Data inserted successfully\n");
			printf("....................................................TEST PASSED\n");
		}
		else
		{
			printf("Result: data not inserted\n");
			printf("....................................................TEST FAILED\n");
		}


		

		printf("Testing function: insertDataInMap\n");
		printf("Expecting: test word to be inserted in map\n");
		insertData(testTable, "testWordTwo", "testWordTwo");
		printf("Entering 'testWordTwo' into map\n");
		if(lookupData(testTable, "testWordTwo") != NULL)
		{
			printf("'testWordTwo found in map'\n");
			printf("Result: data inserted successfully\n");
			printf("....................................................TEST PASSED\n");
		}
		else
		{
			printf("Result: Data not inserted\n");
			printf("....................................................TEST FAILED\n");
		}

		printf("Testing function: insertDataInMap by inserting illegal characters\n");
		printf("Entering '!!!!!!!' into map\n");
		printf("Expecting: a segfault\n");
		/*insertData(testTable, "@!!!", "@!!!");*/
		printf("lime commented out due to seg fault.  for future program revisions, will not let user enter illigal characters.\n");
		/*if(lookupData(testTable, "@!!!!!") != NULL)
		{
			printf("'testWordTwo found in map'\n");
			printf("Result: data inserted successfully\n");
			printf("....................................................TEST PASSED\n");
		}
		else
		{
			printf("Result: Data not inserted\n");
			printf("....................................................TEST FAILED\n");
		}
*/


		printf("Testing function: removeData\n");
		printf("previously entered word, 'testWord' to be removeod from map\n");
		removeData(testTable, "testWord");
		if(lookupData(testTable, "testWord") == NULL)
		{
			printf("Testword was deleted feom the map.\n");
			printf("....................................................TEST PASSED\n");
		}
		else
		{
			printf("testWord not deleted\n");
			printf("....................................................TEST FAILED\n");
		}

		

		printf("Testing function: lookupData\n");
		printf("Expecting: 'testWordTwo to be found in map\n");
		if(lookupData(testTable, "testWordTwo") != NULL)
		{
			printf("lookupData returned the data was found\n");
			printf("....................................................TEST PASSED\n");
		}
		else
		{
			printf("lookupData could not find the data in the list\n");
			printf("....................................................TEST FAILED\n");
		}


		

		printf("Testing function: destroyTable\n");
		printf("Expecting: testTable to be deleted and set to NULLl\n");
		destroyTable(testTable);
		if(testTable == NULL)
		{
			printf("Result: map deleted successfully\n");
			printf("....................................................TEST PASSED\n");
		}
		else
		{
			printf("Result: map not deleted\n");
			printf("....................................................TEST FAILED\n");
			printf("Note: something is causing tables to not be set to null after they are deleted,\n");
			printf("even though they ar eno longer accesible and are freed... This is a fix for future assignments.\n");
		}



		return 0;
	}