	#include <stdio.h>
	#include <stdlib.h>
	#include "LinkedListAPI.h"
	#include "car.h"
	#include "fileIO.h"
/*
main for a1 - cis2500, UOGuelph
By: Spencer Ploeger
	October 2017
*/


int main(int argc, char ** argv)
{
	/*create 4 lists of cars, one for eadh direction, and pass the three
	user definerd car functions*/
	List * carListN = initializeList(&printCar, &deleteCar, &compareCar);
	List * carListS = initializeList(&printCar, &deleteCar, &compareCar);
	List * carListE = initializeList(&printCar, &deleteCar, &compareCar);
	List * carListW = initializeList(&printCar, &deleteCar, &compareCar);

	/*call the loqd file function, and pass the name of the file,
	and the four lists to it*/
	loadFile(argv[1], carListN, carListS, carListE, carListW);

	/*Create temp nodes to hold the next car in line for each direction, and 
	initialize them to the head of the list of every car per direction*/
	Node * nodeN = carListN->head;
	Node * nodeS = carListS->head;
	Node * nodeE = carListE->head;
	Node * nodeW = carListW->head;

	/*initialize 4 temporary cars which will act as placeholders in each list.
	Set their data to the data pointed to by the prviously declared nodes*/
	Car * tempCarN = nodeN->data;
	Car * tempCarE = nodeE->data;
	Car * tempCarS = nodeS->data;
	Car * tempCarW = nodeW->data;


		/*master timer for the entire intersection*/
	double masterTimer = 1;

		/*light timer for each light phase*/
	double lightTimer = 1;

		/*master char for the status of the current forward
		direction*/
	char currentDirection = 'N';

	
		/*the printing formatted title for the car infomarion that will 
		be printed in the body of this program*/
		printf("Initial Vehicle Information     Intersection Arrival Time         Completed at Time\n");


	/*for the main do-while loop, only the code for one direction will be
	commented, as the code for the other three directions is identical, with 
	the direction variables changed appropriately*/
	do
	{
		if(currentDirection == 'N') /*if it is the turn for nortbound vehicles to go*/
		{
			if(nodeN == NULL || lightTimer > 13) /*if the list is not empty, and the light is yellow or green*/
			{	
				currentDirection = 'E'; /*else, change the direction to east, and add 14 seconds for the light cycle if the list is empty*/
				lightTimer = 1;

				if(nodeN == NULL)
				{
					masterTimer += 14;				
				}
			}
			else
			{
				if(masterTimer < tempCarN->timeArrive || lightTimer > 11) /*if the next car has not arrived at the interection, but there is still time for a car to go,
																			then add time, a half second at a time until either the light cycle ends or a car reaches the 
																			intersection*/
				{
					lightTimer += 0.5;
					masterTimer += 0.5;
				}
				else	/*otherwise, if a car is at the intersection..*/
				{
					if(tempCarN->instruction == 'L' && lightTimer <= 11) /*if the car is turning left
																			and there is time for a left 
																			turn*/
					{
						tempCarN->timeFront = masterTimer; /*update the ligttimer, mastertimer, and timeOut of the car*/
						lightTimer += 2.5;
						masterTimer += 2.5;
						tempCarN->timeOut = masterTimer;

						printCar(tempCarN);	/*print the car's info*/

						if(nodeN->next	!=	NULL) /*if there is a next car in the list, update the temp node and car*/
						{
							nodeN = nodeN->next;
							tempCarN = nodeN->data;
						}
						else /*otherwise, the list's end has been reached
								so set the node to null, so it is skipped
								over the next loops*/
						{
							nodeN = NULL;
						}

					}
					if(tempCarN->instruction == 'R' && lightTimer <= 10) /*if the insturction is right, and there is time for a right turn*/
					{													/*the rest of the code follows as above*/
						tempCarN->timeFront = masterTimer;
						lightTimer += 1;
						masterTimer += 1;
						tempCarN->timeOut = masterTimer;

						printCar(tempCarN);

						if(nodeN->next	!=	NULL)
						{
							nodeN = nodeN->next;
							tempCarN = nodeN->data;
						}
						else
						{
							nodeN = NULL;
						}

					}
					if(tempCarN->instruction == 'F' && lightTimer <= 10) /*if the instruction is forward, and there is time to go forward*/
					{													/*rest of code is the same as above*/
						tempCarN->timeFront = masterTimer;
						lightTimer += 2;
						masterTimer += 2;
						tempCarN->timeOut = masterTimer;

						printCar(tempCarN);

						if(nodeN->next	!=	NULL)
						{
							nodeN = nodeN->next;
							tempCarN = nodeN->data;
						}
						else
						{
							nodeN = NULL;
						}

					}
				}
			}


		}



		if(currentDirection == 'E')
		{
			if(nodeE == NULL || lightTimer > 13)
			{
				currentDirection = 'S';
				lightTimer = 1;

				if(nodeE == NULL)
				{
					masterTimer += 14;				
				}
			}
			else
			{
				if(masterTimer < tempCarE->timeArrive || lightTimer > 11)
				{
					lightTimer += 0.5;
					masterTimer += 0.5;
				}
				else
				{
					if(tempCarE->instruction == 'L' && lightTimer <= 11)
					{
						tempCarE->timeFront = masterTimer;
						lightTimer += 2.5;
						masterTimer += 2.5;
						tempCarE->timeOut = masterTimer;

						printCar(tempCarE);

						if(nodeE->next	!=	NULL)
						{
							nodeE = nodeE->next;
							tempCarE = nodeE->data;
						}
						else
						{
							nodeE = NULL;
						}
					}
					if(tempCarE->instruction == 'R' && lightTimer <= 9)
					{
						tempCarE->timeFront = masterTimer;
						lightTimer += 1;
						masterTimer += 1;
						tempCarE->timeOut = masterTimer;

						printCar(tempCarE);


						if(nodeE->next	!=	NULL)
						{
							nodeE = nodeE->next;
							tempCarE = nodeE->data;
						}
						else
						{
							nodeE = NULL;
						}

					}
					if(tempCarE->instruction == 'F' && lightTimer <= 8)
					{
						tempCarE->timeFront = masterTimer;
						lightTimer += 2;
						masterTimer += 2;
						tempCarE->timeOut = masterTimer;

						printCar(tempCarE);

						if(nodeE->next	!=	NULL)
						{
							nodeE = nodeE->next;
							tempCarE = nodeE->data;
						}
						else
						{
							nodeE = NULL;
						}
					}
				}
			}
		}





		if(currentDirection == 'S')
		{
			if(nodeS == NULL || lightTimer > 13)
			{
				currentDirection = 'W';
				lightTimer = 1;

				if(nodeS == NULL)
				{
					masterTimer += 14;				
				}
			}
			else
			{
				if(masterTimer < tempCarS->timeArrive || lightTimer > 11)
				{
					lightTimer += 0.5;
					masterTimer += 0.5;
				}
				else
				{
					if(tempCarS->instruction == 'L' && lightTimer <= 11)
					{
						tempCarS->timeFront = masterTimer;
						lightTimer += 2.5;
						masterTimer += 2.5;
						tempCarS->timeOut = masterTimer;

						printCar(tempCarS);

						if(nodeS->next	!=	NULL)
						{
							nodeS = nodeS->next;
							tempCarS = nodeS->data;
						}
						else
						{
							nodeS = NULL;
						}
					}
					if(tempCarS->instruction == 'R' && lightTimer <= 9)
					{
						tempCarS->timeFront = masterTimer;
						lightTimer += 1;
						masterTimer += 1;
						tempCarS->timeOut = masterTimer;

						printCar(tempCarS);


						if(nodeS->next	!=	NULL)
						{
							nodeS = nodeS->next;
							tempCarS = nodeS->data;
						}
						else
						{
							nodeS = NULL;
						}

					}
					if(tempCarS->instruction == 'F' && lightTimer <= 8)
					{
						tempCarS->timeFront = masterTimer;
						lightTimer += 2;
						masterTimer += 2;
						tempCarS->timeOut = masterTimer;

						printCar(tempCarS);

						if(nodeS->next	!=	NULL)
						{
							nodeS = nodeS->next;
							tempCarS = nodeS->data;
						}
						else
						{
							nodeS = NULL;
						}
					}
				}
			}
		}




		if(currentDirection == 'W')
		{
			if(nodeW == NULL || lightTimer > 13)
			{
				currentDirection = 'N';
				lightTimer = 1;

				if(nodeW == NULL)
				{
					masterTimer += 14;				
				}
			}
			else
			{
				if(masterTimer < tempCarW->timeArrive || lightTimer > 11)
				{
					lightTimer += 0.5;
					masterTimer += 0.5;
				}
				else
				{
					if(tempCarW->instruction == 'L' && lightTimer <= 11)
					{
						tempCarW->timeFront = masterTimer;
						lightTimer += 2.5;
						masterTimer += 2.5;
						tempCarW->timeOut = masterTimer;

						printCar(tempCarW);

						if(nodeW->next	!=	NULL)
						{
							nodeW = nodeW->next;
							tempCarW = nodeW->data;
						}
						else
						{
							nodeW = NULL;
						}
					}
					if(tempCarW->instruction == 'R' && lightTimer <= 9)
					{
						tempCarW->timeFront = masterTimer;
						lightTimer += 1;
						masterTimer += 1;
						tempCarW->timeOut = masterTimer;

						printCar(tempCarW);


						if(nodeW->next	!=	NULL)
						{
							nodeW = nodeW->next;
							tempCarW = nodeW->data;
						}
						else
						{
							nodeW = NULL;
						}

					}
					if(tempCarW->instruction == 'F' && lightTimer <= 8)
					{
						tempCarW->timeFront = masterTimer;
						lightTimer += 2;
						masterTimer += 2;
						tempCarW->timeOut = masterTimer;

						printCar(tempCarW);

						if(nodeW->next	!=	NULL)
						{
							nodeW = nodeW->next;
							tempCarW = nodeW->data;
						}
						else
						{
							nodeW = NULL;
						}
					}
				}
			}
		}





	}while (nodeE != NULL || nodeN != NULL || nodeS != NULL || nodeW != NULL); /*while there is still at least one car left in one list*/

	return 0;
}


