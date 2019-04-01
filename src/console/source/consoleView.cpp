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
		 * @throw invalid_argument if tile is null
		 * @throw invalid_argument if ligneDansTuile is null
		 * @throw runtime_error if printing carriage is out of bounds (should not happen)
		 * @return a string with the line printed at the specified height
		 */
		std::string ConsoleView::printTile(const Labyrinth_44422::model::Tile * const tile, const unsigned int & ligneDansTuile, std::string & str) const {
			if(tile == nullptr) {
				throw std::invalid_argument("Error while printing the tile. No tile provided.");
			}
			if(ligneDansTuile >= this->tileSize) {
				throw std::invalid_argument("Error while printing the tile. Tile line is out of bounds.");
			}
			
			for(unsigned int caractereDeTuile = 0; caractereDeTuile < this->tileSize; caractereDeTuile++) {
				if(ligneDansTuile < this->wall1 // Vertical Top part
				|| ligneDansTuile > this->wall2) { // Vertical Bottom part
					if(caractereDeTuile == this->wall1
					|| caractereDeTuile == this->wall2) { // Horizontal ConsoleView::walls part
						if(ligneDansTuile < this->wall1) {
							if(tile->getPathUP()) {
								str += this->wall;
							} else {
								str += this->path;
							}
						} else if(ligneDansTuile > this->wall2) {
							if(tile->getPathDOWN()) {
								str += this->wall;
							} else {
								str += this->path;
							}
						}
					} else { // Horizontal All other parts
						str += this->path;
					}
				} else if(ligneDansTuile > this->wall1
				&& ligneDansTuile < this->wall2) { // Vertical Middle part
					if(caractereDeTuile == this->wall1) { // Horizontal Left ConsoleView::wall
						if(tile->getPathLEFT()) {
							str += this->path;
						} else {
							str += this->wall;
						}
					} else if(caractereDeTuile == this->wall2) { // Horizontal Right ConsoleView::wall
						if(tile->getPathRIGHT()) {
							str += this->path;
						} else {
							str += this->wall;
						}
					} else { // Horizontal Middle part
						if(caractereDeTuile == this->tileSize/2 && ligneDansTuile == this->tileSize/2) {
							if(tile->hasObjective()) {
								str += this->objective;
							} else  if(tile->hasStartNumber()) {
								str += std::to_string(tile->getStartNumber());
							} else {
								str += this->path;
							}
						} else {
							str += this->path;
						}
					}
				} else if(ligneDansTuile == this->wall1
				|| ligneDansTuile == this->wall2) { // Vertical ConsoleView::walls part
					if(caractereDeTuile < this->wall1) { // Horizontal Left ConsoleView::wall
						if(tile->getPathLEFT()) {
							str += this->wall;
						} else {
							str += this->path;
						}
					} else if(caractereDeTuile > this->wall2) { // Horizontal Right ConsoleView::wall
						if(tile->getPathRIGHT()) {
							str += this->wall;
						} else {
							str += this->path;
						}
					} else if(caractereDeTuile > this->wall1
					&& caractereDeTuile < this->wall2) { // Horizontal Middle part
						if(ligneDansTuile == this->wall1) { // Horizontal Middle Top ConsoleView::wall
							if(tile->getPathUP()) {
								str += this->path;
							} else {
								str += this->wall;
							}
						} else if(caractereDeTuile > this->wall1
						&& caractereDeTuile < this->wall2) { // Horizontal Middle Bottom ConsoleView::wall
							if(tile->getPathDOWN()) {
								str += this->path;
							} else {
								str += this->wall;
							}
						}
					} else { // 4 small Middle ConsoleView::walls
						str += this->wall;
					}
				} else {
					throw std::runtime_error("Error while printing tile. Print carriage is out of tile");
				}
			}
			return str;
		}
		
		/**
		 * Gets a yes or no answer from the user
		 * @param message the message to ask something to the player and wait for a yes or no answer
		 * @return the answer of the player as a boolean
		 */
		bool ConsoleView::getYesNoAnswer(const std::string & message) const {
			std::string answer;
			this->lineBreak();
			this->printMessage(message + " [ yes | no ]");
			std::cout << "\n> ";
			do {
				std::getline(std::cin, answer);
				std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
				if(answer.empty()) {
					this->printError("Wrong input, please only answer with [ yes ] or [ no ].");
					std::cout << "\n> ";
				}
			} while(answer != "yes" && answer != "y" && answer != "n" && answer != "no");
			return answer == "yes" || answer == "y";
		}
		
		/**
		 * Creates a new console view
		 * @param spacing if there needs to be spaces between the rows and lines of the board printed
		 */
		ConsoleView::ConsoleView(const bool spacing, const bool arrows) :
			spacing{spacing},
			arrows{arrows} {}
		
		/**
		 * Creates a new console view from an existing one
		 * @param vue
		 */
		ConsoleView::ConsoleView(const ConsoleView & vue) :
			wall{"▓"},
			path{"░"},
			space{" "},
			objective{"o"},
			spacing{vue.spacing},
			arrows{vue.arrows} {}
		
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
				for(Labyrinth_44422::model::Player * const & player_ptr : game->getPlayers()) {
					this->printMessage("  " + player_ptr->getNickname() + "\t: " + std::to_string(player_ptr->getObjectiveCardsLeftCount()) + " objective cards left");
				}
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
							str += "↓";
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
						str += "→ ";
					} else if (this->arrows) {
						str += "  ";
					}
					for(unsigned int tuileDansRangee = 0; tuileDansRangee < board->getMaxSizeX(); tuileDansRangee++) {
						str = this->printTile(board->getTiles().at(rangeeDeTuile * board->getMaxSizeX() + tuileDansRangee), ligneDansTuile, str);
						
						if(this->spacing) {
							str += this->space;
						}
					}
					this->printMessage(str);
				}
				if(this->spacing) {
					this->lineBreak();
				}
			}
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
				"- insert <n> [ UP | DOWN | RIGHT | LEFT ]\n"
				"  inserts the tile at the nth row line\n"
				"  i.e. \"insert 1 LEFT\" will insert the tile in the first line and push all the tiles to the left.\n"
				"\n"
				"- goto <x> <y>\n"
				"  moves your pawn to a location, between (1;1) (upper left corner) and " + board->getMaxSize().toString() + " (bottom right corner)\n"
				"  i.e. \"goto 3 3\" will try to move the pawn to the tile in (3;3) if the tile is connected to the current tile\n"
				"\n"
				"- help\n"
				"  shows the different commands\n");
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