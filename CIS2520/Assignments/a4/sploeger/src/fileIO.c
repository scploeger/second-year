#include "fileIO.h"
#include "dictionary.h"
#include "hashTableAPI.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*this handles the file reading and writing for the program
By: Spencer Ploeger
A2 - cis2520, uoguelph
October 2017
*/
void loadDict( char* filename, HTable* thisTable)
{

    FILE *file;
    file = fopen(filename, "r"); /*open a file with the filename passed as a function parameter*/
    if(file == NULL)    /*if the file cannot be found, print an error message*/
    {
        printf("ERROR - file not found!  Check the filename passed on command line!\n");
        exit(1);
    }
    

  
    while(!feof(file)) /*until end of file is reached*/
    {
        char * w = malloc(100 * sizeof(char)); /*malloc space for a line of text*/
        fscanf(file, "%s\n", w); /*read data from file*/
        insertData(thisTable, w, w);/*insert the data to the table*/

    }
    fclose(file); /*close the file reader*/
}

/*load in the user data and compare it against the dicitonary*/
void loadUsr( char* filename, HTable* thisTable, char* name)
{

    /*variables counting the number of matches and non matched words*/
	int correctWords = 0;
	int incorrectWords = 0;
	FILE *file;
    
    file = fopen(filename, "r"); /*open a file with the filename passed as a function parameter*/
    
    if(file == NULL)    /*if the file cannot be found, print an error message*/
    {
        printf("ERROR - file not found!\n");
        return;
    }
  
  	printf("\n\n");
  	printf("File processed by spellcheck: %s\n", name);

    while(!feof(file)) /*until end of file is reached*/
    {
        char * w = malloc(100 * sizeof(char)); /*variables for reading from the file*/
        fscanf(file, "%s\n", w); /*read the line, and assign the data to the respective variables*/
        if(lookupData(thisTable, w) == NULL) /*if the read in word is not in the ditionary*/
        {
        	printf("'%s' was not found in the dictionary\n\n", w);
        	incorrectWords++;
        }
        else
        {
        	correctWords++;
        }

    }
    /*print the summary of words found*/

    printf("\n...\n\n");

    printf("Summary:\n\n");
    printf("Correctly spelt words: %d\n\n", correctWords);
    printf("Incorrectly spelt words: %d\n\n", incorrectWords);
   

    fclose(file); /*close the file reader*/

}