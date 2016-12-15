/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                          __       __ __	          */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/09 17:33:00 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/15 09:26:56 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "../launcher/launcher.h"
#include "../common/struct_image.h"
#include "../common/createUniformImage.h"
#include "../common/readPBM.h"
#include "../common/centerImage.h"
#include "../common/printImage.h"
#include "../common/deleteImage.h"

int		main(int argc, char *argv[])
{
    char imagename[255];
	/*Déclaration de la variable de types image*/
	image *background;
	image *display;
	
	/*Creation des variables necessaires au fork et au pipe*/
	int fd[2];
	int readFromPipe;
	pid_t pid_child;
	char readBufferFromPipe[100];
	char *stringToReturn;

	/*Debut du fork et du pipe*/

	if(pipe(fd) != 0)
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
			/*Fermeture de fd[0] car l'enfant n'a pas besoin de lire dans le pipe*/
			close(fd[0]);

    		/*Vérification du paramètre de l'image*/
		    if (argc == 2)
		    {
		          strcpy (imagename, argv[1]);
		    }
			
			/*ecriture de imagename dans le pipe*/
			write(fd[1], imagename, (sizeof(char) * strlen(imagename)+1));
			close(fd[1]);
			exit(0);
			break;
		default:
			/*Fermeture de fd[0] car l'enfant n'a pas besoin de lire dans le pipe*/
			close(fd[1]);

			/*On lit le nom du fichier recupere par le pipe*/
			readFromPipe = read(fd[0], readBufferFromPipe, (sizeof(char) * 100));
			
			/*On copie le contenu de readBufferFromPipe dans imagename*/
			strcpy(imagename, readBufferFromPipe);

			/*Allocation de mémoire*/
		    display = malloc (sizeof(image));

		    /*Adaptation de l'image avec le terminal*/
		    background = createUniformImageTermSize(' ');

		    /*Converti le fichier de façon à pouvoir afficher une image*/
		    readPBM (imagename, display);

		    /*Permet de centrer l'image sur le terminal*/
		    centerImage (*background, *display);

		    /*Permet d'afficher l'image*/
		    printImage (background);

		    /*Comme il n'y a qu'une frame à afficher, on peut tout supprimer*/
		    deleteImage(background);
		    deleteImage(display);

		    /*Attend l'appuie d'une touche pour pouvoir quitter le programme*/
		    getchar();

    return 0;
	}
}
