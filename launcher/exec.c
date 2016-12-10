/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   exec.c                                          __       __ __	          */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/09 09:54:30 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/10 15:10:52 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"

int		executeRandom(void)
{
	char *path;
	pid_t pid_child;
	pid_child = fork();
	
	switch(randomSaver())
	{
		case 1:
			path = "../static/main.c\n";
		break;
		case 2:
			path = "../dynamic/main.c\n";
		break;
		case 3:
			path = "../interactive/main.c\n";
		break;
	}

	switch(pid_child)
	{
		case -1:
			perror("fork");
			return EXIT_FAILURE;
		break;

		case 0:
			printf("path : %s", path);
		//	execl(randomSaver(), randomImage(), (char*) NULL);
		break;

		default:
			wait(pid_child);
		break;
	}
}
