#include "createResizedImage.h"

/*Techniquement, voilà comment ça marche:
Pour chaque pixel de la nouvelle image, on va se demander à quel pixel de l'image d'origine ça correspond*/
character computePixel(image originImage, int xPixel, int yPixel, int newWidth, int newHeight)
{
	float x;
	float y;

	x = (float) ((float)xPixel/(float)newWidth) * (float)originImage.xDim;
	y = (float) ((float)yPixel/(float)newHeight) * (float)originImage.yDim;

	x = (x < originImage.xDim) ? x : originImage.xDim - 1;
	y = (y < originImage.yDim) ? y : originImage.yDim - 1;

	return originImage.charArray[(int)x][(int)y];
}

image * createResizedImage(image imageToResize, int widthToFit, int heightToFit)
{
	image * outImage;
	int i;
	int j;

	outImage = createUniformImage(' ', widthToFit, heightToFit);

	for (i = 0; i < widthToFit; ++i)
	{
		for (j = 0; j < heightToFit; ++j)
		{
			outImage->charArray[i][j] = computePixel(imageToResize, i, j, widthToFit, heightToFit);
		}
	}

	return outImage;
}