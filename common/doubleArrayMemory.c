#include "doubleArrayMemory.h"

character **createTable(int nbLin, int nbCol){

	character** theArray;
	theArray = (character**) malloc(nbCol*sizeof(character*));
	for (int i = 0; i < nbCol; i++)
	   theArray[i] = (character*) malloc(nbLin*sizeof(character));
   
    return theArray;
}
void freeTable(int **array, int nbLin){
	/*int i;
	for (i = 0; i < nbLin; ++i)
	{
		free(array[i]);
	}
	free(array);*/
}