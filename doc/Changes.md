# Changements

Ce fichier reprend les changements par rapport au modèle métier remis lors de la remise n°1.

## Remise 3

* Ajout d'une méthode `canCurrentPlayerInsertTile` dans la classe `Game`
* Ajout d'une méthode `canCurrentGoTo` dans la classe `Game`
* Ajout d'une méthode overloadée `canInsertTile` dans la classe `Board`

## Remise 2

* Création d'une classe `ConsoleView` avec des méthodes responsable pour l'affichage
  * Création de l'attribut privé `pathSize`
  * Création de l'attribut privé `tileSize`
  * Création de l'attribut privé `wall1`
  * Création de l'attribut privé `wall2`
  * Création de l'attribut privé `wall`
  * Création de l'attribut privé `path`
  * Création de l'attribut privé `space`
  * Création de l'attribut privé `objective`
  * Création de l'attribut privé `spacing`
  * Création de l'attribut privé `arrows`
  * Création de la méthode privée `printTileLine`
  * Création de la méthode publique `getYesNoAnswer`
  * Création de la méthode publique `getNewPlayerName`
  * Création de la méthode publique `getCommand`
  * Création de la méthode publique `printGameInfos`
  * Création de la méthode publique `printBoard`
  * Création de la méthode publique `printPlayerInfos`
  * Création de la méthode publique `printWinner`
  * Création de la méthode publique `printMessage`
  * Création de la méthode publique `printError`
  * Création de la méthode publique `printHelp`
  * Création de la méthode publique `printWelcome`
  * Création de la méthode publique `printInstructions`
  * Création de la méthode publique `printTile`
  * Création de la méthode publique `printBoardObjectives`
  * Création de la méthode publique `printAvailableTile`
  * Création de la méthode publique `printPlayersInfos`
  * Création de la méthode publique `clearScreen`
  * Création de la méthode publique `lineBreak`
* Création d'une classe `ControllerConsole` avec des méthodes responsable pour l'affichage
    * Création de l'attribut privé `consoleView`
    * Création de l'attribut privé `game`
    * Création de la méthode privée `start`
* Modification de la classe `Board`
  * Replacement des attributs privés `sizeHorizontal` et `sizeVertical` par l'attribut privé `maxSize`
  * Création de l'attribut privé `playersDefaultPositions`
  * Création de la méthode privée `indexOf`
  * Création de la méthode privée `includes`
  * Création de la méthode publique `getMaxSize`
  * Création de la méthode publique `getMaxSizeX`
  * Création de la méthode publique `getMaxSizeY`
  * Création de la méthode publique `isPositionInsideBoard`
  * Création de la méthode publique `getTilesCount`
  * Création de la méthode publique `getTilesAt`
  * Création de la méthode publique `setTile`
  * Création de la méthode publique `getPlayersDefaultPositions`
  * Création de la méthode publique `getUnmovableTilesPositions`
  * Création de la méthode publique `hasEmptyTiles`
  * Création de la méthode publique `getEmptyTile`
* Modification de la classe `Game`
  * Création de l'attribut privé `playerColors`
  * Création de l'attribut privé `objectiveCards`
  * Création de la méthode privée `getFirstPlayerColor`
  * Création de la méthode privée `getFirstGameObjective`
  * Création de la méthode privée `generateObjectiveCards`
  * Création de la méthode privée `playersFixPosition`
  * Création de l'attribut publique `gameObjectives`
  * Création de la méthode publique `getMinPlayers`
  * Création de la méthode publique `getMaxPlayers`
  * Création de la méthode publique `getPlayerAt`
  * Création de la méthode publique `getPlayersCount`
  * Création de la méthode publique `hasEnoughPlayers`
  * Création de la méthode publique `hasWinner`
  * Création de la méthode publique `getCurrentPlayer`
  * Création de la méthode publique `dealObjectiveCardsToPlayers`
  * Création de la méthode publique `generateTiles`
  * Création de la méthode publique `currentPlayerCheckObjective`
  * Création de la méthode publique `currentPlayerInsertTile`
  * Création de la méthode publique `currentPlayerGoTo`
  * Création de la méthode publique `canCurrentPlayerGoTo`
* Création de l'énumération `InsertSide`
  * Création de la méthode publique `hasObjective`
* Supression de la classe `ObjectiveType`
* Supression de la classe `TileType`
* Supression de la classe `Colors`
* Modification de la classe `Player`
  * Replacement des attributs privés `positionHorizontale` et `positionVerticale` par l'attribut privé `position`
  * Renommage de l'attribut privé `objectiveCards` par `objectiveCardsLeft`
  * Création de l'attribut privé `completedObjectiveCards`
  * Création de l'attribut privé `_hasInsertedTile`
  * Création de l'attribut privé `_hasMovedPawn`
  * Création de la méthode publique `getPosition`
  * Création de la méthode publique `getCompletedObjectiveCards`
  * Création de la méthode publique `getCompletedObjectiveCardsCount`
  * Création de la méthode publique `getObjectiveCardsLeft`
  * Création de la méthode publique `getObjectiveCardsLeftCount`
  * Création de la méthode publique `addObjective`
  * Création de la méthode publique `hasInsertedTile`
  * Création de la méthode publique `hasMovedPawn`
* Création de la classe `Position`
  * Création de l'attribut privé `x`
  * Création de l'attribut privé `y`
  * Création de la méthode publique `getX`
  * Création de la méthode publique `getT`
  * Création de la méthode publique `move`
  * Création de la méthode publique `set`
  * Création de la méthode publique `toString`
* Modification de la classe `Tile`
  * Supression de l'attribut privé `type`
  * Création de l'attribut privé `pathUP`
  * Création de l'attribut privé `pathDOWN`
  * Création de l'attribut privé `pathRIGHT`
  * Création de l'attribut privé `pathLEFT`
  * Création de l'attribut privé `position`
  * Création de la méthode publique `getPathUP`
  * Création de la méthode publique `getPathDOWN`
  * Création de la méthode publique `getPathRIGHT`
  * Création de la méthode publique `getPathLEFT`
  * Création de la méthode publique `getPosition`
  * Création de la méthode publique `isMovable`
  * Création de la méthode publique `hasObjective`
  * Création de la méthode publique `hasStartNumber`
  * Création de la méthode publique `setPosition`
  * Création de la méthode publique `rotateRight90`
  * Création de la méthode publique `rotateLeft90`
  * Création de la méthode publique `move`
