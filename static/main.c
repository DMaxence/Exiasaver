/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                          __       __ __	          */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/09 17:33:00 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/09 17:33:56 by mduhoux                                  */
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
      char imagename[255];

      /*Vérification du paramètre de l'image*/
      if (argc == 2)
      {
      strcpy (imagename, argv[1]);


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
      return 0;



}
