/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   log.c                                           __       __ __	          */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/07 15:57:35 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/12 15:28:25 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"

int		logs(int screenSaverToLaunch, char *argumentsList[4])
{
	int i;
	char text[100];
	/*declaration de la variable timestamp de type time_t*/
	time_t timestamp;
	struct tm * t;

	/*on definit le timestamp en timestamp actuel
	les valeurs enregistrees de dans correspondent au systeme*/
	timestamp = time(NULL);			

	/*ici on initialise les valeurs de la structure t
	au temps local de l'ordinateur*/
	t = localtime(&timestamp);


	FILE* file = NULL;				

	/*ouverture du fichier en mode a+ pour ecrire en fin de ligne*/
	file = fopen("log.txt", "a+");
	switch(screenSaverToLaunch)
	{
		case 1:
			i = 0;
		break;
		case 2:
			i = 1;
		break;
		case 3:
			i = 0;
		break;
	}
	sprintf(text, "%02u/%02u/%04u %02u:%02u:%02u;%d;%s;\n", t->tm_mday, t->tm_mon,1900 + t->tm_year, t->tm_hour, t->tm_min, t->tm_sec, screenSaverToLaunch, argumentsList[i]);			//concatenation des dates et des autres parametres dans text

	/*ecriture de text dans le fichier log.txt*/
	fputs(text, file);

	/*fermeture du fichier*/
	fclose(file);
	
	return 0;
}