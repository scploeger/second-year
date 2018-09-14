#include "car.h"
#include <stdio.h>
#include <stdlib.h>


/*the content of Spencer's car.h file
(the comments describing each function can be found in the car.h file)
By: Spencer Ploeger
A1 - cis2520, uoguelph
October 2017
*/
Car* createCar( char dir, char action, double time )
{
	Car* c = malloc(sizeof(Car));
    c->direcTo  = dir;
    c->instruction = action;
    c->timeArrive = time;
    c->timeFront = -1;
    c->timeOut = -1;
    return c;
}

char getDirecTo(Car * c)
{
	return c -> direcTo;
}

void printCar(void * c)
{
	printf("%c %c %.2lf				%.2lf				%.2lf\n", getDirecTo(c), getInstruction(c), getTimeArrive(c), getTimeFront(c), getTimeOut(c) );
}


char getInstruction(Car * c)
{
	return c->instruction;
}
double getTimeArrive(Car * c)
{
	return c->timeArrive;
}
double getTimeOut(Car * c)
{
	return c->timeOut;
}
double getTimeFront(Car * c)
{
	return c->timeFront;
}

void deleteCar(void* toBeDeleted)
{
	Car* c = (Car*)toBeDeleted;
	free(c);
}

int compareCar(const void* first, const void* second)
{
	Car * car1 = (Car*)first;
	Car * car2 = (Car*)second;

	return(car1->timeArrive-car2->timeArrive);
}
