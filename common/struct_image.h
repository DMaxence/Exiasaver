//HEADER

#pragma once
#include "struct_character.h"


/*La struct image est une image convertie en character
Ainsi que ses dimensions et sa position*/
struct image
{
	character ** charArray;

	int xPos;
	int yPos;

	int xDim;
	int yDim;
};
typedef struct image image;