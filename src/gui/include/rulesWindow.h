#ifndef RULESWINDOW_H
#define RULESWINDOW_H

#include <QMessageBox>
#include <QWidget>

namespace Labyrinth_44422 {
	namespace gui {

		/**
		 * Represents dialog windows with the rules of the game
		 * @author 44422
		 * @version 0.1.0
		 * @since 2019-04-29
		 */
		class RulesWindow : public QDialog {

				Q_OBJECT

			private:
				QString rules = ""
								"Regles :\n"
								"========\n"
								"    Dans un labyrinthe enchante, les joueurs partent a la chasse aux objets et aux creatures magiques. Chacun cherche a se frayer un chemin jusqu'a eux en faisant coulisser astucieusement les couloirs.\n"
								"Le premier joueur a decouvrir tous ses secrets et a revenir a son point de depart remporte cette passionnante chasse aux tresors.\n\n"
								"Deroulement :\n"
								"=============\n"
								"    Chaque joueur se voit attribue differents objectifs a aller chercher dans le labyrinthe.\n"
								"Un tour se compose toujours de deux phases :\n"
								"    1. Introduction de la carte couloir supplementaire\n"
								"    2. Deplacement du pion\n"
								"A son tour de jeu, le joueur doit essayer d'atteindre la tuile comportant le meme objectif que celui squi lui est actuellement attribue\n"
								"Pour cela il commence toujours par faire coulisser une rangee ou une colonne du labyrinthe en inserant la plaque supplementaire du bord vers l'interieur du plateau, puis il deplace son pion.\n\n"
								"Modification du labyrinthe :\n"
								"============================\n"
								"    12 fleches sont dessinees en bordure de plateau.\n"
								"Elles indiquent les rangees et colonnes où peut etre inseree la plaque supplementaire pour modifier les couloirs du labyrinthe.\n"
								"Quand vient son tour, le joueur choisit l'une de ces rangees ou colonnes et pousse la plaque supplementaire vers l'interieur du plateau jusqu'a ce qu'une nouvelle plaque soit expulsee a l'oppose.\n"
								"La plaque expulsee reste au bord du plateau jusqu'a ce qu'elle soit reintroduite a un autre endroit par le joueur suivant.\n\n"
								"Deplacement du pion :\n"
								"=====================\n"
								"    Des qu'il a modifie le labyrinthe, le joueur peut deplacer son pion. Il peut le deplacer aussi loin qu'il veut jusqu'a n'importe quelle plaque en suivant un couloir ininterrompu.\n"
								"Un joueur peut meme s'arreter sur une case deja occupee. S'il veut, il peut aussi choisir de rester sur place ; il n'est pas oblige de se deplacer.\n"
								"Si le joueur n'atteint pas le dessin recherche (= celui fi gurant sur la carte superieure de sa pile), il peut deplacer son pion aussi loin qu'il veut de maniere a etre en bonne position pour le prochain tour.\n"
								"S'il atteint le dessin recherche, il retourne sa carte a côte de sa pile. Il peut immediatement regarder secretement la carte suivante de sa pile pour connaître son prochain objectif.\n"
								"C'est maintenant au tour du joueur suivant de jouer.\n\n"
								"Fin du jeu :\n"
								"============\n"
								"    La partie s'arrete des qu'un joueur a atteint tous ses objectifs et qu'il est revenu a son point de depart.";

			public:

				explicit RulesWindow(QWidget *parent);

				~RulesWindow() = default;
		};

	} // namespace gui
} // namespace Labyrinth_44422

#endif
