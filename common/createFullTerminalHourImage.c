#include "createFullTerminalHourImage.h"

image * createFullTerminalHourImage(image numbersList[11])
{
	/*Déclaration des variables*/
	
	/*declaration de la variable timestamp de type time_t	
	declaration de la structure t de type tm
	ces variables servent a enregistrer les dates*/
	time_t timestamp;
	struct tm * t;
	
	/*on definit le timestamp en timestamp actuel
	les valeurs enregistrees de dans correspondent au systeme
	ici on initialise les valeurs de la structure t
	au temps local de l'ordinateur*/
	
	timestamp = time(NULL);			
	t = localtime(&timestamp);		

	/*Les variables contenant l'index des images à afficher*/
	int h0;
	int h1;
	int m0;
	int m1;
	int s0;
	int s1;

	image * termBackground;
	image * hourBG;
	int numberWidth = numbersList[0].xDim;
	int numberHeight = numbersList[0].yDim;


	/*Les variables sont déclarées, ont peut maintenant agir dessus*/
	termBackground = createUniformImageTermSize(' ');

	/*
	hourBG est une image vide des dimensions de l'heure
	
	8 * numberwidth -> 2 * heures + 2* : + 2 * minutes + 2* secondes de même largeur
	+3 -> les espaces entre les nombres
	*/
	hourBG = createUniformImage(' ', 8 * numberWidth + 3, numberHeight);


	/*On trouve le chiffre des dizaines et des unités de l'heure, des minutes,
	et des secondes*/
	h0 = (int)t->tm_hour / 10;
	
	h1 = (int)t->tm_hour;
	while(h1 > 9)
		h1 -= 10;

	m0 = (int)t->tm_min / 10;

	m1 = (int)t->tm_min;
	while(m1 > 9)
		m1 -= 10;

	s0 = (int)t->tm_sec / 10;

	s1 = (int)t->tm_sec;
	while(s1 > 9)
		s1 -= 10;

	/*On donne la bonne position aux chiffres sur l'image de bonne taille*/

	numbersList[h0].xPos = 0;
	numbersList[h0].yPos = 0;
	mergeImages(*hourBG, numbersList[h0]);

	numbersList[h1].xPos = numberWidth + 1;
	numbersList[h1].yPos = 0;
	mergeImages(*hourBG, numbersList[h1]);

	numbersList[10].xPos = 2 * numberWidth + 1;
	numbersList[10].yPos = 0;
	mergeImages(*hourBG, numbersList[10]);

	numbersList[m0].xPos = 3 * numberWidth + 1;
	numbersList[m0].yPos = 0;
	mergeImages(*hourBG, numbersList[m0]);

	numbersList[m1].xPos = 4 * numberWidth + 2;
	numbersList[m1].yPos = 0;
	mergeImages(*hourBG, numbersList[m1]);

	numbersList[10].xPos = 5 * numberWidth + 2;
	numbersList[10].yPos = 0;
	mergeImages(*hourBG, numbersList[10]);

	numbersList[s0].xPos = 6 * numberWidth + 2;
	numbersList[s0].yPos = 0;
	mergeImages(*hourBG, numbersList[s0]);

	numbersList[s1].xPos = 7 * numberWidth + 3;
	numbersList[s1].yPos = 0;
	mergeImages(*hourBG, numbersList[s1]);



	/*On centre l'image de l'heure sur l'image de toute la console*/
	centerImage(*termBackground, *hourBG);

	return termBackground;
}