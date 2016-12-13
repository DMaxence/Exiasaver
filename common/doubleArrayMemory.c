#include "doubleArrayMemory.h"

character ** createTable(int nbCol, int nbLin){
    int i;
    character ** arr;
	character * arr_data;
	
	/*On malloc un tableau de tableau*/
	arr = (character**)malloc(nbCol * sizeof(character*));

	/*On malloc tout l'espace nécessaire pour mettre les valeurs*/
	arr_data = malloc( nbCol * nbLin * sizeof(character));

	/*On assigne au tableau une portion de mémoire qui lui sera propre*/
	for(i = 0; i<nbCol; i++)
	   arr[i] = arr_data + i * nbLin ;

	return arr;
}

void freeTable(character **array, int nbCol){
	free(*array);
	free(array);
}