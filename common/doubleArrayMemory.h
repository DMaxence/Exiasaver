//METTRE UN HEADER


#pragma once
#include "struct_character.h"
#include <stdlib.h>
#include <stdio.h>

//On utilise cette fonction pour allouer la mémoire à un tableau 2 dimensions de character
// INPUT nbLin, nbCol - nombre de colonnes et de lignes du tableau
character **createTable(int nbLin, int nbCol);

//On utilise cette fonction pour libérer la mémoire d'un tableau 2D
// INPUT / OUTPUT array - le tableau
// INPUT nbLin - le nombre de lignes du tableau
void freeTable(int **array, int nbLin);

//On utilise cette fonction pour afficher un tableau 2D
// INPUT array - Le tableau à afficher
void printArray(character ** array, int nbLin, int nbCol);