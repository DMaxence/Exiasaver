/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   randomSaver.c                                   __       __ __	      */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/09 09:58:40 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/09 14:10:41 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"

int	randomSaver(void)
{
	int randomNumber;
	srand(time(NULL));

	randomNumber = rand()%3+1;
	return randomNumber;

}
