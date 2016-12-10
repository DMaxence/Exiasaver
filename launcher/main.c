/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                          __       __ __	          */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/10 15:03:32 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/10 16:39:55 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"

int		main(int argc, char *argv[])
{
	//ETAPE 1: Préparer le terrain
	//on n'a besoin de seed le générateur de nombres aléatoire qu'une fois
	srand(time(NULL));

	int screenSaverToLaunch;
	char * pathToHome = NULL;
	char * argumentsList[3]; //Pas plus de trois arguments pour le scrsvr dynamique

	//ETAPE 2: Se décider sur quel ecran de veille choisir
	screenSaverToLaunch = randomSaver();

	//ETAPE 3: Prépare les variables d'environnement pour trouver où se troubent les dossiers nécessaires
	getEnvFolders(screenSaverToLaunch, &pathToHome, argumentsList); 

	//Cette ligne permet de vérifier les settings générés et la bonne lecture des vars d'envt
	//printf("%d %s %s\n", screenSaverToLaunch, pathToHome, argumentsList[0]);

	//ETAPE 4: Finaliser la liste des arguments en ajoutant au chemin des dossiers les noms d'images

	//ETAPE 5: clear le terminal

	//ETAPE 6: Executer le fond d'ecran

	//ETAPE 7: Si le lancement est réussi, faire un log (s'il échoue aussi en fait)

	//ETAPE 8: Attendre que l'utilisateur appuie sur une touche, et gérer si il faut envoyer SIGKILL

	//ETAPE 9: Log de fin d'activité.

	//ETAPE 10: Quitter
	return 0;
}
