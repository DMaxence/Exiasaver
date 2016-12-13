//HEADER

#pragma once
#include "createUniformImage.h"

/*createResizedImage
Permet de modifier la taille d'une image en n'importe quelles proportions
L'image renvoyée est mallocée et est rescalée
INPUT imageToResize - l'image à rescaler
INPUT widthToFit - la largeur de l'image renvoyée
INPUT heightToFit - la hauteur de l'image renvoyée
*/
image * createResizedImage(image imageToResize, int widthToFit, int heightToFit);