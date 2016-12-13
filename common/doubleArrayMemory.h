//METTRE UN HEADER


#pragma once
#include "struct_character.h"
#include <stdlib.h>
#include <stdio.h>

/*On utilise cette fonction pour allouer la mémoire à un tableau 2 dimensions de character
INPUT nbLin, nbCol - nombre de colonnes et de lignes du tableau*/
character **createTable(int nbCol, int nbLin);

/*On utilise cette fonction pour libérer la mémoire d'un tableau 2D
INPUT / OUTPUT array - le tableau
INPUT nbLin - le nombre de lignes du tableau
NOTE : Fonctionnelle? à vérifier
NOTE : :'( pourquoi pas les unique_ptr du C++ je pleure très fort*/
void freeTable(character **array, int nbLin);