/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   log.c                                           __       __ __	          */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/07 15:57:35 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/09 10:32:01 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"

int		logs(char *ex)
{
	char *level;
	char text[100];
	time_t timestamp;				//declaration de la variable timestamp de type time_t
	struct tm * t;					//declaration de la structure t de type tm
									//ces variables servent a enregistrer les dates

	timestamp = time(NULL);			//on definit le timestamp en timestamp actuel
									//les valeurs enregistrees de dans correspondent au systeme
	t = localtime(&timestamp);		//ici on initialise les valeurs de la structure t
									//au temps local de l'ordinateur

	level = strtok(ex, "ex.");		//tri de l'argument pour enlever le ex de ex1 et le .C de ex1.c

	FILE* file = NULL;				

	file = fopen("log.txt", "a+");	//ouverture du fichier en mode a+ pour ecrire en fin de ligne

	sprintf(text, "%02u/%02u/%04u %02u:%02u:%02u;%s;\n", t->tm_mday, t->tm_mon, t->tm_year, t->tm_hour, t->tm_min, t->tm_sec, level);			//concatenation des dates et des autres parametres dans text

	fputs(text, file);				//ecriture de text dans le fichier log.txt

	fclose(file);					//fermeture du fichier
	
	return 0;
}
