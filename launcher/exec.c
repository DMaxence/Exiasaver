/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   executeSaver.c                                  __       __ __	          */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/09 09:54:30 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/12 14:08:48 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"

int		executeSaver(char *pathToHome, int screenSaverToLaunch, char *argumentsList[4])
{
	char *path;
	pid_t pid_child;
	pid_child = fork();
	
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

	switch(pid_child)
	{
		case -1:
			perror("fork");
			return EXIT_FAILURE;
		break;

		case 0:
			logs(screenSaverToLaunch, argumentsList);
			execv(pathToHome, argumentsList);
		break;

		default:
			wait(pid_child);
		break;
	}
}
