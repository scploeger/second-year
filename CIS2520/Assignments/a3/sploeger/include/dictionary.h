#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashTableAPI.h"

int hashFunction(char* toHash);
void printNode(void *toBePrinted);
void deleteNode(void *data);