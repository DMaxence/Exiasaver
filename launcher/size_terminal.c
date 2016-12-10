/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   size_terminal.c                                 __       __ __	          */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/10 14:36:52 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/10 14:55:52 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"

int		size_terminal(void)
{
	struct winsize size_terminal;
	ioctl(0, TIOCGWINSZ, &size_terminal;

	printf("lines : %d\n", size_terminal.ws_row);
	printf("columns : %d\n", size_terminal.ws_col);
	return 0;
}
