/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                          __       __ __	          */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/09 17:33:00 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/13 12:42:46 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "../common/struct_image.h"	
#include "../common/printImage.h"
#include "../common/readPBM.h"
#include "../common/createUniformImage.h"
#include "../common/mergeImages.h"
#include "../common/deleteImage.h"
#include "../common/centerImage.h"
#include "../common/stringToImage.h"

int		main(int argc, char *argv[])
{
	//ETAPE 0: Déclarer les variables
	int numberWidth;
	int numberHeight;

	image numbers[11]; //Ce tableau va contenir les images
	image * termBackground;
	image * textUpdateImage;
	char *imgPath;
	int i;

	//Les variables contenant l'index des 
	int h0;
	int h1;
	int m0;
	int m1;
	int s0;
	int s1;

	numberHeight = 0;
	numberWidth = 0;


	//ETAPE 1: Vérifier que les arguments donnés sont bons et les stocker dans des variables

	//Si aucun argument n'est donné
	if (argc == 1)
	{
		printf("Veuillez donner le repertoire contenant les images des chiffres en argument.\n");
		exit(1);
	}
	else if (argc == 2) //Un argument
	{
		printf("ATTENTION: Vous n'avez donne qu'un argument!\nJ'assume qu'il s'agit du chemin vers le dossier contenenant les images.\n");
		numberWidth = 3;
		numberHeight = 5;
	}
	else if(argc == 3) //Si il y a un argument
	{


		sscanf(argv[2], "%dx%d", &numberWidth, &numberHeight);

		if (numberWidth < 3 || numberHeight < 5 || numberWidth > 80 || numberHeight > 23)
		{
			printf("Dimensions trop grandes, trop petites, ou incorrectes!\n");
			exit(1);
		}
		else if (numberHeight != numberWidth + (numberHeight - numberWidth))
		{
			printf("Le ratio des chiffres donné n'est pas bon!\n");
			printf("Vous avez donne: %dx%d\n", numberWidth, numberHeight);
			exit(1);
		}
	}

	//ETAPE 2: Charger en mémoire les images des numéros

	//La 11e case sert à stocker les ':'

	imgPath = malloc(strlen(argv[1]) * sizeof(char) + 6 * sizeof(char)); //Plus 6 char pour le nom de l'image

	strcpy(imgPath, argv[1]);

	for (i = 0; i < 11; ++i)
	{
		if(i != 10)
			imgPath[strlen(argv[1]) + 0] = (char)i + '0';
		else
			imgPath[strlen(argv[1]) + 0] = ':';

		imgPath[strlen(argv[1]) + 1] = '.';
		imgPath[strlen(argv[1]) + 2] = 'p';
		imgPath[strlen(argv[1]) + 3] = 'b';
		imgPath[strlen(argv[1]) + 4] = 'm';
		imgPath[strlen(argv[1]) + 5] = '\0';

		readPBM(imgPath, &numbers[i]);

		imgPath[strlen(argv[1])] = '\0';
	}



	//TANT QUE PAS APPUYE SUR TOUCHE
	//while (1)
	{

		//ETAPE 4: Trouver l'heure 
		time_t timestamp;				//declaration de la variable timestamp de type time_t
		struct tm * t;					//declaration de la structure t de type tm
										//ces variables servent a enregistrer les dates

		timestamp = time(NULL);			//on definit le timestamp en timestamp actuel
										//les valeurs enregistrees de dans correspondent au systeme
		t = localtime(&timestamp);		//ici on initialise les valeurs de la structure t
										//au temps local de l'ordinateur


		//ETAPE 4.5: A faire + tard: redimensionner les numéros

		//ETAPE 5: Créer une image contenant l'heure

		//7 -> le nombre d'espaces
		//2 -> la taille des ':'

		//Creer une image de fond de la taille du terminal
		termBackground = createUniformImageTermSize(' ');

		image * hourBG = createUniformImage(' ', 6 * numberWidth + 7 + 2, numberHeight);

		h0 = (int)t->tm_hour / 10;
		
		h1 = (int)t->tm_hour;
		while(h1 > 9)
			h1 -= 10;

		m0 = (int)t->tm_min / 10;

		m1 = (int)t->tm_min;
		while(m1 > 9)
			m1 -= 10;

		s0 = (int)t->tm_sec / 10;

		s1 = (int)t->tm_sec;
		while(s1 > 9)
			s1 -= 10;


		numbers[h0].xPos = 0;
		numbers[h0].yPos = 0;
		mergeImages(*hourBG, numbers[h0]);

		numbers[h1].xPos = numberWidth + 1;
		numbers[h1].yPos = 0;
		mergeImages(*hourBG, numbers[h1]);

		numbers[10].xPos = 2 * numberWidth + 2;
		numbers[10].yPos = 0;
		mergeImages(*hourBG, numbers[10]);

		numbers[m0].xPos = 2 * numberWidth + 4;
		numbers[m0].yPos = 0;
		mergeImages(*hourBG, numbers[m0]);

		numbers[m1].xPos = 3 * numberWidth + 5;
		numbers[m1].yPos = 0;
		mergeImages(*hourBG, numbers[m1]);

		numbers[10].xPos = 4 * numberWidth + 6;
		numbers[10].yPos = 0;
		mergeImages(*hourBG, numbers[10]);

		numbers[s0].xPos = 4 * numberWidth + 8;
		numbers[s0].yPos = 0;
		mergeImages(*hourBG, numbers[s0]);

		numbers[s1].xPos = 5 * numberWidth + 9;
		numbers[s1].yPos = 0;
		mergeImages(*hourBG, numbers[s1]);



		//ETAPE 6: Centrer l'image de l'heure sur celle du terminal
		centerImage(*termBackground, *hourBG);
		//ETAPE 6.5: TODO Rajouter le texte d'actualisation

		//ETAPE 7: Afficher l'image


		//ETAPE 8 : Afficher le timer
		char stringInImage[] = "Ce message va etre acutalise dans ";
		int i;
		char tmpString[255];
		strcpy(tmpString, stringInImage);
		while (1)
		{
			if (i == 10)
			{
				strcpy(tmpString, stringInImage);
				i = 0;
			}
			textUpdateImage = stringToImage(tmpString);

			textUpdateImage->xPos = (termBackground->xDim - textUpdateImage->xDim)/2;
			textUpdateImage->yPos = termBackground->yDim - 1;

			mergeImages(*termBackground, *textUpdateImage);
			printImage(termBackground);
			free(textUpdateImage);

			sleep(1);
			strcat(tmpString, ".");
			i++;
		}
		//deleteImage(tmpimg);

	}
	//FIN TANT QUE

	//ETAPE 8: Quitter
	return 0;
}
