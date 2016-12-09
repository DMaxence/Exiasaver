#include "readPBM.h"

int main()
{
	int x;
	int y;
	int RGB;
	
	FILE* file = fopen("ex2.pbm", "r");

	readMetaData(file, &x, &y, &RGB);

	printf("x: %d\ny: %d\nRGB: %d\n", x, y, RGB);
	
	fclose(file);


	//readMetaData OK!

	character ** imageArray;
	readPBM("ex2.pbm", &imageArray);
	printArray(imageArray, 15, 15);

	return 0;
}