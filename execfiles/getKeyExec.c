/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   getKeyExec.c                                    __       __ __	          */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/13 18:53:02 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/13 23:56:35 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

int	main(pid_t pid_parent)
{
	char keyPressed;
	while (keyPressed != 'q')
		keyPressed = getchar();
	kill(pid_parent,9);
	exit(0);
}
