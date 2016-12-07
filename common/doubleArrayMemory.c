#include "doubleArrayMemory.h"

character **createTable(int nbLin, int nbCol){
	scharacter **array = (character **)malloc(sizeof(character*) * nbLin); //On malloc une ligne de tableaux de characters
	character *array2 = (character *)malloc(sizeof(character) * nbCol * nbLin); // on malloc la 'surface' du tableau 2D
	for(int i = 0 ; i < nbLin ; i++){
		array[i] = &array2[i * nbCol]; 
		//Pour chaque ligne, on file un tableau simple. 
		//C'est simple, on remplit juste le tableau qu'on a eu avec le premier malloc avec les colonnes du deuxieme malloc
	}
	return array;
}
 
void freeTable(int **array, int nbLin){
	int i;
	for (i = 0; i < nbLin; ++i)
	{
		free(array[i]);
	}
	free(array);
}