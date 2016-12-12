/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   printStats.c                                    __       __ __	          */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/12 15:16:08 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/12 17:24:20 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"

int		printStats()
{
	int choice;
	FILE *file;
	char *string;

	string = malloc(100 * sizeof(char));
	choice = 1;

	while (choice < 5 && choice > 0)
	{
		printf("Choisir un critere d'affichage :\n"); //affichage des choix 
		printf("1 - date\n");
		printf("2 - type\n");
		printf("3 - parametre du saver\n");
		printf("4 - quitter\n");
		printf("Choix : ");
		scanf("%d", &choice);

		file = fopen("log.txt", "r");				//ouverture du fichier de logs

		if (file == NULL)
		{												
				printf("Fichier non trouve ou inexistant");
				exit (1);								//erreur si fichier inexistant
		}
		fgets(string, 255, file);

		switch (choice)								//taches a effectuer sinon
		{
			case 1:
				while (fgets(string, 255, file) != NULL)
					printf("%s\n",strtok(string, ";"));
				printf("\n");
				break;
			case 2:
				while (fgets(string, 255, file) != NULL)
				{
					strtok(string, ";");
					printf("Launcher numero : %s\n", strtok(NULL, ";"));
				}
				printf("\n");
				break;
			case 3:
			//	fgets(string, 255, file);
			//	strtok(string, ";");
			//	if (strtok(NULL, ";") == "1")

				while (fgets(string, 255, file) != NULL)
				{
					strtok(string, ";");
					strtok(NULL, ";");
					printf("Parametre du saver : %s\n", strtok(NULL, ";"));
				}
				printf("\n");
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Mauvais choix\n");
				break;
		}
	}
	exit (0);
}
