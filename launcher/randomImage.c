/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   randomImage.c                                   __       __ __	      */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/09 09:58:40 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/14 23:07:14 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"
#include "fcntl.h"
#include <errno.h>

char * randomImage(char *argumentsList)
{
		/*Creation des variables necessaires a la lecture des fichiers d'un dossier */
		DIR *directory;
		struct dirent *dir;
		int randomNumber;
		char * filenames[100];
		char * filename;
		int i;
		int	j;

		/*Creation des variables necessaires au fork et au pipe*/
		int	fd[2];
		int readFromPipe;
		pid_t pid_child;
		char *stringToPipe;
		char readBufferFromPipe[100];
		char *stringToReturn;

		/*Debut du fork et du pipe*/

		if (pipe(fd) != 0)
		{
			perror ("pipe");
			exit(1);
		}
		pid_child = fork();

		switch(pid_child)
		{
			case -1:
				perror("fork");
				exit(1);
				break;
			case 0:
				/*Fermeture du fd[0] car l'enfant n'a pas besoin de lire dans le pipe*/
				close(fd[0]);

				/*Debut de l'algorithme qui recupere les noms des fichiers*/
				i = 0;

				directory = opendir(argumentsList);

				/*On vérifie que ce soit bien ouvert*/
				if (directory)
				{
					/*On fait une boucle qui copie le nom des répertoires
					 *On copie les noms dans un tableau pour selectionner une seule image*/
					while ((dir = readdir(directory)) != NULL)
					{		  		
					/*on verifie que les fichiers retournes sont bien des fichiers et non des dossiers*/
						if (dir->d_type == DT_REG)
						{
							filenames[i] = malloc(strlen(dir->d_name) * sizeof(char));
							strcpy(filenames[i], dir->d_name);
							i++;
						}
					}
				}
				closedir(directory);

				srand(time(NULL));
				randomNumber = rand() % i;

				filename = malloc(strlen(filenames[randomNumber]) * sizeof(char));

				strcpy(filename, filenames[randomNumber]);

				for (j = 0; j < i; j++)
				{
					free(filenames[j]);
				}

				printf("fils string : %s\n", filename);

				/*On envoie le nom du fichier a recuperer par le pipe */
				write(fd[1], filename, (sizeof(filename)+1));
				exit(0);
				break;
			default:
				/*Fermeture du fd[1] car le pere n'a pas besoin d'ecrire dans le pipe*/
				close(fd[1]);
				

				/*On lit le nom du fichier recupere par le pipe*/
				while (read(fd[0], readBufferFromPipe, (sizeof(readBufferFromPipe)+1)) > 0)
					printf("readBufferFromPipe : %s\n", readBufferFromPipe);


				stringToReturn = malloc(sizeof(char) * strlen(readBufferFromPipe));
				strcpy(stringToReturn, readBufferFromPipe);

				return stringToReturn;
				break;
		}
}
