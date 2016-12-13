/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   executeSaver.c                                  __       __ __	          */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/09 09:54:30 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/14 11:17:11 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"

int		executeSaver(char *pathToHome, int screenSaverToLaunch, char **argumentsList)
{
		char *path;

		switch(screenSaverToLaunch)
		{
				case 1:
						strcat(pathToHome, "exiasaver1");
						logs(screenSaverToLaunch, argumentsList);
						execl(pathToHome, " ", argumentsList[0], (char *) NULL);
						break;
				case 2:
						strcat(pathToHome, "exiasaver2");
						logs(screenSaverToLaunch, argumentsList);
						printf("argvlauncher0 : %s\n", argumentsList[0]);
						execl(pathToHome, " ", argumentsList[0], argumentsList[1], argumentsList[2], (char *) NULL);
						break;
				case 3:
						strcat(pathToHome, "exiasaver3");
						logs(screenSaverToLaunch, argumentsList);
						execl(pathToHome, " ", argumentsList[0], argumentsList[1], (char * )NULL);
						break;
		}

		exit (0);
}
