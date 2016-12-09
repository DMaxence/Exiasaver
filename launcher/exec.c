/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   exec.c                                          __       __ __	          */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/09 09:54:30 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/09 17:35:16 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"

int		main(void)
{
	pid_t pid_child;

	pid_child = fork();

	switch(pid_child)
	{
	case -1:
		perror("fork");
		return EXIT_FAILURE;
	break;

	case 0:
		execl(randomSaver(), randomImage(), (char*) NULL);
		break;

	default:
		wait(pid_child);
		break;
	}
}
