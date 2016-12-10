//HEADER PLS

#pragma once
#include "struct_image.h"
#include "doubleArrayMemory.h"
//#include "../launcher/getTerminalSize.h" j'aurai préféré ça mais bon
#include "../launcher/launcher.h"


//createUniformImageTermSize
//Crée une image uniforme des dimensions du terminal
//INPUT fillCharacter - replir l'image de ce caracère là.
image * createUniformImageTermSize(char fillCharacter);