#Exiasaver

ExiaSaver permet d'animer votre terminal UNIX lorsque vous êtes parti en proposant 3 animations différentes

* Statique
* Dynamique (affichage de l'heure avec une horloge)
* Interactive (déplace un symbole sur l'écran à l'aide du clavier)

Tous ces écrans de veille se font à l'aide de la leturede ficchiers PBM et PPM.
Il est possible de configurer ExiaSaver avec ses propres images, et des variables d'environnement

Ces variables d'environnement doivent contenir le chemin vers le dossier contenant les images
* EXIASAVER1_PBM
* EXIASAVER2_PBM
* EXIASAVER3_PBM

Cette variable doit contenir le chemin du dossier contenant les trois exécutables
* EXIASAVER_HOME

Cette variable doit contenir les dimensions des chiffres de l'horloge (sous la forme 3x5, 4x7, 5x9 ..)
* EXIASAVER2_TAILLE

Cette variable change la fréquence à laquelle l'horloge s'actualise
* EXIASAVER2_SLEEP

Pour ajouter les variables environnementales, il suffit de lancer le script shell "prepareTerminal.sh" depuis la racine du projet.
Pour compiler tous les programmes, il faut exécuter le script "make.sh" dans le dossier execfiles. Les executables seront placés dans ce même dossier.
Enfin, pour lancer un screen saver, il faut exécuter le programme "launcher". Ce dernier peut prendre le paramètre "-stats" pour afficher les statistiques.
