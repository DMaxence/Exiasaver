#include "doubleArrayMemory.h"

character **createTable(int nbLin, int nbCol){
	character** theArray;
	theArray = (character**) malloc(nbCol*sizeof(character*));
	for (int i = 0; i < nbCol; i++)
	   theArray[i] = (character*) malloc(nbLin*sizeof(character));
   
    return theArray;
}
void freeTable(character **array, int nbCol){
	int i;
	for (i = 0; i < nbCol; ++i)
	{
		free(array[i]);
	}
	free(array);
}