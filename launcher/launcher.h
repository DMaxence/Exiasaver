/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   launcher.h                                      __       __ __	          */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/07 15:45:13 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/10 14:57:06 by mduhoux                                  */
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
void	empty(void);

//focntion randomSaver pour definir un chiffre aleatoire dans le but d'executer un saver aleatoirement
int		randomSaver(void);

//fonction randomImage pour selectionner aleatoirement l'image du saver 1
char*		randomImage(void);

//fonction logs qui cree et modifie le fichier de logs du saver
int		logs(char *ex);

//fonction pour determiner la taille du terminal
int		size_terminal(void);
