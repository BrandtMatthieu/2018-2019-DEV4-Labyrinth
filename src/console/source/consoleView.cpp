#include <algorithm>
#include <iostream>

#include "./../include/consoleView.h"

class Position;
namespace Labyrinth_44422 {
	namespace console {

		/**
		 * Prints an horizontal line in the tile
		 * @param tile the tile to print the line from
		 * @param ligneDansTuile the height to print the line of the tile from
		 * @param str the existing string to get the text to append to from
		 * @throw invalid_argument if tile is null
		 * @throw invalid_argument if ligneDansTuile is null
		 * @return a string with the line printed at the specified height
		 */
		void ConsoleView::printTileLine(const Labyrinth_44422::model::Tile * const tile, const unsigned int & ligneDansTuile, std::string & str) const {
			if(tile == nullptr) {
				throw std::invalid_argument("Error while printing the tile. No tile provided.");
			}
			if(ligneDansTuile >= this->tileSize) {
				throw std::invalid_argument("Error while printing the tile. Tile line is out of bounds.");
			}

			for(unsigned int caractereDeTuile = 0; caractereDeTuile < this->tileSize; caractereDeTuile++) {
				if(ligneDansTuile < this->wall1) {
					if(caractereDeTuile < this->wall1 || caractereDeTuile > this->wall2) {
						str += space;
					} else if(caractereDeTuile == this->wall1 || caractereDeTuile == this->wall2) {
						if(tile->getPathUP()) {
							str += wall;
						} else {
							str += space;
						}
					} else if(caractereDeTuile > this->wall1 || caractereDeTuile < this->wall2) {
						if(tile->getPathUP()) {
							str += path;
						} else {
							str += space;
						}
					}
				} else if(ligneDansTuile == this->wall1 || ligneDansTuile == this->wall2) {
					if(caractereDeTuile < this->wall1) {
						if(tile->getPathLEFT()) {
							str += wall;
						} else {
							str += space;
						}
					} else if (caractereDeTuile > this->wall2) {
						if(tile->getPathRIGHT()) {
							str += wall;
						} else {
							str += space;
						}
					} else if (caractereDeTuile > this->wall1 && caractereDeTuile < this->wall2) {
						if(ligneDansTuile == wall1) {
							if(tile->getPathUP()) {
								str += path;
							} else {
								str += wall;
							}
						} else if (ligneDansTuile == wall2) {
							if(tile->getPathDOWN()) {
								str += path;
							} else {
								str += wall;
							}
						}
					} else {
						str += wall;
					}
				} else if(ligneDansTuile > this->wall1 && ligneDansTuile < this->wall2) {
					if(caractereDeTuile < this->wall1) {
						if(tile->getPathLEFT()) {
							str += path;
						} else {
							str += space;
						}
					} else if(caractereDeTuile > this->wall2) {
						if(tile->getPathRIGHT()) {
							str += path;
						} else {
							str += space;
						}
					} else if(caractereDeTuile == wall1){
						if(tile->getPathLEFT()) {
							str += path;
						} else {
							str += wall;
						}
					} else if(caractereDeTuile == wall2) {
						if(tile->getPathRIGHT()) {
							str += path;
						} else {
							str += wall;
						}
					} else {
						if(caractereDeTuile == this->tileSize / 2 && ligneDansTuile == this->tileSize / 2 && tile->hasStartNumber()) {
							str += std::to_string(tile->getStartNumber());
						} else if(tile->hasObjective() && tile->getObjective().length() >= 3 && std::abs(static_cast<int>(caractereDeTuile - this->tileSize / 2)) <= 1 && ligneDansTuile == this->tileSize / 2) {
							str += tile->getObjective().at(1 + (caractereDeTuile - this->tileSize / 2));
						} else if(tile->hasObjective() && tile->getObjective().length() >= 1 && caractereDeTuile == this->tileSize / 2 && ligneDansTuile == this->tileSize / 2 && tile->hasStartNumber()) {
							str += tile->getObjective().at(0);
						} else if(tile->hasObjective() && caractereDeTuile == this->tileSize / 2 && ligneDansTuile == this->tileSize / 2 && tile->hasStartNumber()) {
							str += "?";
						} else {
							str += path;
						}
					}
				} else if (ligneDansTuile > this->wall2) {
					if(caractereDeTuile < this->wall1 || caractereDeTuile > this->wall2) {
						str += space;
					} else if(caractereDeTuile == this->wall1 || caractereDeTuile == this->wall2) {
						if(tile->getPathDOWN()) {
							str += wall;
						} else {
							str += space;
						}
					} else if(caractereDeTuile > this->wall1 || caractereDeTuile < this->wall2) {
						if(tile->getPathDOWN()) {
							str += path;
						} else {
							str += space;
						}
					}
				}
			}
		}

		/**
		 * Gets a yes or no answer from the user
		 * @param message the message to ask something to the player and wait for a yes or no answer
		 * @return the answer of the player as a boolean
		 */
		bool ConsoleView::getYesNoAnswer(const std::string & message) const {
			this->lineBreak();
			this->printMessage(message + " [ yes | no ]");
			std::cout << "\n> ";
			std::string answer;
			while(answer != "yes" && answer != "y" && answer != "n" && answer != "no") {
				std::getline(std::cin, answer);
				std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
				if(answer != "yes" && answer != "y" && answer != "n" && answer != "no") {
					this->lineBreak();
					this->printError("Invalid answer. Please only answer with [ yes ] or [ no ].");
					std::cout << "\n> ";
				}
			}
			return answer == "yes" || answer == "y";
		}

		/**
		 * Creates a new console view
		 * @param spacing if there needs to be spaces between the rows and lines of the board printed
		 * @param arrows if there needs to be arrows in front of the lines of the board that can be moved
		 */
		ConsoleView::ConsoleView(const bool spacing, const bool arrows) :
			wall{"X"},
			path{" "},
			space{"."},
			objective{"O"},
			spacing{spacing},
			arrows{arrows} {
		}

		/**
		 * Creates a new console view from an existing one
		 * aka. copy constructor
		 * @param vue the existing view to take the infos from
		 */
		ConsoleView::ConsoleView(const ConsoleView & vue) :
			wall{vue.wall},
			path{vue.path},
			space{vue.space},
			objective{vue.objective},
			spacing{vue.spacing},
			arrows{vue.arrows} {
		}

		/**
		 * Asks the name for the new player in the game
		 * @return the name of the new player
		 */
		std::string ConsoleView::getNewPlayerName(void) const {
			this->lineBreak();
			this->printMessage("Please enter a name for this player.");
			std::cout << "\n> ";
			std::string answer;
			while(answer.empty()) {
				std::getline(std::cin, answer);
				if(answer.empty()) {
					this->printError("Invalid name. Please enter a name for this player.");
					std::cout << "\n> ";
				}
			}
			return answer;
		}

		/**
		 * Returns the command entered by the player
		 * @return the command entered by the player
		 */
		std::string ConsoleView::getCommand(void) const {
			this->lineBreak();
			this->printMessage("Please enter a command.");
			this->printMessage("Type \"help\" to get a list of all the available commands.");
			this->lineBreak();
			std::cout << "> ";
			std::string answer;
			std::getline(std::cin, answer);
			return answer;
		}

		/**
		 * Prints the infos of the game
		 * @param game the game to print the infos from
		 * @throw invalid_argument if game is null
		 */
		void ConsoleView::printGameInfos(const model::Game * const game) const {
			if(game == nullptr) {
				throw std::invalid_argument("Error while printing game infos. Game does not exists.");
			}

			std::cout << std::endl << "Game infos : " << std::endl;
			if(game->hasWinner()) {
				this->printMessage("Game is over.");
				this->printMessage("Winner : " + game->getWinner()->getNickname());
			} else {
				this->printMessage("Game is still in progress...");
				this->printMessage("Current player : " + game->getCurrentPlayer()->getNickname());
				this->printMessage("Objective left count for each player : ");
				this->printPlayersInfos(game->getPlayers());
			}

		}

		/**
		 * Prints the board of the game
		 * @param board the board to print
		 * @throw invalid_argument if game is null
		 */
		void ConsoleView::printBoard(const model::Board * const board) const {
			if(board == nullptr) {
				throw std::invalid_argument("Error while printing board. Board doesn't exists.");
			}

			std::string str = "";
			if(this->arrows) {
				str += "  ";
				for(unsigned int tuileDansRangee = 0; tuileDansRangee < board->getMaxSizeX(); tuileDansRangee++) {
					for(unsigned int caractereDeTuile = 0; caractereDeTuile < this->tileSize; caractereDeTuile++) {
						if(caractereDeTuile == this->tileSize / 2 && board->canInsertTile(model::Position{tuileDansRangee, 0}, model::InsertSide::DOWN)) {
							str += "v"; // v ↓
						} else {
							str += " ";
						}
					}
					if(this->spacing) {
						str += " ";
					}
				}
				str += "\n";
			}
			this->printMessage(str);
			for(unsigned int rangeeDeTuile = 0; rangeeDeTuile < board->getMaxSizeY(); rangeeDeTuile++) { // chaque ligne de tuile
				for(unsigned int ligneDansTuile = 0; ligneDansTuile < this->tileSize; ligneDansTuile++) { // ligne horizontale dans tuile
					str = "";
					if(this->arrows && ligneDansTuile == this->tileSize / 2 && board->canInsertTile(model::Position{0, rangeeDeTuile}, model::InsertSide::RIGHT)) {
						str += "> "; // →
					} else if (this->arrows) {
						str += "  ";
					}
					for(unsigned int tuileDansRangee = 0; tuileDansRangee < board->getMaxSizeX(); tuileDansRangee++) {
						this->printTileLine(board->getTiles().at(rangeeDeTuile * board->getMaxSizeX() + tuileDansRangee), ligneDansTuile, str);

						if(this->spacing) {
							str += " ";
						}
					}
					if(this->arrows && ligneDansTuile == this->tileSize / 2 && board->canInsertTile(model::Position{0, rangeeDeTuile}, model::InsertSide::RIGHT)) {
						str += " <"; // ←
					} else if (this->arrows) {
						str += "  ";
					}
					this->printMessage(str);
				}
				if(this->spacing) {
					this->lineBreak();
				}
			}
			if(this->arrows) {
				str = "  ";
				for(unsigned int tuileDansRangee = 0; tuileDansRangee < board->getMaxSizeX(); tuileDansRangee++) {
					for(unsigned int caractereDeTuile = 0; caractereDeTuile < this->tileSize; caractereDeTuile++) {
						if(caractereDeTuile == this->tileSize / 2 && board->canInsertTile(model::Position{tuileDansRangee, 0}, model::InsertSide::DOWN)) {
							str += "^"; // ↑
						} else {
							str += " ";
						}
					}
					if(this->spacing) {
						str += " ";
					}
				}
			}
			this->printMessage(str);
		}

		/**
		 * Prints infos about a player
		 * @param player the player to print the infos from
		 * @throw invalid_argument if player is null
		 */
		void ConsoleView::printPlayerInfos(const model::Player * const player) const {
			if(player == nullptr) {
				throw std::invalid_argument("Error while printing player infos. Player doesn't exists.");
			}

			this->lineBreak();
			this->printMessage(
				"Players infos :\n"
				"===============\n"
				"  Nickname :\t\t\t" + player->getNickname() + "\n"
				"  Color :\t\t\t" + player->getColor() + "\n"
				"  Location :\t\t\t" + player->getPosition().toString() + "\n"
				"  Current objective :\t\t" + player->getCurrentObjective()->getObjective() + "\n"
				"  Objectives left count :\t" + std::to_string(player->getObjectiveCardsLeftCount()) + "\n"
				"  Completed objectives count :\t" + std::to_string(player->getCompletedObjectiveCardsCount()));
		}

		/**
		 * Prints a message telling the winner of the game
		 * @param player the winner of the game
		 */
		void ConsoleView::printWinner(model::Player * player) {
			this->printMessage("Congratulations " + player->getNickname() + ", you won this game.");
		}

		/**
		 * Prints a message
		 * @param message the message to be printed
		 */
		void ConsoleView::printMessage(const std::string & message) const {
			std::cout << message << std::endl;
		}

		/**
		 * Prints an error
		 * @param error the error to be printed
		 */
		void ConsoleView::printError(const std::string & error) const {
			std::cerr << error << std::endl;
		}

		/**
		 * Prints a message with the different supported commands
		 * @param board the board of the game
		 * @throw invalid_argument if board is null
		 */
		void ConsoleView::printHelp(const model::Board * const board) const {
			if(board == nullptr) {
				throw std::invalid_argument("Error while printing board. Board doesn't exists.");
			}

			this->lineBreak();
			this->printMessage(
				"Help :\n"
				"======\n"
				"Here are the following available commands :\n"
				"\n"
				"> help\n"
				"  shows the different commands\n"
				"\n"
				"> insert <n> [ UP | DOWN | RIGHT | LEFT ]\n"
				"  inserts the tile at the nth row line\n"
				"  i.e. \"insert 1 LEFT\" will insert the tile in the first line and push all the tiles to the left.\n"
				"\n"
				"> goto <x> <y>\n"
				"  moves your pawn to a location, between (1;1) (upper left corner) and " + model::Position(board->getMaxSizeX() - 1, board->getMaxSizeY() - 1).toString() + " (bottom right corner)\n"
				"  i.e. \"goto 3 3\" will try to move the pawn to the tile in (3;3) if the tile is connected to the current tile\n"
				"\n"
				"> rotate\n"
				"  rotates the available tile 90°\n"
				"  i.e. \"rotate\" will rotate the available tile\n"
				"\n"
				"> end turn\n"
				"  ends the player turns\n"
				"  i.e. \"end turn\" will end your turn and go to the next player\n"
			);
			this->lineBreak();
			this->lineBreak();
		}

		/**
		 * Prints a welcome message
		 */
		void ConsoleView::printWelcome(void) const {
			this->lineBreak();
			this->printMessage(
				"Welcome in ...\n"
				"\n"
				"  _           _                _       _   _     \n"
				" | |         | |              (_)     | | | |    \n"
				" | |     __ _| |__  _   _ _ __ _ _ __ | |_| |__  \n"
				" | |    / _` | '_ \\| | | | '__| | '_ \\| __| '_ \\ \n"
				" | |___| (_| | |_) | |_| | |  | | | | | |_| | | |\n"
				" |______\\__,_|_.__/ \\__, |_|  |_|_| |_|\\__|_| |_|\n"
				"                     __/ |                       \n"
				"                    |___/                        ");
			this->lineBreak();
			this->lineBreak();
		}

		/**
		 * Prints the game instructions
		 */
		void ConsoleView::printInstructions(void) const {
			this->lineBreak();
			this->lineBreak();
			this->printMessage(
					"Regles :\n"
					"========"
			);
			this->printMessage(
				"  Dans un labyrinthe enchante, les joueurs partent a la chasse aux objets et aux creatures magiques. Chacun cherche a se frayer un chemin jusqu'a eux en faisant coulisser astucieusement les couloirs.\n"
				"Le premier joueur a decouvrir tous ses secrets et a revenir a son point de depart remporte cette passionnante chasse aux tresors."
			);
			this->lineBreak();
			this->printMessage(
				"Deroulement :\n"
				"============="
			);
			this->printMessage(
				"  Chaque joueur se voit attribue differents objectifs a aller chercher dans le labyrinthe.\n"
				"Un tour se compose toujours de deux phases :\n"
				"  1. Introduction de la carte couloir supplementaire\n"
				"  2. Deplacement du pion\n"
				"A son tour de jeu, le joueur doit essayer d'atteindre la tuile comportant le meme objectif que celui squi lui est actuellement attribue\n"
				"Pour cela il commence toujours par faire coulisser une rangee ou une colonne du labyrinthe en inserant la plaque supplementaire du bord vers l'interieur du plateau, puis il deplace son pion."
			);
			this->lineBreak();
			this->printMessage(
				"Modification du labyrinthe :\n"
				"============================");
			this->printMessage(
				"  12 fleches sont dessinees en bordure de plateau.\n"
				"Elles indiquent les rangees et colonnes où peut etre inseree la plaque supplementaire pour modifier les couloirs du labyrinthe.\n"
				"Quand vient son tour, le joueur choisit l'une de ces rangees ou colonnes et pousse la plaque supplementaire vers l'interieur du plateau jusqu'a ce qu'une nouvelle plaque soit expulsee a l'oppose.\n"
				"La plaque expulsee reste au bord du plateau jusqu'a ce qu'elle soit reintroduite a un autre endroit par le joueur suivant."
			);
			this->lineBreak();
			this->printMessage(
				"Deplacement du pion :\n"
				"=====================");
			this->printMessage(
				"  Des qu'il a modifie le labyrinthe, le joueur peut deplacer son pion. Il peut le deplacer aussi loin qu'il veut jusqu'a n'importe quelle plaque en suivant un couloir ininterrompu.\n"
				"Un joueur peut meme s'arreter sur une case deja occupee. S'il veut, il peut aussi choisir de rester sur place ; il n'est pas oblige de se deplacer.\n"
				"Si le joueur n'atteint pas le dessin recherche (= celui fi gurant sur la carte superieure de sa pile), il peut deplacer son pion aussi loin qu'il veut de maniere a etre en bonne position pour le prochain tour.\n"
				"S'il atteint le dessin recherche, il retourne sa carte a côte de sa pile. Il peut immediatement regarder secretement la carte suivante de sa pile pour connaître son prochain objectif.\n"
				"C'est maintenant au tour du joueur suivant de jouer"
			);
			this->lineBreak();
			this->printMessage(
				"Fin du jeu :\n"
				"============");
			this->printMessage(
				"  La partie s'arrete des qu'un joueur a atteint tous ses objectifs et qu'il est revenu a son point de depart."
			);
		}

		/**
		 * Prints a tile
		 * @param tile the tile to print
		 */
		void ConsoleView::printTile(const Labyrinth_44422::model::Tile * const tile) const {
			for(unsigned int i = 0; i < this->tileSize; i++) {
				std::string str = "  ";
				this->printTileLine(tile, i, str);
				this->printMessage(str);
			}
		}

		/**
		 * Prints the different objectives on the board and their positions
		 * @param board the board containing the tiles
		 */
		void ConsoleView::printBoardObjectives(model::Board * board, std::vector<model::Tile *> availableTiles) const {
			this->lineBreak();
			this->printMessage("Here are the objectives on the board :");
			this->printMessage("======================================");
			for(const auto & tile : board->getTiles()) {
				if(tile->hasObjective()) {
					this->printMessage("  " + tile->getObjective() + " :" + std::string(1 + ((15 - tile->getObjective().length()) / 4), '\t') + tile->getPosition().toString());
				}
			}
			if(std::any_of(availableTiles.begin(), availableTiles.end(), [](model::Tile * tile){return tile->hasObjective();})) {
				this->lineBreak();
				this->printMessage("Objectives on the available tile:");
				this->printMessage("=================================");
				for(model::Tile * tile : availableTiles) {
					if(tile->hasObjective()) {
						this->printMessage("  " + tile->getObjective());
					}
				}
			}
			this->lineBreak();
		}

		/**
		 * Prints the available tile
		 * @param tile
		 */
		void ConsoleView::printAvailableTile(model::Tile * & tile) const {
			this->lineBreak();
			this->printMessage("Here is the available tile :");
			this->printMessage("============================");
			this->printTile(tile);
		}
		
		/**
		 * Prints the infos of all the players
		 * @param players the players in a vector
		 */
		void ConsoleView::printPlayersInfos(std::vector<model::Player *> players) const {
			this->lineBreak();
			this->printMessage("Infos on the different players :");
			this->printMessage("============================");
			for(model::Player * const & player : players) {
				this->printMessage("  " + player->getNickname() + " :\t" + ((player->getNickname().length() <= 3) ? "\t" : "")
				+ player->getPosition().toString() + "\t>\t" + player->getCurrentObjective()->getObjective());
			}
		}

		/**
		 * Clears the console
		 */
		void ConsoleView::clearScreen(void) const {
			std::cout << "\033c";
		}

		/**
		 * Prints a line break
		 */
		void ConsoleView::lineBreak(void) const {
			std::cout << std::endl;
		}
	}  // namespace console
}  // namespace Labyrinth_44422
