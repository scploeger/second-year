#include "fileIO.h"
#include "priorityQueue.h"
#include "patient.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*this handles the file reading and writing for the program
By: Spencer Ploeger
A2 - cis2520, uoguelph
October 2017
*/
void loadFile( char * filename, List *patientListSorted, List* patientListUnsorted)
{

    FILE *file;
    file = fopen(filename, "r"); /*open a file with the filename passed as a function parameter*/
    if(file == NULL)    /*if the file cannot be found, print an error message*/
    {
        printf("ERROR - file not found!");
        exit(1);
    }
    

    char * n = malloc(100 * sizeof(char)); /*variables for reading from the file*/
    int r;
    char * s = malloc(100 * sizeof(char));
    char line[100];
    while( fgets(line,100,file) != NULL ) /*read 80 lines from the file*/
    {
        sscanf(line,"%s %d %s", n, &r, s); /*read the line, and assign the data to the respective variables*/
       Patient * newPatient = createPatient(n, r, s); /*create a temp car*/

        insertSorted(patientListSorted, newPatient);
        insertBack(patientListUnsorted, newPatient);

    }
    fclose(file); /*close the file reader*/
}

void writeFile( char * filename, List *patientList)
{

    FILE *file;
    file = fopen("./assets/output.txt", "w"); /*open a file with the filename passed as a function parameter*/
    

    char * n = malloc(100 * sizeof(char)); /*variables for reading from the file*/
    int r;
    char * s = malloc(100 * sizeof(char));
    int t;
    char outLine[100];
    char rString[10];
    char tString[10];


    

    fprintf(file, "%s\n", "Patient ID   Priority  Symptom Code  Time Out");


    Node * nextToWrite = patientList->head;
    Patient * thisPatientToWrite = nextToWrite->data;

    while(nextToWrite->next != NULL)/*loop until list is empty*/
    {
        /*set temp variables for info of each patient from the file*/
        n = thisPatientToWrite->name;
        r = thisPatientToWrite->priority;
        sprintf(rString, "%d", r);
        s = thisPatientToWrite->symptomCode;
        t = thisPatientToWrite->timeOut;
        sprintf(tString, "%d", t);

        /*format and concatenate the individual peieces of info into one string*/
        strcpy(outLine, n);
        strcat(outLine, "\t\t\t");
        strcat(outLine, rString);
        strcat(outLine, "\t");
        strcat(outLine, s);
        strcat(outLine, "\t");
        strcat(outLine, tString);

        /*write the patient info string to the file*/
        fprintf(file, "%s\n", outLine);

        nextToWrite = nextToWrite->next;
        thisPatientToWrite = nextToWrite->data;
    }

    n = thisPatientToWrite->name;
    r = thisPatientToWrite->priority;
    sprintf(rString, "%d", r);
    s = thisPatientToWrite->symptomCode;
    t = thisPatientToWrite->timeOut;
    sprintf(tString, "%d", t);

    strcpy(outLine, n);
    strcat(outLine, "\t\t\t");
    strcat(outLine, rString);
    strcat(outLine, "\t");
    strcat(outLine, s);
    strcat(outLine, "\t");
    strcat(outLine, tString);

    fprintf(file, "%s\n", outLine);

    /*close thw file*/
    fclose(file); /*close the file reader*/
}