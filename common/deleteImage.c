#include "deleteImage.h"

void deleteImage(image * imageToDelete)
{
	//WHAT? xDim ou yDim -> meme resultat
	freeTable(imageToDelete->charArray, imageToDelete->xDim);
}