#include "priorityQueue.h"
/**
 * @file fileIO.h
 * @author Spencer Ploeger
 * @date October 2017
 * @brief File containing the function definitions of the function to load text files
 */


/*
*@pre data should be in correct format
*@param filename - the name of the file to be read
*@param patientListSorted - a list to put the patient info in, in order sorted by priority
*@param patientListUnsorted - a list to put the patient info in, in the original order
*/
void loadFile( char * filename, List *patientListSorted, List* patientListUnsorted);

/*
*@pre data should be in correct format
*@param filename - the name of the file to be written to
*@param patientList - the list containing the patients in original, unsorted order
*/
void writeFile( char * filename, List *patientList);