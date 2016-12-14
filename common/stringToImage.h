/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   stringToImage.h                                 __       __ __	          */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/13 10:08:55 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/13 10:29:58 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "struct_image.h"
#include "createUniformImage.h"
#include <string.h>

/*stringToImage
Convertis une string en image
INPUT string - La string à convertir
NOTE: L'image sera malloc et de hauteur 1*/
image *	stringToImage(char *string);
