#include <algorithm>
#include <iostream>
#include <string>

#include "./../include/consoleView.h"
#include "./../../core/model/include/insertSide.h"
#include "./../../core/model/include/position.h"


class Position;
namespace Labyrinth_44422 {
	namespace console {
		
		/**
		 * Prints an horizontal line in the tile
		 * @param tile the tile to print the line from
		 * @param ligneDansTuile the height to print the line of the tile from
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
						// TODO print player on the tile or objective or spawnPoint
						str += this->path;
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
			std::cout << message << " [ yes | no ]" << std::endl << "> ";
			do {
				std::cin >> answer;
				std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
				if(answer.empty()) {
					std::cout << "Wrong input, please only answer with [ yes ] or [ no ]." << std::endl << " >";
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
			spacing{vue.spacing},
			arrows{vue.arrows} {}
		
		/**
		 * Asks the name for the new player in the game
		 * @return the name of the new player
		 */
		std::string ConsoleView::getNewPlayerName(void) const {
			std::cout << "Please enter a name for this player" << std::endl << "> ";
			std::string answer;
			while(answer.empty()) {
				std::cin >> answer;
				if(answer.empty()) {
					std::cout << "Invalid name. Please enter a name for this player" << std::endl << "> ";
				}
			}
			return answer;
		}
		
		/**
		 * Prints the infos of the game
		 * @param game the game to print the infos from
		 */
		void ConsoleView::printGameInfos(const model::Game * const game) const {
			if(game == nullptr) {
				throw std::invalid_argument("Error while printing game infos. Game does not exists.");
			}
			
			std::cout << "Game infos : " << std::endl;
			if(game->hasWinner()) {
				std::cout << "Game is over." << std::endl
					<< "Winner : " << game->getWinner()->getNickname();
			} else {
				std::cout << "Game is still in progress...";
				std::cout << "Current player : " << game->getCurrentPlayer()->getNickname() << std::endl;
				std::cout << "Objective left count for each player : " << std::endl;
				for(Labyrinth_44422::model::Player * const & player_ptr : game->getPlayers()) {
					std::cout << "\t" << player_ptr->getNickname() << " : " << std::to_string(player_ptr->getObjectiveCardsLeftCount()) << " objective cards left" << std::endl;
				}
			}

		}
		
		/**
		 * Prints the board of the game
		 * @param board the board to print
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
			std::cout << str << std::endl;
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
					std::cout << str << std::endl;
				}
				if(this->spacing) {
					std::cout << std::endl;
				}
			}
		}
		
		/**
		 * Prints infos about a player
		 * @param player the player to print the infos from
		 */
		void ConsoleView::printPlayerInfos(const model::Player * const player) const {
			if(player == nullptr) {
				throw std::invalid_argument("Error while printing player infos. Player doesn't exists.");
			}
			
			std::cout << "Players infos :" << std::endl
				<< "Nickname : " << player->getNickname() << std::endl
				<< "Color : " << player->getColor() << std::endl
				<< "Location : " << player->getPosition().toString() << std::endl
				<< "Current objective : " << player->getCurrentObjective()->getObjective() << std::endl
				<< "Objectives left count : " << std::to_string(player->getObjectiveCardsLeftCount()) << std::endl << std::endl
				<< "Objectives completed count : " << std::to_string(player->getObjectiveCount()) << std::endl;
				
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
		 * Prints a message with the different supported comands
		 * @param board the board of the game
		 */
		void ConsoleView::printHelp(const model::Board * const board) const {
			if(board == nullptr) {
				throw std::invalid_argument("Error while printing board. Board doesn't exists.");
			}
			
			std::cout <<
			"== HELP ==" << std::endl << std::endl <<
			"Here are the following available commands :" << std::endl <<
			"- insert <n> [UP|DOWN|RIGHT|LEFT] " << std::endl <<
			"\tinsert the tile at the nth row line" << std::endl <<
			"\ti.e. \"insert 1 LEFT\" will insert the tile in the first line and push all the tiles to the left." << std::endl <<
			"- goto <x> <y> " << std::endl <<
			"\tmoves your pawn to a location, between (1;1) (upper left corner) and " << board->getMaxSize().toString() << " (bottom right corner)" << std::endl <<
			"\ti.e. \"goto 3 3\" will try to move the pawn to the tile in (3;3) if the tile is connected to the current tile" << std::endl <<
			"- help" << std::endl <<
			"\tshows the different commands" << std::endl << std::endl;
		}
		
		/**
		 * Clears the console
		 */
		void ConsoleView::clearScreen(void) const {
			std::cout << "\033c";
		}
	}  // namespace console
}  // namespace Labyrinth_44422
