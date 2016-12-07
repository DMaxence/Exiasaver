/* ************************************************************************** */
/*                                                                            */
/*                    	                                     	              */
/*   readPBM.h		                        __        __ __          	      */
/*                                         |     \  /   |       /\            */
/*   By: Groupe 2                          |__    \/    |      /  \           */
/*			       		                   |      /\    |     /____\          */
/*   				        			   |__   /  \ __|__  /      \         */
/*							   					          		              */
/*                                                                            */
/* ************************************************************************** */

#include "readPBM.h"

#define SIZELINE 255

int readMetaData(char[] fileName, int * x, int * y, int * RGB)
{
	FILE* file = fopen(fileName, "r");
	char line[SIZELINE];
	int stop = 0;
	
	//We check if the the file is successfully opened
	if(file == NULL)
	{
		puts("Erreur, le fichier suivant n'a pas pu être ouvert:");
		puts(fileName);
		exit(1);
	}

	//We read each line. We have to make sure we read data in the right order

	//First we have to find the magic number
	while(stop == 1)
	{
		if(fgets(line, SIZELINE, file) == NULL)
		{
			puts("Erreur, le fichier suivant ne possede pas de 'magic number':");
			puts(fileName);
			exit(1);
		}

		//We just wait for a line that starts with P
		if (line[0] == 'P')
		{
			*RGB = line[1] - '0'; //Converts char to int
			stop  = 1;
		}
	}
}


int readPBM(char[] fileName, int * imageWidth, int * imageHeight, char ** output[])
{

}