#include "readPBM.h"
#include "struct_image.h"
#include "deleteImage.h"
#include "printImage.h"

int main()
{
	image testImage1;
	image testImage2;
	image testImage3;
	
	//Dimensions différentes
	readPBM("ex1.pbm", &testImage1);

	//Dimensions identiques
	readPBM("ex2.pbm", &testImage2);

	//Couleur
	readPBM("color.ppm", &testImage3);
	
	printImage(&testImage1);
	printImage(&testImage2);
	printImage(&testImage3);

	deleteImage(&testImage1);
	deleteImage(&testImage2);
	deleteImage(&testImage3);
	
	int test = 255;
	printf("\x1b[38;2;255;%d;0mTRUECOLOR\x1b[0m\n", test);

	return 0;
}