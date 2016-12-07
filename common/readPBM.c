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

void readMetaData(FILE * file, int ** x, int ** y, int ** RGB)
{
	//First, we have to make sure pointers are set to NULL;
	if (*x != NULL || *y != NULL ||  *RGB != NULL)
	{
		puts("Erreur de programmation: un pointeur n'est pas nul pour readMetaData\n");
		exit(1);
	}
	
	
	char line[SIZELINE];
	int stop = 0;

	//We read each line. We have to make sure we read data in the right order

	//First we have to find the magic number
	while(stop != 1)
	{
		if(fgets(line, SIZELINE, file) == NULL)
		{
			puts("Erreur, fichier suivant ne possede pas de 'magic number'");
			exit(1);
		}

		//We just wait for a line that starts with P
		if (line[0] == 'P')
		{
			*RGB = malloc(sizeof(char));
			**RGB = line[1] - '0'; //Converts char to int
			stop  = 1;
		}
	}


	//Then we have to get the dimensions
	while(stop != 2)
	{
		if(fgets(line, SIZELINE, file) == NULL)
		{
			puts("Erreur, le fichier ne possede pas de dimensions.");
			exit(1);
		}

		//We have to get the next line after the magic number that's not a commment
		if (line[0] != '#')
		{
			*x = malloc(sizeof(int));
			*y = malloc(sizeof(int));
			**x = 0;
			**y = 0;

			sscanf(line, "%d %d", *x, *y);

			if (*x == 0 || *y == 0)
			{
				puts("Erreur, les paramètres de taille de l'image doivent être sur la même ligne.");
				exit(1);
			}

			stop  = 2;
		}
	}
}


void readPBM(FILE * file, int * color, int * imageWidth, int * imageHeight, char ** output[])
{
	//First, we have to make sure pointers are set to NULL;
	if (imageWidth == NULL || imageHeight == NULL)
	{
		puts("Erreur de programmation: un pointeur est nul pour readPBM\n");
		exit(1);
	}

	char line[SIZELINE];

	//on doit prendre les valeurs par groupe de 1 ou 3 en fonction de la couleur.

	//Tants qu'on est pas à la fin du fichier
	while(fgets(line, SIZELINE, file) != NULL)
	{
		
	}
}