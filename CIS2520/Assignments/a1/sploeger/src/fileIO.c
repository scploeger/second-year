#include "fileIO.h"
#include "LinkedListAPI.h"
#include "car.h"
#include <stdio.h>
#include <stdlib.h>

/*this handles the file reading for the program
By: Spencer Ploeger
A1 - cis2520, uoguelph
October 2017
*/
void loadFile( char * filename, List *northList, List *southList, List *eastList, List *westList )
{
    FILE *file;
    file = fopen(filename, "r"); /*open a file with the filename passed as a function parameter*/
    if(file == NULL)    /*if the file cannot be found, print an error message*/
    {
        printf("ERROR - file not found!");
        exit(1);
    }
    
    char d; /*variables for reading from the file*/
    double t;
    char a;
    char line[80];
    while( fgets(line,80,file) != NULL ) /*read 80 lines from the file*/
    {
        Car * c = malloc(sizeof(Car)); /*create a temp car*/
        sscanf(line,"%c %c %lf", &d, &a, &t); /*read the line, and assign the data to the respective variables*/
        c->direcTo = d;
        c->timeArrive = t;
        c->instruction = a;
        Car * newCar = createCar(c->direcTo, c->instruction, c->timeArrive);
        if(d == 'N') /*depending on the direction of the car's travel, insert it to the back of the respective list*/
        {
        	insertBack(northList, newCar);
        }
        else if(d == 'S')
        {
        	insertBack(southList, newCar);
        }
        else if(d == 'E')
        {
        	insertBack(eastList, newCar);
        }
        else if(d == 'W')
        {
        	insertBack(westList, newCar);
        }
    }
    fclose(file); /*close the file reader*/
}