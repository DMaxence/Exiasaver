/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   executeSaver.c                                  __       __ __	          */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/09 09:54:30 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/13 11:14:05 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"

int		executeSaver(char *pathToHome, int screenSaverToLaunch, char *argumentsList[4])
{
		char *path;

		switch(screenSaverToLaunch)
		{
				case 1:
						strcat(pathToHome, "exiasaver1");
						break;
				case 2:
						strcat(pathToHome, "exiasaver2");
						break;
				case 3:
						strcat(pathToHome, "exiasaver3");
						break;
		}

		logs(screenSaverToLaunch, argumentsList);
		execv(pathToHome, argumentsList);
		exit (0);
}
