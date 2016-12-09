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

void readMetaData(FILE * file, int * x, int * y, int * RGB)
{
	
	char line[SIZELINE];
	char firstChar; //Le premier caractère de la ligne, pour voir si c'est un commentaire
	int stop = 0;

	int dbgLine = 1; //ligne courante (debug)

	//We read each line. We have to make sure we read data in the right order

	//First we have to find the magic number
	while(stop != 1)
	{
		if(fgets(line, SIZELINE, file) == NULL)
		{
			puts("Erreur, fichier suivant ne possede pas de 'magic number'");
			exit(1);
		}

		dbgLine++;

		//We just wait for a line that starts with P
		if (line[0] == 'P')
		{
			*RGB = line[1] - '0'; //Converts char to int
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
		dbgLine++;
		//We have to get the next line after the magic number that's not a commment
		if (line[0] != '#')
		{
			*x = 0;
			*y = 0;

			sscanf(line, "%d %d", x, y);

			if (*x == 0 || *y == 0)
			{
				puts("Erreur, les paramètres de taille de l'image doivent être sur la même ligne.");
				exit(1);
			}

			stop  = 2;
		}
	}

	//On déplace la curseur pour sauter les potentiels commentaires
	while(stop != 3)
	{
		firstChar = fgetc(file);

		if (firstChar == '#')
		{
			//on a trouvé un commentaire, on saute une ligne
			if(fgets(line, SIZELINE, file) == NULL)
			{
				puts("Erreur, le fichier ne possede pas de données d'image.");
				exit(1);
			}
			dbgLine++;
			//puts("Une ligne de comm trouvee apres les dimensiosn");
		}
		else //Nous sommes à la première ligne après les dimensions qui n'est pas un commentaire
		{
			//Il faut faire la différence entre noir et blanc et couleur
			//En effet il y a une ligne de plus en couleur pour renseigner
			//la valeur maximale
			if (*RGB == 1) //Si on est en noir et blanc
			{
				//il s'agit directement des données
				//On peut passer à la fin dès maintenant
				//Il s'agit du début des données, on replace le curseur au début de la ligne
				fseek(file, -1, SEEK_CUR);
			}
			else //Si c'est du RGB
			{
				//La valeur maximale doit être 255
				//On passe une ligne supplémentaire
				if(fgets(line, SIZELINE, file) == NULL)
				{
					puts("Erreur, le fichier ne possede pas de données d'image :(");
					exit(1);
				}
				dbgLine++;
			}
			stop = 3;
		}
	}
	//printf("DBG ligne debut de donnees: %d\n", dbgLine);
}


void readPBMFromFile(FILE * file, int * color, int * imageWidth, int * imageHeight, character *** output)
{
	//La ligne dans laquelle on écrit dans le tableau
	int currLine; 
	//La colonne dans laquelle on écrit dans le tableau
	int currColumn;
	//Le nombre de mots lu
	int bytesRead = 0;

	//First, we have to make sure pointers are set to NULL;
	if (imageWidth == NULL || imageHeight == NULL)
	{
		puts("Erreur de programmation: un pointeur est nul pour readPBMFromFile\n");
		exit(1);
	}

	//La ligne que l'on lit dans le fichier
	char line[SIZELINE];

	//Il faut malloc l'output en fonction de la taille de l'image
	//*output = createTable(*imageWidth, *imageHeight);
	*output = createTable(*imageHeight, *imageWidth);

	//Tants qu'on est pas à la fin du fichier, on lit la ligne suivante	
	while(fgets(line, SIZELINE, file) != NULL)
	{
		//A l'interieur de cette boucle, on lit mot à mot
		int column = 0; //Column est la lettre actuellement testée dans line
		int wordCharNumber = 0; //L'emplacement dans lequel ajouter la nouvelle valeur dans le mot couramment lu
		int R, G, B; //Sont remplis pas à pas si image en couleur

		char word[3]; //255 max -> 3 caractères
		// word[2] -> unités
		// word[1] -> dizaines
		// word[0] -> centaines
		//On initialise la valeur à 0
		word[0] = '0';
		word[1] = '0';
		word[2] = '0';

		//Ici, on s'occuppe des lettres
		while(column < (strlen(line)))
		{
			//printf("Caractere traite >%c< (code ascii: %d), colonne %d/%d\n", line[column], (int) line[column], column, strlen(line));

			//Si le mot a été entièrement lu
			if (((line[column] == ' ' || line[column] == '\n' || line[column] == '\0') //Si on rencontre un espace ou caractère de fin de ligne
				|| (line[column] == 13 && line[column + 1] == 10)) // Un CRLF windows
				&& column != 0 // ET Qu'on est pas en début de ligne (éviter les lignes vides)
				&& line[column - 1] != ' ') // ET que le caractère précédent n'est pas un espace (éviter les caractères d'espacement consécutifs)
			{
				if(line[column] == 13 && line[column + 1] == 10)
				{
					//puts("CRLF rencontre!"); //On detecte bien un crlf a lavant derniere colonne
					column++; //On saute le dernier caractère LF
				}
				
				bytesRead++;
				wordCharNumber = 0; //On recommence à écrire dans le nombre des unités
				character tmp;

				if (*color == 1) //Si c'est noir et blanc
				{
					if (word[2] == '0') //Si c'est blanc
					{
						tmp.rgb.R = 0;
						tmp.rgb.G = 0;
						tmp.rgb.B = 0;
						tmp.c = ' ';
					}
					else //Si c'est noir
					{
						tmp.rgb.R = 255;
						tmp.rgb.G = 255;
						tmp.rgb.B = 255;
						tmp.c = '#';
						//tmp.c = '█'; //pour le lol
					}

					//Ces variables correspondent à l'endroit pù l'on écrit dans le tableau
					currLine = (bytesRead - 1) % *imageWidth;
					currColumn = (bytesRead - 1) / *imageWidth;

					//printf("word contains %c%c%c\n", word[0], word[1], word[2]);
					//printf("writing to : %d %d value %c - colonne %d\n", currLine, currColumn, word[2], column);

					(*output)[currLine][currColumn] = tmp;
					//printf("%c", (*output)[currLine][currColumn].c); // marche
				}
				else //si c'est RGB
				{
					//on met à jour à chauqe byte lu, et non par groupe de 3
					if (bytesRead % 3 == 1) // Si on s'occupe du rouge
					{
						R = 100 * (word[2] - '0') + 10 * (word[1] - '0') + (word[0] - '0'); //On a converti les trois caractères du mot en int
					}
					else if (bytesRead % 3 == 2) // Si on s'occupe du vert
					{
						G = 100 * (word[2] - '0') + 10 * (word[1] - '0') + (word[0] - '0'); //On a converti les trois caractères du mot en int
					}
					else if (bytesRead % 3 == 0)
					{
						B = 100 * (word[2] - '0') + 10 * (word[1] - '0') + (word[0] - '0'); //On a converti les trois caractères du mot en int

						tmp.rgb.R = R;
						tmp.rgb.G = G;
						tmp.rgb.B = B;
						tmp.c = '#';

						currLine = ((bytesRead - 1)/3) % *imageWidth;
						currColumn = ((bytesRead - 1)/3) / *imageWidth;

						//printf("Caractere a inserer a %d : %d - R%d G%d B%d char:%c\n", currLine, currColumn, tmp.rgb.R, tmp.rgb.G, tmp.rgb.B, tmp.c);

						(*output)[currLine][currColumn] = tmp;
					}
				}
				
				//Une fois qu'on a lu un mot, on clear l'ancien mot en mémoire
				word[0] = '0';
				word[1] = '0';
				word[2] = '0';
				
				//puts("word reset a 0");
			}
			else if(line[column] != ' ' && line[column] != 10 && line[column] != 13)//Si la lettre que l'on teste n'est pas un espace, 
			{
				word[2 - wordCharNumber] = line[column];
				//printf("Ajout a la place %d du caractère %c\n", 2 - wordCharNumber, line[column]);
				wordCharNumber++;//On écrit à la puissance de 10 supérieure
				
				if (wordCharNumber > 3)
				{
					puts("Erreur, une valeur est supérieure à 1000.\n");
					putchar(word[0]);
					putchar(word[1]);
					putchar(word[2]);
					exit(1);
				}

				//printf("else w%c\n", word[column]);
				//printf("else l%c\n", word[column]);
				//printf("else len%d\n", ((int)strlen(line)) - endLineChars);

			}
			else
			{
				//puts("DEBUG: plusieurs espaces consecutifs ecartes\n");
			}
			column++;
		}
	}
}

void readPBM(char fileName[], image * output)
{
	FILE * file = fopen(fileName, "r");

	if (file == NULL)
	{
		puts("Erreur, impossible d'ouvrir le fichier:");
		puts(fileName);
		exit(1);
	}

	//TODO check si bien ouvert

	int x = 0;
	int y = 0;
	int RGB = 0;

	readMetaData(file, &x, &y, &RGB);

	output->xPos = 0;
	output->yPos = 0;
	output->xDim = x;
	output->yDim = y;

	readPBMFromFile(file, &RGB, &x, &y, &output->charArray);

	//printf("Last chars: %c %c %c\n", output->charArray[0][0].c, output->charArray[1][0].c, output->charArray[2][0].c);
	//printf("Last chars: %c %c %c\n", output->charArray[0][1].c, output->charArray[1][1].c, output->charArray[2][1].c);

	fclose(file);
}