/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                          __       __ __	          */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/10 15:03:32 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/10 16:39:55 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"

int		main(int argc, char *argv[])
{
	char path[4];
	int i;

	empty();
	*path = var_env(1);
	while (path[i] != '\0')
	{
		printf("path : %s\n", path[i]);
		i++;
	}
	return 0;

}
