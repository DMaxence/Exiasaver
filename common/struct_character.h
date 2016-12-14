#pragma once

/*Couleur Red Green Blue
de 0 à 255*/
struct color
{
	unsigned int R;
	unsigned int G;
	unsigned int B;
};
typedef struct color color;

/*Un caractère occupe un 'pixel' dans le terminal
Il s'agit d'un caractère et d'une couleur*/
struct character
{
	color rgb;
	char c;
};
typedef struct character character;