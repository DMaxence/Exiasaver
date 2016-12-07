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

//readMetaData
// OUTPUT x - image width
// OUTPUT y - image height
// OUTPUT RGB - Whether or not the image is RGB (1 -> black and white ; 3 -> RGB)
// INPUT file - file with fopen, must be opened
// NOTE - only accepts RGB images
// NOTE - Make sure to pass empty pointers that will be mallocced in this func
void readMetaData(FILE * file, int ** x, int ** y, int ** RGB);

//readPBM
// INPUT file - file opended with fopen, and passed through 
// INPUT imageWifdth - Width of image to parse
// INPUT image Height - Height of image to parse
// OUTPUT output - Array of array of the image to print
void readPBM(FILE * file, int * color, int * imageWidth, int * imageHeight, char ** output[]);