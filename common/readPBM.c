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


void readPBMFromFile(FILE * file, int * color, int * imageWidth, int * imageHeight, character *** output)
{
	int currLine; 
	int currColumn;

	//First, we have to make sure pointers are set to NULL;
	if (imageWidth == NULL || imageHeight == NULL)
	{
		puts("Erreur de programmation: un pointeur est nul pour readPBMFromFile\n");
		exit(1);
	}

	char line[SIZELINE];

	//Il faut malloc l'output en fonction de la taille de l'image
	*output = createTable(*imageWidth, *imageHeight);


	//Tants qu'on est pas à la fin du fichier, on lit la ligne suivante	
	while(fgets(line, SIZELINE, file) != NULL)
	{
		//A l'interieur de cette boucle, on lit mot à mot
		int column = 0;
		int bytesRead = 0;
		int R, G, B; //Sont remplis pas à pas si image en couleur

		char word[3]; //255 max -> 3 caractères

		//Ici, on s'occuppe des lettres
		while(column < strlen(line))
		{
			if (line[column] == ' ')
			{
				bytesRead++;
				if (*color == 1) //Si c'est noir et blanc
				{
					character tmp;
					if (word[0] == '0') //Si c'est blanc
					{
						tmp.rgb.R = 255;
						tmp.rgb.G = 255;
						tmp.rgb.B = 255;
					}
					else //Si c'est noir
					{
						tmp.rgb.R = 0;
						tmp.rgb.G = 0;
						tmp.rgb.B = 0;
					}

					currLine = (bytesRead - 1) % *imageWidth;
					currColumn = bytesRead / *imageWidth;
					//printf("%d\n", currLine);
					//printf("%d\n", currColumn);

					(*output)[currLine][currColumn] = tmp;
				}
				else //si c'est RGB
				{
					int tmp100 = word[0] - '0';
					int tmp10 = word[1] - '0';
					int tmp1 = word[2] - '0';

					if (bytesRead % 3 == 1) // Si on s'occupe du rouge
					{
						R = 100 * tmp100 + 10 * tmp10 + tmp1; //On a converti les trois caractères du mot en int
					}
					else if (bytesRead % 3 == 2) // Si on s'occupe du vert
					{
						G = 100 * tmp100 + 10 * tmp10 + tmp1; //On a converti les trois caractères du mot en int
					}
					else if (bytesRead % 3 == 0)
					{
						B = 100 * tmp100 + 10 * tmp10 + tmp1; //On a converti les trois caractères du mot en int

						character tmp;
						tmp.rgb.R = R;
						tmp.rgb.G = G;
						tmp.rgb.B = B;

						*output[bytesRead % *imageWidth][(int)bytesRead / *imageWidth] = tmp;
					}
				}
				
				//Une fois qu'on a lu un mot, on clear l'ancien mot en mémoire
				word[0] = '0';
				word[1] = '0';
				word[2] = '0';
				printf("DEBUG %d\n", bytesRead);
			}
			else
			{
				word[column] = line[column];
			}
			column++;
		}
	}
}

void readPBM(char fileName[], character *** output)
{
	FILE * file = fopen(fileName, "r");
	int *x = NULL;
	int *y = NULL;
	int *RGB = NULL;

	readMetaData(file, &x, &y, &RGB);
	readPBMFromFile(file, RGB, x, y, output);

	fclose(file);
}