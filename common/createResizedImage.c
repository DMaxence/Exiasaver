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

/*public void unzoom(int[][] in, int[][] out){
for(int i=0;i<out.length;i++)
for(int j=0;j<out[i].length;j++)
out[i][j]= computepixel(in,i,j,out.length,out[i].length);
}


private int computepixel(int[][] out, float i, float j, int width, int height) {
float x,y;
x=(float) (i/width)*out.length;
y=(float) (j/height)*out[0].length;
x=(x<out.length)?x:(out.length-1);
y=(y<out[0].length)?y:(out[0].length-1);
return out[(int)x][(int)y];
}*/