/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   printStats.c                                    __       __ __	          */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/12 15:16:08 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/13 16:17:37 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"
#include "../common/getKey.h"

int		printStats()
{
	int choice;
	FILE *file;
	char *string;

	unsigned int numberTimesLaunched[3];

	string = malloc(100 * sizeof(char));
	choice = 1;
	numberTimesLaunched[0] = 0;
	numberTimesLaunched[1] = 0;
	numberTimesLaunched[2] = 0;

	while (choice < 5 && choice > 0)
	{
		printf("Choisir un critere d'affichage :\n");
		printf("1 - date\n");
		printf("2 - type\n");
		printf("3 - parametre du saver\n");
		printf("4 - quitter\n");
		printf("Choix : ");
		scanf("%d", &choice);

		file = fopen("log.txt", "r");

		/*On vérifie que le fichier soit bien ouvert*/
		if (file == NULL)
		{												
				printf("Fichier non trouve ou inexistant");
				exit (1);
		}

		fgets(string, 255, file);
		
		switch (choice)
		{
			case 1:
				while (fgets(string, 255, file) != NULL)
					printf("%s\n",strtok(string, ";"));
				printf("\n");
				break;
			case 2:
				printf("Dans l'ordre chronologique, les launcher ont ete appeles dans cet ordre\n");
				while (fgets(string, 255, file) != NULL)
				{
					strtok(string, ";");
					sscanf(strtok(NULL, ";"), "%d", &choice);
					switch(choice)
					{
						case 1:
							numberTimesLaunched[0]++;
							break;
						case 2:
							numberTimesLaunched[1]++;
							break;
						case 3:
							numberTimesLaunched[2]++;
							break;
					}
					printf("Launcher numero : %d\n", choice);
				}
				printf("Nombre de fois le lancheur statique a ete lancé : %d\n", numberTimesLaunched[0]);
				printf("Nombre de fois le lancheur dynamique a ete lancé : %d\n", numberTimesLaunched[1]);
				printf("Nombre de fois le lancheur interactif a ete lancé : %d\n", numberTimesLaunched[2]);

				sortInsert(numberTimesLaunched, 3);
				printf("Le launcher le moins lancé a été lancé %d fois\n", numberTimesLaunched[0]);
				printf("Le launcher le plus lancé a été lancé %d fois\n", numberTimesLaunched[2]);

				printf("\n");
				break;
			case 3:

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
				exit(1);
				break;
		}
	}
	exit (0);
}