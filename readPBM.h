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

//readMetaData
// OUTPUT - error code
// OUTPUT x - image width
// OUTPUT y - image height
// INPUT fileName - name of image to parse
// NOTE - only accepts RGB images
int readMetaData(char[] fileName, int * x, int * y);

//readPBM
// INPUT fileName - file name
// INPUT imageWifdth - Width of image to parse
// INPUT image Height - Height of image to parse
// OUTPUT output - Array of array of the image to print
int readPBM(char[] fileName, int * imageWidth, int * imageHeight, char ** output[]);