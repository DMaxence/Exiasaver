/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   randomImage.c                                   __       __ __	      */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/09 09:58:40 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/09 16:30:56 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"

int	randomImage(void)
{
	DIR *directory;
	struct dirent *dir;
	int randomNumber;
	char filenames[100][100];
	int i;
	
	i = 0;
	directory = opendir("../img/");
	if (directory)									//boucle qui copie le nom des repertoires
	{
		while ((dir = readdir(directory)) != NULL)	//dans un tableau afin de selectionner
		{											//aleatoirement un fichier d'image
			if (dir->d_type == DT_REG)
			{
				strcpy(filenames[i], dir->d_name);
				i++;
			}
		}
	}
	closedir(directory);


	srand(time(NULL));
	randomNumber = rand()%i;
	return filenames[randomNumber];

}
