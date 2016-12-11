#include "createUniformImage.h"

image * createUniformImageTermSize(char fillCharacter)
{
	int * x = malloc(sizeof(int));
	int * y = malloc(sizeof(int));

	getTerminalSize(x, y);

	image * im = createUniformImage(fillCharacter, *x, *y);

	free(x);
	free(y);

	return im;
}

image * createUniformImage(char fillCharacter, int width, int height)
{
	image* im = malloc(sizeof(image));
	int i, j;

	//On remplit alloue une image de la même taille que le terminal
	im->charArray = createTable(width, height); 

	for (i = 0; i < width; ++i)
	{
		for (j = 0; j < height; ++j)
		{
			//printf("%d %d\n", i, j);
			im->charArray[i][j].c = fillCharacter;

			im->charArray[i][j].rgb.R = 255;
			im->charArray[i][j].rgb.G = 255;
			im->charArray[i][j].rgb.B = 255;
		}
	}

	im->xDim = width;
	im->yDim = height;

	return im;	
}