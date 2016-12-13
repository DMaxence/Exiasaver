#include "deleteImage.h"

void deleteImage(image * imageToDelete)
{
	freeTable(imageToDelete->charArray, imageToDelete->xDim);
}