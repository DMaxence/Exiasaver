/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   getKeyExec.c                                    __       __ __	          */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/13 18:53:02 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/14 09:34:31 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

int	main(int argc, char *argv[])
{
	char keyPressed;
	{
		while (keyPressed != 'q')
			keyPressed = getchar();
		printf("c'est good");
	}
	return 0;
}
