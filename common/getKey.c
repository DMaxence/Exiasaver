/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   getKey.c                                        __       __ __	          */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/13 12:46:40 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/14 09:51:35 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */

#include "getKey.h"

int	getKey(void)
{
	pid_t pid_child;
	pid_t pid_parent;
	char keyPressed;

	pid_parent = getpid();
	pid_child = fork();

	switch(pid_child)
	{
		case -1:
			printf("erreur du fork");
			exit (1);
			break;
		case 0:
			while (keyPressed != 'q')
				keyPressed = getchar();
			kill(pid_parent, 9);
			exit (0);
			break;
		default:
			break;
	}
}
