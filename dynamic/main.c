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

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "../common/struct_image.h"	
#include "../common/printImage.h"
#include "../common/readPBM.h"
#include "../common/createUniformImage.h"

int		main(int argc, char *argv[])
{
	//ETAPE 0: Déclarer les variables
	int numberWidth;
	int numberHeight;

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
	else if(argc == 2) //Si il y a un argument
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
	image numbers[11];
	image * termBackground;
	char *imgPath;
	imgPath = malloc(strlen(argv[1]) * sizeof(char) + 6 * sizeof(char)); //Plus 6 char pour le nom de l'image

	strcpy(imgPath, argv[1]);

	for (int i = 0; i < 11; ++i)
	{
		if(i != 10)
			imgPath[strlen(argv[1]) + 0] = (char)i + '0';
		else
			imgPath[strlen(argv[1]) + 0] = ':';

		imgPath[strlen(argv[1]) + 1] = '.';
		imgPath[strlen(argv[1]) + 2] = 'p';
		imgPath[strlen(argv[1]) + 3] = 'p';
		imgPath[strlen(argv[1]) + 4] = 'm';
		imgPath[strlen(argv[1]) + 5] = '\0';

		readPBM(imgPath, &numbers[i]);

		imgPath[strlen(argv[1])] = '\0';
	}

	//ETAPE 3: Creer une image de fond de la taille du terminal

	termBackground = createUniformImageTermSize(' ');

	//TANT QUE PAS APPUYE SUR TOUCHE

		//ETAPE 4: Trouver l'heure 

		//ETAPE 4.5: A faire + tard: redimensionner les numéros

		//ETAPE 5: Créer une image contenant l'heure

		//ETAPE 6: Centrer l'image de l'heure sur celle du terminal

		//ETAPE 6.5: TODO Rajouter le texte d'actualisation

		//ETAPE 7: Afficher l'image

	//FIN TANT QUE

	//ETAPE 8: Quitter
	return 0;
}
