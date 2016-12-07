#include "readPBM.h"

int main()
{
	int* x;
	int* y;
	int* RGB;

	x = NULL;
	y = NULL;
	RGB = NULL;

	readMetaData("ex2.pbm", &x, &y, &RGB);

	printf("x: %d\ny: %d\nRGB: %d\n", *x, *y, *RGB);
	
	free(x);
	free(y);
	free(RGB);


	//readMetaData OK!

	return 0;
}