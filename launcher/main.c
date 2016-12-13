/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                          __       __ __	          */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/10 15:03:32 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/13 14:40:35 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"
#include "../common/getKey.h"

int		main(int argc, char *argv[])
{
	//ETAPE 1: Préparer le terrain
	//on n'a besoin de seed le générateur de nombres aléatoire qu'une fois
	srand(time(NULL));

	int screenSaverToLaunch;
	char * pathToHome = NULL;
	char * argumentsList[4]; //Pas plus de trois arguments pour le scrsvr dynamique
	char * imageName;

	if (argc == 2 && strcmp(argv[1],"-stats") == 0)
	{
		printStats();	
	}

	//ETAPE 2: Se décider sur quel ecran de veille choisir
	screenSaverToLaunch = randomSaver();

	//ETAPE 3: Prépare les variables d'environnement pour trouver où se troubent les dossiers nécessaires
	getEnvFolders(screenSaverToLaunch, &pathToHome, argumentsList); 

	//Cette ligne permet de vérifier les settings générés et la bonne lecture des vars d'envt
	//printf("%d %s %s\n", screenSaverToLaunch, pathToHome, argumentsList[0]);

	//ETAPE 4: Finaliser la liste des arguments en ajoutant au chemin des dossiers les noms d'images
	imageName = randomImage(argumentsList[0]);
	strcat(argumentsList[0], imageName);
	free(imageName);
	//ETAPE 5: clear le terminal
	emptyTerminal();
	//ETAPE 6: Executer le fond d'ecran	
	executeSaver(pathToHome, screenSaverToLaunch, argumentsList);	
	
	return 0;
}
