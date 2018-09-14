/**
 * @file patient.h
 * @author Spencer Ploeger
 * @date October 2017
 * @brief File containing the function definitions for car.c and definition of the car struct
 */


/**
 * Stores basic car information.
 */
typedef struct patient {
    char* symptomCode;
    char* name;
    int priority;
    int timeOut;
} Patient;

#include <stdio.h>
#include <stdlib.h>


Patient* createPatient( char * name, int priority, char * symptomCode );


/**
 * A function to get the priority of a patient
 * 
 * @param a patient
 * 
 * @return priority of a patient
 * */
int getPriority( Patient * p );

/**
 * A function to get the timeOut of a patient
 * 
 * @param a patient
 * 
 * @return timeOut of a patient
 * */
int getTimeOut( Patient * p );


/**
 * A function to print the name of a patient
 * 
 * @param a patient
 * 
 * @return name of a patient
 * @return the priority of the patient
 * @return the symptom code of the patient
 * */
void printPatient( void * p );


/**
 * A function to get the name of a patient
 * 
 * @param a patient
 * @return the name of a patient
 * */
char* getName( Patient *p );


/**
 * A function to get the name of a symptom
 * 
 * @param a patient
 * @return the patient code of the patient
 * */
char* getSymptom( Patient *p );

/*
 *deletes a patient
 * */
void deletePatient(void* toBeDeleted);


/*
 * @param two patients
 * @return the difference in priority numbers of each patient
 * */
int comparePatient(void* first, void* second);

