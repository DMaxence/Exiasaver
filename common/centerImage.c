#include "centerImage.h"

void centerImage(image background, image imageToCenter)
{
	/*determiner l'endroit a partir de laquelle il faut mettre l'image a centrer*/
	int	x;
	int	y;
	
	x = (background.xDim - imageToCenter.xDim) / 2;
	y = (background.yDim - imageToCenter.yDim) / 2;

	/*Et on assigne ces positions aux images*/
	imageToCenter.xPos = x;
	imageToCenter.yPos = y;

	/*Enfin, on merge les images en faisant attention qu'elles soient centrées*/
	mergeImages(background, imageToCenter);
}
