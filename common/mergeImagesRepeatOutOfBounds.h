//HEADER

#pragma once
#include "struct_image.h"
#include "mergeImages.h"

/*
	mergeImagesRepeatOutOfBounds
	merge deux images, si l'image ajoutée dépasse d'un côté, elle réapparrait de l'autre

	INPUT biggerImage - smallerImage sera mergée SUR bigger image
	INPUT smallerImage - image ajoutée AU DESSUS de biggerImage

	NOTE : Si smaller image a complètement transitionné de l'autre côté de l'image,
	sa position ne sera pas modifiée pour des raisons de flexibilité.
	Si quelqu'un un jour en a besoin, il serait préférable de créer une variante de cette fonction.
	En effet, on ne sait jamais quels sont tous les usages que l'on peut faire d'une fonction
	et dans certaines situations il est peut être préférable de ne pas modifier la 
	position de l'image.

	NOTE : Les arguments ne sont pas biggerImage et smallerImage pour rien.
	Si smallerImage dépasse de droite et gauche ou haut et bas, seul le dépassement
	par la droite et par le bas sont traités.

	NOTE : Si la position d'une image est négative, cela ne pose pas problème, la position 
	étant stockée dans un int.
*/
void mergeImagesRepeatOutOfBounds(image biggerImage, image smallerImage);