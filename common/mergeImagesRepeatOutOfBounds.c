#include "mergeImagesRepeatOutOfBounds.h"

void mergeImagesRepeatOutOfBounds(image biggerImage, image smallerImage)
{
	mergeImages(biggerImage, smallerImage);
	
	/*Si l'image dépasse à droite*/
	if (smallerImage.xPos + smallerImage.xDim > biggerImage.xDim)
	{
		/*Il faut alors la faire dépasser du côté gauche*/
		smallerImage.xPos = smallerImage.xPos - biggerImage.xDim;
		mergeImages(biggerImage, smallerImage);
	}
	/*Si l'image dépasse à gauche*/
	else if (smallerImage.xPos < 0)
	{
		/*Il faut alors la faire dépasser du côté droit*/
		smallerImage.xPos = smallerImage.xPos + biggerImage.xDim;
		mergeImages(biggerImage, smallerImage);
	}

	/*Si l'image dépasse en bas*/
	if (smallerImage.yPos + smallerImage.yDim > biggerImage.yDim)
	{
		/*Il faut alors la faire dépasser en haut*/
		smallerImage.yPos = smallerImage.yPos - biggerImage.yDim;
		mergeImages(biggerImage, smallerImage);
	}
	/*Si l'image dépasse à gauche*/
	else if (smallerImage.yPos < 0)
	{
		/*Il faut alors la faire dépasser du côté gauche*/
		smallerImage.yPos = smallerImage.yPos + biggerImage.yDim;
		mergeImages(biggerImage, smallerImage);
	}
}