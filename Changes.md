# Changements

Ce fichier reprend les changements par rapport au modèle métier remis lors de la remise n°1.

* 28/02/2019
  * utilisation d'un `unsigned int` plutôt qu'un `int` pour l'attribut `minPlayers` de la classe `Game` puisque le nombre minimum de joueurs ne peut pas être négatif
  * utilisation d'un `unsigned int` plutôt qu'un `int` pour l'attribut `maxPlayers` de la classe `Game` puisque le nombre maximum de joueurs ne peut pas être négatif
  * utilisation d'un `unsigned int` plutôt qu'un `int` pour l'attribut `currentPlayerIndex` de la classe `Game` puisque l'index d'un tableau ne peut pas être négatif
* 01/03/2019
  * ajout d'un getter pour l'attribut privé `minPlayers` de la classe `Game` en prévision d'un futur éventuel accès
  * ajout d'un getter pour l'attribut privé `maxPlayers` de la classe `Game` en prévision d'un futur éventuel accès
  * utilisation d'un `unsigned int` plutôt qu'un `int` pour l'attribut `positionVerticale` de la classe `Player` puisque la position verticale d'un joueur ne peut pas être négative
  * utilisation d'un `unsigned int` plutôt qu'un `int` pour l'attribut `positionHorizontale` de la classe `Player` puisque la position horizontale d'un joueur ne peut pas être négative
  * ajout d'un getter pour l'attribut privé `positionVerticale` de la classe `Player` en prévision d'un futur éventuel accès
  * ajout d'un getter pour l'attribut privé `positionHorizontale` de la classe `Player` en prévision d'un futur éventuel accès
  * utilisation d'un `unsigned int` plutôt qu'un `int` pour la méthode `getObjectiveCount` de la classe `Player` puisque le nombre d'objectifs d'un joueur ne peut pas être négatif
  * utilisation d'un `unsigned int` plutôt qu'un `int` pour l'attribut `startNumber` de la classe `Tile` puisque le numéro de départ d'un joueur ne peut pas être négatif
  * ajout d'un getter pour l'attribut privé `movable` de la classe `Tile` en prévision d'un futur éventuel accès
  * ajout d'un getter pour l'attribut privé `sizeHorizontal` de la classe `Board` en prévision d'un futur éventuel accès
  * ajout d'un getter pour l'attribut privé `sizeVertical` de la classe `Board` en prévision d'un futur éventuel accès
