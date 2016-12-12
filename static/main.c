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
      image *background;
      image *display;
      display = malloc (sizeof(image));
      background = createUniformImageTermSize(' ');
      readPBM (imagename, display);
      centerImage (*background, *display);
      printImage (background);
      return 0;



}
