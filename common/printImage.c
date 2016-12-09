#include "printImage.h"

void printImage(image * img)
{
	for (int i = 0; i < img->yDim; ++i)
	{
		for (int j = 0; j < img->xDim; ++j)
		{
			//Voici comment marche TRUECOLOR
			//printf("\x1b[38;2;255;00;0mTRUECOLOR\x1b[0m\n");
			//38 -> bg
			//2 -> toujours 2
			//R;G;Bm

			//putchar(img->charArray[j][i].c);
			printf("\x1b[38;2;%d;%d;%dm%c\x1b[0m", img->charArray[j][i].rgb.R, img->charArray[j][i].rgb.G, img->charArray[j][i].rgb.B, img->charArray[j][i].c);
			//printf("%d:%d:%d", img->charArray[j][i].rgb.R, img->charArray[j][i].rgb.G, img->charArray[j][i].rgb.B);
		}
		printf("\n");
	}
}