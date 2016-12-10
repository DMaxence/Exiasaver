/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   size_terminal.c                                 __       __ __	          */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/10 14:36:52 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/10 15:25:43 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"

void	getTerminalSize(int * width, int * height)
{
	struct winsize size_terminal;
	ioctl(0, TIOCGWINSZ, &size_terminal);

	//printf("lines : %d\n", size_terminal.ws_row);
	//printf("columns : %d\n", size_terminal.ws_col);

	*width = size_terminal.ws_col;
	*height = size_terminal.ws_row;
}
