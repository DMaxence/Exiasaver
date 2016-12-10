/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   var_env.c                                       __       __ __	          */
/*                                                  |    \  /   |       /\    */
/*   By: mduhoux <maxence.duhoux@viacesi.fr>        |__   \/    |      /  \   */
/*                                                  |     /\    |     /____\  */
/*   Created: 2016/12/10 15:37:18 by mduhoux        |__  /  \ __|__  /      \ */
/*   Updated: 2016/12/10 16:35:19 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"

int		var_env(int saver)
{
	char *exiasaver_home;
	char *exiasaver1_pbm;
	char *exiasaver2_pbm;
	char *exiasaver2_taille;
	char *exiasaver2_sleep;
	char *exiasaver3_pbm;
	char *path;

	exiasaver_home = getenv("EXIASAVER_HOME");
	exiasaver1_pbm = getenv("EXIASAVER1_PBM");
	exiasaver2_pbm = getenv("EXIASAVER2_PBM");
	exiasaver2_taille = getenv("EXIASAVER2_TAILLE");
	exiasaver2_sleep = getenv("EXIASAVER2_SLEEP");
	exiasaver3_pbm = getenv("EXIASAVER3_PBM");
	
	if (exiasaver_home == NULL)
		exiasaver_home = getenv("PWD");
	if (exiasaver1_pbm == NULL)
		exiasaver1_pbm = getenv("PWD");
	if (exiasaver2_pbm == NULL)
		exiasaver2_pbm = getenv("PWD");
	if (exiasaver2_taille == NULL)
		exiasaver2_taille = "5x3";
	if (exiasaver2_sleep == NULL)
		exiasaver2_sleep = "10";
	if (exiasaver3_pbm == NULL)
		exiasaver3_pbm = getenv("PWD");

	switch(saver)
	{
		case 1:
			path[0] = exiasaver1_pbm;
		break;
		case 2:
			path = malloc(sizeof(char) * 3);
			path[0] = exiasaver2_pbm;
			path[1] = exiasaver2_taille;
			path[2] = exiasaver2_sleep;
		break;
		case 3:
			path = malloc(sizeof(char) * 1);
			path[0] = exiasaver3_pbm;
		break;
	}

}
