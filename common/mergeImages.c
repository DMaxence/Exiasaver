#include "mergeImages.h"

void mergeImages(image biggerImage, image smallerImage)
{
	int i, j;

	for (i = 0; i < biggerImage.xDim; ++i)
	{
		for (j = 0; j < biggerImage.yDim; ++j)
		{
			//Pour chaque case de la plus grande image

			//Si c'est un endroit à modifier
			if ((i >= smallerImage.xPos && i < (smallerImage.xPos + smallerImage.xDim))
				&& j >= smallerImage.yPos && j < (smallerImage.yPos +smallerImage.yDim))
			{
				biggerImage.charArray[i][j].c = smallerImage.charArray[i - smallerImage.xPos][j - smallerImage.yPos].c;

				biggerImage.charArray[i][j].rgb.R = smallerImage.charArray[i - smallerImage.xPos][j - smallerImage.yPos].rgb.R;
				biggerImage.charArray[i][j].rgb.G = smallerImage.charArray[i - smallerImage.xPos][j - smallerImage.yPos].rgb.G;
				biggerImage.charArray[i][j].rgb.B = smallerImage.charArray[i - smallerImage.xPos][j - smallerImage.yPos].rgb.B;
			}
		}
	}
}