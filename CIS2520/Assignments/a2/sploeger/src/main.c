	#include <stdio.h>
	#include <stdlib.h>
	#include "priorityQueue.h"
	#include "fileIO.h"
	#include "patient.h"
	#include <string.h>
/*
main for a2 - cis2500, UOGuelph
By: Spencer Ploeger
	October 2017
*/


	int main(int argc, char ** argv)
	{
		int checkSymptomCode( char* code );

		char n[100];
		char sc[100];
		int p = 0;
		char pString[10];
		char cont[100] = "1";
	/*create 4 lists of cars, one for eadh direction, and pass the three
	user definerd car functions*/
		List * patientListSorted = initializeQueue(&printPatient, &deletePatient, &comparePatient);
		List * patientListUnsorted = initializeQueue(&printPatient, &deletePatient, &comparePatient);



	/*call the loqd file function, and pass the name of the file,
	and the four lists to it*/
		loadFile(argv[1], patientListSorted, patientListUnsorted);

		while (strcmp(cont, "3") != 0){ //runs loop until valid input recieved
			printf("Welcome to Spencer's Hospital Simulator\n*****************************\n");

			/*the menu options*/
			printf("Press 1 to add more patients to the list.\n");
			printf("Press 2 to run the simulation and then exit.\n");
			printf("Press 3 to exit the program (and NOT run the simulation)\n");
			fgets(cont, 100, stdin); /*take input, and delete the null terminator*/
			cont[strcspn(cont, "\n")] =0;

			/*if the user decides to add a patient to the list*/			
			if(strcmp(cont, "1") == 0)
			{
				/*prompt for all patient data and save to temporary variables*/
				printf("Enter the patient's name and press enter:\n");
				fgets(n, 100, stdin);
				n[strcspn(n, "\n")] =0;
				printf("Enter the patient's priority number (1-5) and press enter:\n");
				fgets(pString, 100, stdin);
				pString[strcspn(pString, "\n")] =0;
				p = atoi(pString);
				printf("Enter the patient's symptom code and press enter:\n");
				fgets(sc, 100, stdin);
				sc[strcspn(sc, "\n")] =0;

				/*create a new patient with the user inputted data*/
				Patient * newPt = createPatient(n, p, sc); /*create a temp car*/
				
				/*insert the new patient into the sorted and unsorted lists*/
				/*an unsorted list allows the patient list to be reprinted in original order*/
				insertSorted(patientListSorted, newPt);
				insertBack(patientListUnsorted, newPt);
			}
			else if(strcmp(cont, "2") == 0) /*if the user wants to run the simulation*/
			{
				/*create a master timer variable*/
				int timer = 0;
				/*create a temp node and patient to cycle through the list*/
				Node * nextInList = patientListSorted->head;
				Patient * thisPatient = nextInList->data;

				while(nextInList->next != NULL)/*loop until list is empty*/
				{
					/*add time for the respective symptom (call symptom code function)*/
					timer += checkSymptomCode(thisPatient->symptomCode);
					thisPatient->timeOut = timer; /*update the time out*/
					nextInList = nextInList->next; /*advance to the next in the list*/
					thisPatient = nextInList->data;
					timer ++;
				}
			timer++;
			timer += checkSymptomCode(thisPatient->symptomCode); //get the last member of the list
			thisPatient->timeOut = timer;

		/*print the output for the user*/
		printf("Here is the patient list in original order:\n" );
		printf("(It also has been written to the file)\n" );
		printf("Patient ID         Priortiy  Symptom Code   Time Finished\n"); /*print the format and titel for the top of the list*/
		printForward(patientListUnsorted);

		printf("Press any key and then enter to exit\n");
		char dummyString[100];
		fgets(dummyString, 100, stdin);

		/*overwrite the old data with new data*/
		writeFile(argv[1], patientListUnsorted);

		break;
	}
	else if(strcmp(cont, "3") == 0)
	{
		break;
	}
	else
	{
		printf("Invalid menu input. Please only enter numbers 1, 2, or 3.\n\n");
	}
}


return 0;
}


/*
*@pre data should be in correct format
*@param code - the symptom code
*@return - the time required to deal with each symptom
*/
int checkSymptomCode( char* code )
{
	if(strcmp(code, "CV") == 0)
	{
		return 5;
	}
	else if(strcmp(code, "HN") == 0)
	{
		return 3;
	}
	else if(strcmp(code, "EV") == 0)
	{
		return 10;
	}
	else if(strcmp(code, "GI") == 0)
	{
		return 2;
	}
	else if(strcmp(code, "MH") == 0)
	{
		return 5;
	}
	else if(strcmp(code, "NC") == 0)
	{
		return 5;
	}
	else if(strcmp(code, "RC") == 0)
	{
		return 1;
	}
	else if(strcmp(code, "SK") == 0)
	{
		return 2;
	}
	else if(strcmp(code, "SA") == 0)
	{
		return 7;
	}
	else if(strcmp(code, "TR") == 0)
	{
		return 4;
	}
	return 1;
}


