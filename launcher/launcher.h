/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   launcher.h                                      __       __ __	          */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/07 15:45:13 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/09 15:55:52 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>

//fonction empty pour nettoyer le terminal
void	empty(void);

//focntion randomSaver pour definir un chiffre aleatoire dans le but d'executer un saver aleatoirement
int		randomSaver(void);

//fonction randomImage pour selectionner aleatoirement l'image du saver 1
int		randomImage(void);

//fonction logs qui cree et modifie le fichier de logs du saver
int		logs(char *ex);
