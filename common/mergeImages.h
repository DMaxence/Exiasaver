#pragma once
#include "struct_image.h"

/*mergeImages
Permet d'applatir deux images pour en former une nouvelle
Attention, la deuxième image est placée en fonction de ses coordonnnées,
biggerImage aura les coordonnées locales (0, 0).
INPUT / OUTPUT biggerImage - L'image de fond et de sortie
INPUT smallerImage - L'image à rajouter par dessus
NOTE: (FONCTION À CRÉER) faites un imgcpy pour ne pas perdre biggerImage si on en a besoin plus tard.*/
void mergeImages(image biggerImage, image smallerImage);