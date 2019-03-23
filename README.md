# Labyrinth - 44422

Projet **Labyrinth** de **44422** (groupe **n15**) en **D112** pour le cours de **DEVG4**.

## Débuter

Instructions pour récupérer un copie du projet et le lancer.

### Prérequis

* Git
* Qt Creator 4.8 installé
* Librairies graphiques Qt
* Bibliothèques de test Catch
* Qmake
* Make
* GCC ou autre compilateur C/C++
* Doxygen

### Installation

Récupérez une copie du dépot avec la commande

```bash
git clone https://git.esi-bru.be/44422/DEVG4-D112-2018-19-Labyrinth-Brandt.git
```

ou en téléchargeant l'[archive](https://git.esi-bru.be/44422/DEVG4-D112-2018-19-Labyrinth-Brandt/repository/master/archive.zip) et en la décompressant.

Importez le projet dans **Qt Creator** en allant dans `Fichier > Ouvrir un fichier ou Projet` et en sélectionnant le fichier `.pro` du projet.

### Lancement

#### Dans QtCreator

1. Choisissez le profil Realease.
2. Compilez le projet (Ctrl + B)

#### Compilation avec CMake

```
cmake.exe --build ${dossier du projet}/cmake-build-debug --target Build -- -j 2
```

avec `-j 2` pour 2 threads actifs en parallèle pour la compilation

#### Utilisation Build fournis

Dans la section `tags` du repository, se trouvent différents builds du projet à différents stades.
Les builds sont nommés de la façon suivante : `v a.b build yyy-mm-dd-hhmm` avec :

* a la version majeure du projet
* b la version mineure du projet
* yyyy l'année du build
* mm le mois du build
* dd le jour du build
* hhmm l'heure du build (heure et minutes)

### Lancer les tests

*À venir...*

### Générer le documentation

#### Avec le plugin Doxygen pour Qt Creator

Aller dans `Outils > Doxygen > Document current project` ou `Ctrl + Maj + F8`.

## Organisation

Basé sur le pattern **MVC**

* le sous-projet **core** conteant le modèle (remise 2+)
* le sous-projet **console** contenant la vue console et le contrôleur console (remise 3+)
* le sous-projet **gui** contenant la vue graphique et le contrôleur graphique (remise 3+)
* le sous-projet **test** conteant les tests (librairie Catch2) (remise 2+)

## Auteur

* **Brandt Matthieu** aka. **44422**

## License

Ce projet est sous license `Creative Commons Attribution-NonCommercial 4.0 International Public License`.

Plus de détails dans le fichier `LICENCE.md`
