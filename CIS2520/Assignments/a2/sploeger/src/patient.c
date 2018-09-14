#include "patient.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Patient functions*/
/**
 * A function to create a new patient
 * 
 * @param name
 * @param priority
 * @param symptom code
 * 
 * @return a new patient
 * */
Patient* createPatient( char * name, int priority, char * symptomCode )
{
	Patient* p = malloc(sizeof(Patient));
    p->name  = malloc(sizeof(char) * strlen(name)-1);
    strcpy(p->name, name);
    p->priority = priority;
    p->symptomCode = malloc(sizeof(char) * strlen(name)-1);
    strcpy(p->symptomCode, symptomCode);
    p->timeOut = -1;
    return p;
}

/**
 * A function to get the priority of a patient
 * 
 * @param a patient
 * 
 * @return priority of a patient
 * */
int getPriority( Patient * p )
{
	return p->priority;
}

/**
 * A function to print the name of a patient
 * 
 * @param a patient
 * 
 * @return name of a patient
 * @return the priority of the patient
 * @return the symptom code of the patient
 * */
void printPatient( void * p )
{
	printf("%-18s	%d	%s		%d	\n", getName(p), getPriority(p), getSymptom(p), getTimeOut(p) );
}

/**
 * A function to get the timeOut of a patient
 * 
 * @param a patient
 * 
 * @return timeOut of a patient
 * */
int getTimeOut( Patient * p )

{
	return p->timeOut;
}

/**
 * A function to get the name of a patient
 * 
 * @param a patient
 * @return the name of a patient
 * */
char* getName( Patient *p )
{
	return p->name;
}

/**
 * A function to get the name of a symptom
 * 
 * @param a patient
 * @return the patient code of the patient
 * */
char* getSymptom( Patient *p )
{
	return p->symptomCode;
}

/*
 *deletes a patient
 * */
void deletePatient(void* toBeDeleted)
{
	Patient* p = (Patient*)toBeDeleted;
	free(p);
}

/*
 * @param two patients
 * @return the difference in priority numbers of each patient
 * */
int comparePatient(void* first, void* second)
{
	Patient* p1 = first;
	Patient* p2 = second;
	
	if(p1->priority >= p2->priority)
	{
		return 1;
	}
	else if(p1->priority < p2->priority)
	{
		return 2;
	}
	return 1;
}

