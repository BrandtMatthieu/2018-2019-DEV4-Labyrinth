# Avertissements

## Remise 3
* Mêmes avertissements qu'à la remise 2
* `gui/source/guiView.cpp`
  * ligne 50: prise d'une valeur d'enum depuis un entier
  * ligne 116: prise d'une valeur d'enum depuis un entier
* `core/controller/source/controllerGUI.cpp`
  * ligne 13: la classe `ControllerGUI` n'a pas d'`operator=`, ce qui est recommandé pour les classes demandant de l'allocation de mémoire (pas nécessaire dans ce cas-ci de l'implémenter)
* `core/controller/include/controllerGUI.h`
  * ligne 32: le constructeur par copie est mis à `default`, ce qui n'est pas recommandé dans les classes demandant de l'allocation de mémoire (pas nécessaire dans ce cas-ci de l'implémenter)

## Remise 2

* `console/source/controllerConsole.cpp`
  * ligne 107: incompatibilité de types. `regex_search` attend un `const char *` et non un `std::string` pour le premier paramètre (`answer`).
  * ligne 107: incompatibilité de types. `regex_search` attend un `const char *` et non un `std::string` pour le deuxième paramètre (`sideMatch`).
  * ligne 125: incompatibilité de types. `regex_search` attend un `const char *` et non un `std::string` pour le premier paramètre (`answer`).
  * ligne 125: incompatibilité de types. `regex_search` attend un `const char *` et non un `std::string` pour le deuxième paramètre (`positionMatch`).
  * ligne 173: incompatibilité de types. `regex_search` attend un `const char *` et non un `std::string` pour le premier paramètre (`answer`).
  * ligne 173: incompatibilité de types. `regex_search` attend un `const char *` et non un `std::string` pour le deuxième paramètre (`matchCoo`).
* `core/model/include/board.h`
  * ligne 47: la fonction `setTile` n'est jamais utilisée. La fonction a été crée en prévision d'une éventuelle utilisation future.
  * ligne 48: la fonction `setTile` n'est jamais utilisée. La fonction a été crée en prévision d'une éventuelle utilisation future.
* `console/include/consoleView.h`
  * ligne 43: la fonction `printGameInfos` n'est jamais utilisée. La fonction a été crée en prévision d'une éventuelle utilisation future.
  * ligne 57: la fonction `clearScreen` n'est jamais utilisée. La fonction a été crée en prévision d'une éventuelle utilisation future.
* `core/model/include/player.h`
  * ligne 44: la fonction `getCompletedObjectiveCards` n'est jamais utilisée. La fonction a été crée en prévision d'une éventuelle utilisation future.
  * ligne 52: la fonction `**getCompletedObjectiveCards**` n'est jamais utilisée. La fonction a été crée en prévision d'une éventuelle utilisation future.
* `core/model/include/position.h`
  * ligne 33: la fonction `move` n'est jamais utilisée. La fonction a été crée en prévision d'une éventuelle utilisation future.
  * ligne 35: la fonction `move` n'est jamais utilisée. La fonction a été crée en prévision d'une éventuelle utilisation future.
* `core/model/include/tile.h`
  * ligne 59: la fonction `rotateRight90` n'est jamais utilisée. La fonction a été crée en prévision d'une éventuelle utilisation future.
