
# Panneau de contrôle domotique

Ce projet utilise principalement le logiciel TouchGFX développé par STMicroelectronics, la même entreprise qui a conçu la carte que nous utilisons ce semestre. Cela facilite donc la compatibilité et l'interfaçabilité entre TouchGFX et STM32CubeIDE.

Le plus gros du projet est réalisé sous le logiciel TouchGFX grâce à son interface utilisateur extrêmement simple à comprendre mais toutefois efficace. On peut dessus y définir différents écrans, les transitions entre ces écrans. A l'intérieur de ces écrans, on peut ajouter des "widgets" mis à disposition par le logiciel et qui permettent de réaliser la plupart de ce qu'on peut attendre d'une interface homme-machine (boutons, curseurs, graphiques...).

L'action réalisée lorsqu'on interagit avec un de ces widgets est nommée "interaction". Deux possibilités s'offrent à nous :
- Utiliser une interaction classique proposée par le logiciel (passer d'un écran à un autre, afficher une image, etc...)
- Faire appel à une interaction personnalisée que l'on va nous même comprendre

La première possibiltié est utilisée dans le projet (changement d'écran, changement d'image lorsqu'on clique sur un bouton...) mais c'est la deuxième qui est la plus intéréssante et qui permet d'utiliser toutes les capacités de TouchGFX.

On retrouve la déclaration de ces fonctions dans le fichier *RadiatorView.hpp* et leur code dans le fichier *RadiatorView.cpp*. 

On va prendre pour exemple la fonction principale qui gère l'évolution du graphe dynamique :

```cpp
void RadiatorView::handleTickEvent()
{
	tickCounter = tickCounter + 1;

	if (tickCounter % 3 == 0){
		dynamicGraph1.addDataPoint(counter);
		if (cur_temp < counter - 2){
			pente = 0.5;
		}
		else if (cur_temp > counter + 2){
			pente = -0.1;
		}
		cur_temp = cur_temp + pente;
		dynamicGraph2.addDataPoint(cur_temp);
	}
}
```

Ici, on actualise le graphe tous les 3 "tick events". La courbe de référence est toujours la même, la courbe *réelle* est quant à elle recalculer suivant son positionnement relatif par rapport à la consigne (commande tout ou rien relativement simple).

On peut alors compiler et téléverser sur la carte. Le lien entre les deux logiciels est immédiat, il n'y a aucun problème de désynchronisation du projet. 

On observe au final un rendu relativement *professionnel* obtenu beaucoup plus facilement que s'il avait fallu définir de nombreuses images via les fonctions de base liées à la carte.