/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   randomSaver.c                                   __       __ __	      */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/09 09:58:40 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/09 17:35:05 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"

int	randomSaver(void)
{
	int randomNumber;
	char path;
	srand(time(NULL));

	randomNumber = rand()%3+1;

	switch(randomNumber)
	{
		case 1:
			path = "../static/main.c";
		break;
		case 2:
			path = "../dynamic/main.c";
		break;
		case 3:
			path = "../interactive/main.c";
		break;
	}
	return path;

}
