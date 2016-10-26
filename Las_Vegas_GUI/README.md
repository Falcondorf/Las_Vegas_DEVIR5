# Rapport:
- **Etat du projet:**
Le projet est terminé et fonctionnel tel qu'il est.
- **Fonctionnement:**
L'application graphique lance une première fenêtre de lancement; 
après avoir cliqué sur START, une nouvelle fenêtre formulaire s'affiche afin de sélectionner les paramètres de jeux.
 + On sélectionne le nombre de joueur dans une spinbox.
 + Une checkbox permet d'afficher ou cacher les paramètres d'extension
 + Trois radio (par défaut sur la radio "pas d'extension") donc on ne sais joué que sur une seule extension ou aucune.

Une fois le jeu lancé, la fenêtre est d'abord divisé en deux panneaux. Celui de gauche représente tout les casinos avec les
 billets et les paris des joueurs. Celui de droite contient les informations du joueur courant, sa réserve de dé ainsi que 
 des boutons pour lancer les dés et placer un pari. Les deux boutons sont dépendant l'un de l'autre, on doit lancer les dés avant 
 de pouvoir parier.
 
- **Problèmes:**
Lors d'une partie en extension avec les gros dé, l'affichage du nombre de dés restant dans le panneau d'information du joueur
 n'est pas correct.
