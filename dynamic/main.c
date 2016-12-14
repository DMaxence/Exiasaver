/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                          __       __ __	          */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/09 17:33:00 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/14 12:48:05 by mduhoux                                  */
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
#include "../common/createFullTerminalHourImage.h"
#include "../common/getKey.h"
#include "../common/createResizedImage.h"

int		main(int argc, char *argv[])
{
	//ETAPE 0: Déclarer les variables
	int numberWidth;
	int numberHeight;

	image numbers[11]; //Ce tableau va contenir les images
	image * hourBackground;
	image * textUpdateImage;
	char *imgPath;
	int i;
	int timer;

	numberHeight = 0;
	numberWidth = 0;

	//ETAPE 1: Vérifier que les arguments donnés sont bons et les stocker dans des variables
	
		printf("argv0 : %s\n", argv[0]);
		printf("argv1 : %s\n", argv[1]);
		printf("argv2 : %s\n", argv[2]);
		printf("argv3 : %s\n", argv[3]);
	//Si aucun argument n'est donné
	if (argc == 1)
	{
		printf("Veuillez donner le repertoire contenant les images des chiffres en argument.\n");
		exit(1);
	}
	else if (argc == 2) //Un argument
	{
		printf("ATTENTION: Vous n'avez donne qu'un argument!\nJ'assume qu'il s'agit du chemin vers le dossier contenenant les images.\n");
		printf("argv1 : %s\n", argv[1]);
		numberWidth = 5;
		numberHeight = 9;
		timer = 10;
	}
	else if(argc == 3 || argc == 4) //Si il y a deux arguments
	{

		sscanf(argv[2], "%dx%d", &numberWidth, &numberHeight);
		printf("argv2 : %s\n", argv[2]);
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
		timer = 10;
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




	//ETAPE 5: redimensionner les numéros
	image * tmpResizedImage;
	for (int i = 0; i < 11; ++i)
	{
		/*On crée une nouvelle image de bonne dimensions*/
		tmpResizedImage = createResizedImage(numbers[i], numberWidth, numberHeight);
		
		/*On supprime les images 3x5*/
		deleteImage(&numbers[i]);

		/*On donne les nouvelles dimensions aux anciennes 3x5*/
		numbers[i].xDim = numberWidth;
		numbers[i].yDim = numberHeight;

		/*On donne les nouvelles images aux anciennes 3x5*/
		numbers[i].charArray = tmpResizedImage->charArray;
	}

	/*Dans la mémoire, on a maintenant uniquement les images des chiffres resizés*/

	//ETAPE 8 : Afficher le timer
	char stringInImage[] = "Ce message va etre acutalise dans ";
	char tmpString[255];
	strcpy(tmpString, stringInImage);
	hourBackground = createFullTerminalHourImage(numbers);
	i = 0;

	getKey();
	/*Appel a la fonction getKey pour creer un processus fils qui ecoute le clavier
	 *en attente de l'appui sur la touche 'q'*/
	while (1)
	{
		if (i == timer) // TODO remplacer avec la var d'environnement
		{
			strcpy(tmpString, stringInImage);
			free(hourBackground);
			hourBackground = createFullTerminalHourImage(numbers);
			i = 0;
		}
		textUpdateImage = stringToImage(tmpString);

		textUpdateImage->xPos = (hourBackground->xDim - textUpdateImage->xDim)/2;
		textUpdateImage->yPos = hourBackground->yDim - 1;

		mergeImages(*hourBackground, *textUpdateImage);
		printImage(hourBackground);

		free(textUpdateImage);

		sleep(1);
		strcat(tmpString, ".");
		i++;
	}

	//ETAPE 8: Quitter
	return 0;
}
