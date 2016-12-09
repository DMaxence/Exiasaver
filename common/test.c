#include "readPBM.h"
#include "struct_image.h"
#include "printImage.h"

int main()
{
	image testImage;
	
	//FILE* file = fopen("ex2.pbm", "r");

	//readMetaData(file, &x, &y, &RGB);

	//printf("x: %d\ny: %d\nRGB: %d\n", x, y, RGB);
	
	//fclose(file);


	//readMetaData OK!
	readPBM("ex2.pbm", &testImage);
	printImage(&testImage);
	printf("\x1b[38;2;255;00;0mTRUECOLOR\x1b[0m\n");

	return 0;
}