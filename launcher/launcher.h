/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   launcher.h                                      __       __ __	          */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/07 15:45:13 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/09 11:07:35 by mduhoux                                  */
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
void	empty();

//focntion randomNumber pour definir un chiffre aleatoire dans le but d'executer un saver aleatoirement
int		randomNumber(void);

//fonction logs qui cree et modifie le fichier de logs du saver
int		logs(char *ex);
