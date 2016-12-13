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

/*wordToInt
A utiliser UNIQUEMENT DANS CE CONTEXTE
INPUT word - le tableau à convertir*/
int wordToInt(char word[3])
{
/*	Exemple pour 73
	[2] => '7' 
	[1] => '3'
	[0] => 0 de base*/

	/*Il n'y a qu'un chiffre*/
	if (word[0] == 0 && word[1] == 0)
	{
		return word[2] - '0';
	}
	/*Il y a deux chiffres*/
	else if (word[0] == 0)
	{
		return 10 * (word[2] - '0') +
			1 * (word[1] - '0'); 
	}
	/*Il y a trois chiffres*/
	else
	{
		return 100 * (word[2] - '0') +
			10 * (word[1] - '0') +
			1 * (word[0] - '0');
	}

}

void readMetaData(FILE * file, int * x, int * y, int * RGB)
{
	/*Déclaration des variables*/
	char line[SIZELINE];
	/*Le premier caractère de la ligne, pour voir si c'est un commentaire*/
	char firstChar;
	int stop;

	/*Tout d'abord, il faut trouver le nombre magique*/
	stop = 0;
	while(stop != 1)
	{
		/*Si on arrive à la fin du fichier*/
		if(fgets(line, SIZELINE, file) == NULL)
		{
			puts("Erreur, fichier suivant ne possede pas de 'magic number'");
			exit(1);
		}

		/*Si la ligne commence par un P*/
		if (line[0] == 'P')
		{
			/* - '0' Convertis char vers int*/
			*RGB = line[1] - '0';
			stop  = 1;
		}
	}

	/*Ensuite, il faut lire les dimensions*/
	while(stop != 2)
	{
		/*Si on arrive à la fin du fichier*/
		if(fgets(line, SIZELINE, file) == NULL)
		{
			puts("Erreur, le fichier ne possede pas de dimensions.");
			exit(1);
		}
		
		/*On trouve la prochaine ligne qui n'est pas un commentaire*/
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

	/*On déplace la curseur pour sauter les potentiels commentaires*/
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
		}
		else
		{
			/*Nous sommes à la première ligne après les dimensions qui n'est pas un commentaire
			Il faut faire la différence entre noir et blanc et couleur
			En effet il y a une ligne de plus en couleur pour renseigner
			la valeur maximale*/
			if (*RGB == 1)
			{
				/*C'est du noir et blanc
				il s'agit directement des données
				On peut passer à la fin dès maintenant
				Il s'agit du début des données, on replace le curseur au début de la ligne*/
				
				fseek(file, -1, SEEK_CUR);
			}
			else
			{
				/*Si c'est du RGB
				La valeur maximale doit être 255
				On passe une ligne supplémentaire*/
				if(fgets(line, SIZELINE, file) == NULL)
				{
					puts("Erreur, le fichier ne possede pas de données d'image :(");
					exit(1);
				}
			}
			stop = 3;
		}
	}
}


void readPBMFromFile(FILE * file, int * color, int * imageWidth, int * imageHeight, character *** output)
{
	/*La ligne dans laquelle on écrit dans le tableau*/
	int currLine; 
	/*La colonne dans laquelle on écrit dans le tableau*/
	int currColumn;
	/*Le nombre de mots lu*/
	int bytesRead = 0;
	/*Column est la lettre actuellement testée dans line*/
	int column;
	/*L'emplacement dans lequel ajouter la nouvelle valeur dans le mot couramment lu*/
	int wordCharNumber;
	/*Sont remplis pas à pas si image en couleur*/
	int R, G, B;
	/*255 max -> 3 caractères
	word[2] -> unités
	word[1] -> dizaines
	word[0] -> centaines*/
	char word[3];

	/*Déjà, il faut être sûr d'avoir une image de dimensions non nulles*/
	if (imageWidth == NULL || imageHeight == NULL)
	{
		puts("Erreur de programmation: un pointeur est nul pour readPBMFromFile\n");
		exit(1);
	}

	/*La ligne que l'on lit dans le fichier*/
	char line[SIZELINE];

	/*Il faut malloc l'output en fonction de la taille de l'image*/
	*output = createTable(*imageWidth, *imageHeight);

	/*Tants qu'on est pas à la fin du fichier, on lit la ligne suivante	*/
	while(fgets(line, SIZELINE, file) != NULL)
	{
		/*A l'interieur de cette boucle, on lit mot à mot*/
		column = 0;
		wordCharNumber = 0;

		/*On initialise la valeur à 0*/
		word[0] = 0;
		word[1] = 0;
		word[2] = 0;

		/*Ici, on s'occuppe des lettres*/
		while(column < (strlen(line)))
		{
			/*Si le mot a été entièrement lu AKA:
			Si on rencontre un espace ou caractère de fin de ligne
			Un CRLF windows
			ET Qu'on est pas en début de ligne (éviter les lignes vides)
			ET que le caractère précédent n'est pas un espace (éviter les caractères d'espacement consécutifs)*/
			if (((line[column] == ' ' || line[column] == '\n' || line[column] == '\0')
				|| (line[column] == 13 && line[column + 1] == 10))
				&& column != 0
				&& line[column - 1] != ' ')
			{
				if(line[column] == 13 && line[column + 1] == 10)
				{
					/*On detecte bien un crlf a lavant derniere colonne
					On saute le dernier caractère LF*/
					column++;
				}
				
				bytesRead++;
				/*On recommence à écrire dans le nombre des unités*/
				wordCharNumber = 0;
				character tmp;

				if (*color == 1)
				{
					/*Si c'est noir et blanc*/
					if (word[2] == '0')
					{
						/*Si c'est blanc*/
						tmp.rgb.R = 0;
						tmp.rgb.G = 0;
						tmp.rgb.B = 0;
						tmp.c = ' ';
					}
					else
					{
						/*Si c'est noir*/
						tmp.rgb.R = 255;
						tmp.rgb.G = 255;
						tmp.rgb.B = 255;
						tmp.c = '#';
					}

					/*Ces variables correspondent à l'endroit pù l'on écrit dans le tableau*/
					currLine = (bytesRead - 1) % *imageWidth;
					currColumn = (bytesRead - 1) / *imageWidth;

					(*output)[currLine][currColumn] = tmp;
				}
				else
				{
					/*si c'est RGB
					on met à jour à chauqe byte lu, et non par groupe de 3*/
					if (bytesRead % 3 == 1)
					{
						/*Si on s'occupe du rouge*/
						R = wordToInt(word);
					}
					else if (bytesRead % 3 == 2)
					{
						/*Si on s'occupe du vert*/
						G = wordToInt(word);
					}
					else if (bytesRead % 3 == 0)
					{
						/*Si c'est du bleu*/
						B = wordToInt(word);

						tmp.rgb.R = R;
						tmp.rgb.G = G;
						tmp.rgb.B = B;
						tmp.c = '#';

						currLine = ((bytesRead - 1)/3) % *imageWidth;
						currColumn = ((bytesRead - 1)/3) / *imageWidth;

						(*output)[currLine][currColumn] = tmp;
					}
				}
				
				/*Une fois qu'on a lu un mot, on clear l'ancien mot en mémoire*/
				word[0] = 0;
				word[1] = 0;
				word[2] = 0;
			}
			else if(line[column] != ' ' && line[column] != 10 && line[column] != 13)
			{
				/*Si la lettre que l'on teste n'est pas un espace, */
				word[2 - wordCharNumber] = line[column];
				/*On écrit à la puissance de 10 supérieure*/
				wordCharNumber++;
				
				if (wordCharNumber > 3)
				{
					puts("Erreur, une valeur est supérieure à 1000.\n");
					putchar(word[0]);
					putchar(word[1]);
					putchar(word[2]);
					exit(1);
				}
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

	int x;
	int y;
	int RGB;

	x = 0;
	y = 0;
	RGB = 0;

	readMetaData(file, &x, &y, &RGB);

	output->xPos = 0;
	output->yPos = 0;
	output->xDim = x;
	output->yDim = y;

	readPBMFromFile(file, &RGB, &x, &y, &output->charArray);

	fclose(file);
}