/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   stringToImage.c                                 __       __ __	          */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/13 10:08:48 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/13 10:29:35 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */

#include "stringToImage.h"

image *	stringToImage(char *string)
{
	int i;
	image *stringImage;

	stringImage = createUniformImage(' ', strlen(string), 1);
	
	for (i = 0; i < strlen(string); i++)
	{
		stringImage->charArray[i][0].c = string[i];
	}
	
	return stringImage;
}
