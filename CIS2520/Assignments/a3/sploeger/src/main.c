#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashTableAPI.h"
#include "fileIO.h"
#include "dictionary.h"


/*
main for a3 - cis2500, UOGuelph
By: Spencer Ploeger
	October 2017
*/

	int main(int argc, char ** argv)
	{
		char menuChoice[10];
		char userWord[100];

		HTable *thisTable = createTable(115, &hashFunction, &printNode, &deleteNode);
		loadDict(argv[1], thisTable);

		while(strcmp(menuChoice, "5") != 0)
		{
			printf("Please enter a menu choice (only press the number then press enter!):\n");
			printf("1. Add a word to your dictionary\n");
			printf("2. Remove a word from your dictionary\n");
			printf("3. Spell check a file\n");
			printf("4. See the contents of your dictironary\n");
			printf("5. Quit\n");

			fgets(menuChoice, 10, stdin);
			strtok(menuChoice, "\n");




			if(strcmp(menuChoice, "1") == 0)
			{
				printf("Enter the word to add to your dicitonary and press enter:\n");
				fgets(userWord, 100, stdin);
				strtok(userWord, "\n");

				if(lookupData(thisTable, userWord) == NULL)
				{
					printf("Word added successfully!\n");
				}
				insertDataInMap(thisTable, userWord);
			}

			if(strcmp(menuChoice, "2") == 0)
			{
				printf("Enter the word to be removed:\n");
				fgets(userWord, 100, stdin);
				strtok(userWord, "\n");

				removeData(thisTable, userWord);
			}


			if(strcmp(menuChoice, "3") == 0)
			{
				char bef[20];
				strcpy(bef, "./assets/");

				printf("Enter the JUST THE NAME including the file extension of the file to be searched:\n");
				printf("ex: type 'fileName.txt'\n");
				printf("file must be in assets folder, and be a .txt file\n");
				printf("./assets/");
				fgets(userWord, 100, stdin);
				strtok(userWord, "\n");

				strcat(bef, userWord);

				loadUsr(bef, thisTable, userWord);

			}


			if(strcmp(menuChoice, "4") == 0)
			{
				printf("INDEX	KEY			DATA\n\n");
				int x=0;
				for(x = 0; x < 115; x++)
				{
					if(thisTable->table[x] != NULL)
					{
						Node * tempNode = thisTable->table[x];
						while(tempNode != NULL)
						{
							printf("%d:%s:%s\n", x, (char*)tempNode->data, (char*)tempNode->data);
							tempNode=tempNode->next;
						}
					}
				}
			}


		}
		
		destroyTable(thisTable);
		printf("Goodbye!!\n");

		return 0;
	}


