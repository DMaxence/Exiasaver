/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                          __       __ __	          */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/09 17:33:00 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/13 17:21:35 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "../launcher/launcher.h"
#include "../common/struct_image.h"
#include "../common/createUniformImage.h"
#include "../common/readPBM.h"
#include "../common/centerImage.h"
#include "../common/printImage.h"

int		main(int argc, char *argv[])
{
      char *imagename;

      /*Vérification du paramètre de l'image*/
	  printf("%d", argc);
      if (argc == 2)
      {
	  imagename = malloc((strlen(argv[1])+1) * sizeof(char));
	  sscanf(argv[1], "%s", imagename);
	 // imagename = argv[1];

     // strcpy (imagename, argv[1]);

      }
	  else
	  {
		printf("Mauvais nombre d'arguments\n");
		exit (1);
	  }
       //Déclaration de la variable de types image
      image *background;
      image *display;

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

      getchar();
      return 0;



}
