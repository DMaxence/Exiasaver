/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   var_env.c                                       __       __ __	          */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/10 15:37:18 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/14 11:19:17 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"

void	getEnvFolders(int saver, char ** homeFolder, char * argumentsList[4])
{
	char* tmp;
	switch(saver)
	{
		/*Pour le scrsvr statique, il faut donner le répertoire contenant les images*/
		case 1:
			argumentsList[0] = malloc(255 * sizeof(char));
			tmp = getenv("EXIASAVER1_PBM");
			
			if (tmp != NULL)
			{
				strcpy(argumentsList[0], tmp);
			}
			else
			{
				strcpy(argumentsList[0], getenv("PWD"));
			}
			argumentsList[1] = NULL;
			break;

		/*Pour le dynamique, il faut donner le répertoire d'images,
		Le nombre de secondes avant d'actualiser l'heure*/
		case 2:
			argumentsList[0] = malloc(255 * sizeof(char));
			argumentsList[1] = malloc(255 * sizeof(char));
			argumentsList[2] = malloc(255 * sizeof(char));

			tmp = getenv("EXIASAVER2_PBM");
			
			if (tmp != NULL)
			{
				strcpy(argumentsList[0], tmp);
				printf("getenv : %s\ntmpemv : %s\n", argumentsList[0], tmp);
			}
			else
			{
				strcpy(argumentsList[0], getenv("PWD"));
			}

			tmp = getenv("EXIASAVER2_TAILLE");
			
			if (tmp != NULL)
			{
				strcpy(argumentsList[1], tmp);
			}
			else
			{
				strcpy(argumentsList[1], "5x3");
			}
			
			tmp = getenv("EXIASAVER2_SLEEP");
			
			if (tmp != NULL)
			{
				strcpy(argumentsList[2], tmp);
			}
			else
			{
				strcpy(argumentsList[2], "10");
			}
			argumentsList[3] = NULL;
			break;

		/*Pour le scrsvr interactif, il faut donner uniquement le répertoire contenant l'image*/
		case 3:
			argumentsList[0] = malloc(255 * sizeof(char));
			tmp = getenv("EXIASAVER3_PBM");
			
			if (tmp != NULL)
			{
				strcpy(argumentsList[0], tmp);
			}
			else
			{
				strcpy(argumentsList[0], getenv("PWD"));
			}	
			argumentsList[1] = NULL;
			break;

		default:
			puts("Erreur dans le lecture des variables d'environnement: impossible de determiner de quel ecran de veille il s'agit.\n");
			exit(1);
			break;
	}

	
	/*Enfin, on indique là où se trouvent les executables*/
	*homeFolder = malloc(255 * sizeof(char));
	tmp = getenv("EXIASAVER_HOME");
	
	if (tmp != NULL)
	{
		strcpy(*homeFolder, tmp);
	}
	else
	{
		strcpy(*homeFolder, getenv("PWD"));
	}
}
