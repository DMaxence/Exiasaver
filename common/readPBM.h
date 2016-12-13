/* ************************************************************************** */
/*                                                                            */
/*                    	                                     	              */
/*   readPBM.h		                        __        __ __          	      */
/*                                         |     \  /   |       /\            */
/*   By: Groupe 2                          |__    \/    |      /  \           */
/*			       		                   |      /\    |     /____\          */
/*   				        			   |__   /  \ __|__  /      \         */
/*							   					          		              */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_character.h"
#include "struct_image.h"
#include "doubleArrayMemory.h"

/*readMetaData
OUTPUT x - largeur de l'image
OUTPUT y - hauteur de l'image
OUTPUT RGB - En quel mode de couleur est l'image (1 -> black and white ; 3 -> RGB)
INPUT file - Un stream de fichier. Doit être ouvert avec fopen.
NOTE - Les pointeurs doivent être vides et seront malloc*/
void readMetaData(FILE * file, int * x, int * y, int * RGB);

/*readPBMFromFile
INPUT file - stream de fichier. Doit être ouvert avec fopen.
INPUT imageWidth - Largeur de l'image à parser
INPUT imageHeight - Hauteur de l'image à parser
OUTPUT output - Tableau 2D contenant les données de l'image*/
void readPBMFromFile(FILE * file, int * color, int * imageWidth, int * imageHeight, character *** output);

/*readPBM
INPUT fileName - la destination vers le fichier PBM
OUTPUT output - un tableau double entrée de charactères correspondant à l'image.*/
void readPBM(char fileName[], image * output);