# Changements

Ce fichier reprend les changements par rapport au modèle métier remis lors de la remise n°1.

* 28/02/2019
    * utilisation d'un `unsigned int` plutôt qu'un `int` pour l'attribut `minPlayers` de la classe `Game` puisque le nombre minimum de joueurs ne peut pas être négatif
    * utilisation d'un `unsigned int` plutôt qu'un `int` pour l'attribut `maxPlayers` de la classe `Game` puisque le nombre maximum de joueurs ne peut pas être négatif
    * utilisation d'un `unsigned int` plutôt qu'un `int` pour l'attribut `currentPlayerIndex` de la classe `Game` puisque l'index d'un tableau ne peut pas être négatif
	* ajout d'un getter pour l'attribut privé `minPlayers` de la classe `Game` en prévision d'un futur éventuel accès
	* ajout d'un getter pour l'attribut privé `maxPlayers` de la classe `Game` en prévision d'un futur éventuel accès
