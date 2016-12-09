#pragma once
#include "struct_image.h"
#include <stdio.h>

//printImage
// INPUT img - L'image à afficher
// NOTE : On utilise un pointeur car une image peut être relativement lourde.
void printImage(image * img);