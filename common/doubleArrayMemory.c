#include "doubleArrayMemory.h"

character ** createTable(int nbCol, int nbLin){
	/*character** theArray;
	theArray = (character**) malloc(nbCol * sizeof(character*));
	for (int i = 0; i < nbCol; i++)
	   theArray[i] = (character*) malloc(nbLin * sizeof(character));
   
    return theArray;*/
    int i;
    character ** arr = (character**)malloc(nbCol * sizeof(character*));
	character * arr_data = malloc( nbCol * nbLin * sizeof(character));
	
	for(i = 0; i<nbCol; i++)
	   arr[i] = arr_data + i * nbLin ;

	return arr;
}

void freeTable(character **array, int nbCol){
	free(*array);
	free(array);
}