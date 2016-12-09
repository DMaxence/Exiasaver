#include "printImage.h"

void printImage(image * img)
{
	for (int i = 0; i < img->xDim; ++i)
	{
		for (int j = 0; j < img->yDim; ++j)
		{
			putchar(img->charArray[j][i].c);
		}
		printf("\n");
	}
}