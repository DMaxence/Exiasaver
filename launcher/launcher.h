/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   launcher.h                                      __       __ __	          */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/07 15:45:13 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/12 14:09:07 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <sys/ioctl.h>

//fonction empty pour nettoyer le terminal
void	emptyTerminal(void);

//fonction randomSaver pour definir un chiffre aleatoire dans le but d'executer un saver aleatoirement
//Dans les faits, cette fonction renvoie un int aléatoire entre 1 et 3 compris
int		randomSaver(void);

//fonction randomImage pour selectionner aleatoirement l'image du saver 1
char*	randomImage(char *argumentsList);

//fonction logs qui cree et modifie le fichier de logs du saver
int		logs(int screenSaverToLaunch, char *argumentsList[4]);

//fonction pour récupérer la taille du terminal
// OUTPUT width - la largeur du terminal
// OUTPUT height - la hauteur du terminal
void	getTerminalSize(int * width, int * height);

//fonction qui execute un saver aleatoirement grace a la fonction randomSaver
int		executeSaver(char *pathToHome, int screenSaverToLaunch, char *argumentsList[4]);

//fonction pour recuperer les variables environnementales
//Prépare la liste des dossiers nécessaires
//Trouve le chemin vers le répertoire contenant les exécutables
// INPUT saver - Le sreensaver à lancer (1 -> statique, 2 -> dynamique, 3 -> interactif)
// OUTPUT homeFolder - Le chemin vers le répertoire contenant les executables
// OUTPUT argumentsList - la liste des dossiers contenant les images etc
void	getEnvFolders(int saver, char ** homeFolder, char * argumentsList[4]);
