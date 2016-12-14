#include "createFullTerminalHourImage.h"

image * createFullTerminalHourImage(image numbersList[11])
{
	//Déclaration des variables
	time_t timestamp;				//declaration de la variable timestamp de type time_t
	struct tm * t;					//declaration de la structure t de type tm
									//ces variables servent a enregistrer les dates

	timestamp = time(NULL);			//on definit le timestamp en timestamp actuel
									//les valeurs enregistrees de dans correspondent au systeme
	t = localtime(&timestamp);		//ici on initialise les valeurs de la structure t
									//au temps local de l'ordinateur

	//Les variables contenant l'index des 
	int h0;
	int h1;
	int m0;
	int m1;
	int s0;
	int s1;

	image * termBackground;
	int numberWidth = numbersList[0].xDim;
	int numberHeight = numbersList[0].yDim;


	//Début fonction
	termBackground = createUniformImageTermSize(' ');

	image * hourBG = createUniformImage(' ', 8 * numberWidth + 3, numberHeight);

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



	//ETAPE 6: Centrer l'image de l'heure sur celle du terminal
	centerImage(*termBackground, *hourBG);
	//ETAPE 6.5: TODO Rajouter le texte d'actualisation
	return termBackground;
	//ETAPE 7: Afficher l'image

}