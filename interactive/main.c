/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                          __       __ __	          */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/09 17:33:00 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/09 17:33:56 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "../common/struct_image.h"
#include "../common/printImage.h"
#include "../common/readPBM.h"
#include "../common/mergeImages.h"
#include "../common/deleteImage.h"
#include "../common/createUniformImage.h"

#include "../launcher/launcher.h"

int		main(int argc, char *argv[])
{
	//Déclaration des variables
	int initialPositionX;
	int initialPositionY;
	int backgroundWidth;
	int backgroundHeight;
	int * x;
	int * y;

	char *imgPath;
	image planePositions[4];


	//Si aucun argument n'est donné
	if (argc == 1)
	{
		printf("Veuillez donner le repertoire contenant les images de l'avion argument.\n");
		exit(1);
	}
	else if (argc == 2) //Un argument, le répertoire contenant les images de l'avion
	{
		printf("ATTENTION: Vous n'avez donne qu'un argument!\nJ'assume qu'il s'agit du chemin vers le dossier contenenant les images.\n");
		initialPositionY = 0;
		initialPositionX = 0;
	}
	else if(argc == 3) //Si il y a deux argument
	{
		sscanf(argv[2], "%dx%d", &initialPositionX, &initialPositionY);

		if (initialPositionX < 0 || initialPositionY < 0 || initialPositionX > 80 || initialPositionY > 23)
		{
			printf("Position de l'avion incorrecte (précisez entre 80x23)!\n");
			exit(1);
		}
	}

	//Début du programme
	//Charger en mémoire les images des 4 positions de l'avion

	imgPath = malloc(strlen(argv[1]) * sizeof(char) + 6 * sizeof(char)); //Plus 6 char pour le nom de l'image

	//Position haut
	strcpy(imgPath, argv[1]);
	strcat(imgPath, "u.pbm");
	readPBM(imgPath, &planePositions[0]);

	//Position bas
	strcpy(imgPath, argv[1]);
	strcat(imgPath, "d.pbm");
	readPBM(imgPath, &planePositions[1]);
	
	//Position droite
	strcpy(imgPath, argv[1]);
	strcat(imgPath, "r.pbm");
	readPBM(imgPath, &planePositions[2]);

	//Position gauche
	strcpy(imgPath, argv[1]);
	strcat(imgPath, "l.pbm");
	readPBM(imgPath, &planePositions[3]);

	free(imgPath);

	//printImage(&planePositions[0]);
	//printImage(&planePositions[1]);
	//printImage(&planePositions[2]);
	//printImage(&planePositions[3]);

	//On a maintenant les images de l'avion chargées.
	//tant que la commande n'est pas la touche 'p'
	char * userInput;
	userInput = malloc(255 * sizeof(char));
	image * fullTerminalImage;
	image planeImage;

	planeImage.xPos = initialPositionX;
	planeImage.yPos = initialPositionY;

	planeImage.xDim = 6;
	planeImage.yDim = 6;

	planeImage.charArray = planePositions[3].charArray;

	//On trouve les tailles correctes du bakground

	x = malloc(sizeof(int));
	y = malloc(sizeof(int));

	getTerminalSize(x, y);

	backgroundWidth = *x;
	backgroundHeight = *y - 1;

	free(x);
	free(y);

	//TANT QUON TAPE PAS P
	while(userInput[0] != 'p')
	{
		//CREER UNE IMAGE TAIILE TERM - 1 EN HAUTEUR
		fullTerminalImage = createUniformImage(' ', backgroundWidth, backgroundHeight);

		//METTRE LAVION DESSUS
		mergeImages(*fullTerminalImage, planeImage);

		//AFFICHER
		printImage(fullTerminalImage);

		//LIRE LINPUT
		printf("Direction (p: quitter): ");
		scanf("%s", userInput);

		//BOUGER LAVION DE POSITION
		if (userInput[0] == 'z')
		{
			planeImage.yPos--;
			planeImage.charArray = planePositions[0].charArray;
		}
		if (userInput[0] == 's')
		{
			planeImage.yPos++;
			planeImage.charArray = planePositions[1].charArray;
		}
		if (userInput[0] == 'd')
		{
			planeImage.xPos++;
			planeImage.charArray = planePositions[2].charArray;
		}
		if (userInput[0] == 'q')
		{
			planeImage.xPos--;
			planeImage.charArray = planePositions[3].charArray;
		}

		//DELETE L'IMAGE DE BACKGROUND
		deleteImage(fullTerminalImage);

	//FIN TANT QUE
	}

	return 0;
}
