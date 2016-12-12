#include "readPBM.h"
#include "struct_image.h"
#include "deleteImage.h"
#include "printImage.h"
#include "createUniformImage.h"
#include "mergeImages.h"
#include "centerImage.h"

int main()
{
	image testImage1;
	image testImage2;
	image testImage3;
	image* testTerm = NULL;
	
	//Dimensions différentes
	readPBM("ex1.pbm", &testImage1);

	//Dimensions identiques
	readPBM("ex2.pbm", &testImage2);

	//Une image uniforme de la taille du terminal
	testTerm = createUniformImageTermSize('o');
	
	testImage2.xPos = 10;
	testImage2.yPos = 5;
	
	centerImage(*testTerm, testImage2);

	//printf("%c\n", testTerm->charArray[10][11].c);


	//Couleur
	readPBM("color.ppm", &testImage3);
	
	printImage(&testImage1);
	printImage(&testImage2);
	printImage(&testImage3);
	printImage(testTerm);

	//Même si ce ne sont pas des pointeurs, il faut delete les images
	//Pour supprimer les tableaux de char a linterieur
	deleteImage(&testImage1);
	deleteImage(&testImage2);
	deleteImage(&testImage3);
	deleteImage(testTerm);

	return 0;
}