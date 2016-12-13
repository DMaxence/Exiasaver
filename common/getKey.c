/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   getKey.c                                        __       __ __	          */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/13 12:46:40 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/13 15:58:18 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */

#include "getKey.h"

int	getKey(void)
{
	pid_t pid_child;
	pid_t parent_pid;

	parent_pid = getppid();
	if(parent_pid != 0)
		pid_child = fork();
	else
	{
	char keyPressed;

	switch(pid_child)
	{
		case -1:
			printf("erreur du fork");
			exit (1);
			break;
		case 0:
			keyPressed = getchar();
			if (keyPressed == 'q')
			{
				printf("\n\n\n JE SUIS L'ENFANT JE VAIS TUER MON PAPA\n\n\n");
				kill(parent_pid, 9);
				printf("\n\n\n JE SUIS L'ENFANT J'AI TUE MON PAPA\n\n\n");
			}
			exit (0);
			break;
		default:
			break;
	}
	}
}
