#include "createUniformImage.h"

image * createUniformImageTermSize(char fillCharacter)
{
	int * x = malloc(sizeof(int));
	int * y = malloc(sizeof(int));
	image* im = malloc(sizeof(image));
	int i, j;
	int xmax, ymax;

	getTerminalSize(x, y);

	//On remplit alloue une image de la même taille que le terminal
	im->charArray = createTable(*x, *y); 
	//im->charArray = createTable(10, 3); 

	xmax = *x;
	ymax = *y;

	//ymax = 3;
	//xmax = 10;

	printf("%d %d\n", xmax, ymax);

	for (i = 0; i < xmax; ++i)
	{
		for (j = 0; j < ymax; ++j)
		{
			//printf("%d %d\n", i, j);
			im->charArray[i][j].c = fillCharacter;

			im->charArray[i][j].rgb.R = 255;
			im->charArray[i][j].rgb.G = 255;
			im->charArray[i][j].rgb.B = 255;
		}
	}

	im->xDim = *x;
	im->yDim = *y;

	//im->xDim = 10;
	//im->yDim = 3;

	//puts("OK!");

	return im;
}