#include <iostream>
#include <string>

#include "../include/consoleView.h"

namespace Labyrinth_44422 {
	namespace console {
		
		/**
		 * Prints an horizontal line in the tile
		 * @param tile the tile to print the line from
		 * @param k the height to print the line of the tile from
		 * @return a string with the line printed at the specified height
		 */
		std::string ConsoleView::printTile(const Labyrinth_44422::model::Tile * const tile, const unsigned int & k) const {
			if(tile == nullptr) {
				throw std::invalid_argument("Error while printing the tile. No tile provided.");
			}
			if(k >= ConsoleView::tileSize) {
				throw std::invalid_argument("Error while printing the tile. Tile line is out of bounds.");
			}
			
			std::string line;
			for(unsigned int l = 0; l < ConsoleView::tileSize; l++) {
				if(k < ConsoleView::pathSize // Vertical Top part
				|| k > 2 * ConsoleView::tileSize + 1) { // Vertical Bottom part
					if(l == ConsoleView::pathSize
					|| l == 2 * ConsoleView::pathSize + 1) { // Horizontal ConsoleView::walls part
						if(k < ConsoleView::pathSize) {
							if(tile->getPathUP()) {
								line += ConsoleView::wall;
							} else {
								line += ConsoleView::path;
							}
						} else if(k > 2 * ConsoleView::pathSize + 1) {
							if(tile->getPathDOWN()) {
								line += ConsoleView::wall;
							} else {
								line += ConsoleView::path;
							}
						}
					} else { // Horizontal All other parts
						line += ConsoleView::path;
					}
				} else if(k > ConsoleView::pathSize
				&& k < 2 * ConsoleView::tileSize + 1) { // Vertical Middle part
					if(l == ConsoleView::pathSize) { // Horizontal Left ConsoleView::wall
						if(tile->getPathLEFT()) {
							line += ConsoleView::path;
						} else {
							line += ConsoleView::wall;
						}
					} else if(l == 2 * ConsoleView::pathSize + 1) { // Horizontal Right ConsoleView::wall
						if(tile->getPathRIGHT()) {
							line += ConsoleView::path;
						} else {
							line += ConsoleView::wall;
						}
					} else { // Horizontal Middle part
						// TODO print player on the tile or objective or spawnPoint
						line += ConsoleView::path;
					}
				} else if(k == ConsoleView::pathSize
				|| k == 2 * ConsoleView::pathSize + 1) { // Vertical ConsoleView::walls part
					if(l < ConsoleView::pathSize) { // Horizontal Left ConsoleView::wall
						if(tile->getPathLEFT()) {
							line += ConsoleView::wall;
						} else {
							line += ConsoleView::path;
						}
					} else if(l > 2 * ConsoleView::pathSize + 1) { // Horizontal Right ConsoleView::wall
						if(tile->getPathRIGHT()) {
							line += ConsoleView::wall;
						} else {
							line += ConsoleView::path;
						}
					} else if(l > ConsoleView::pathSize
					&& l < 2 * ConsoleView::pathSize + 1) { // Horizontal Middle part
						if(k == ConsoleView::pathSize) { // Horizontal Middle Top ConsoleView::wall
							if(tile->getPathUP()) {
								line += ConsoleView::path;
							} else {
								line += ConsoleView::wall;
							}
						} else if(l > ConsoleView::pathSize
						&& l < 2 * ConsoleView::pathSize + 1) { // Horizontal Middle Bottom ConsoleView::wall
							if(tile->getPathDOWN()) {
								line += ConsoleView::path;
							} else {
								line += ConsoleView::wall;
							}
						}
					} else { // 4 small Middle ConsoleView::walls
						line += ConsoleView::wall;
					}
				} else {
					throw std::runtime_error("Error while printing tile. Print carriage is out of tile");
				}
			}
			return line;
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
		ConsoleView::ConsoleView(bool const spacing) :
			spacing{spacing} {}
		
		/**
		 * Creates a new console view from an existing one
		 * @param vue
		 */
		ConsoleView::ConsoleView(const ConsoleView & vue) :
			wall{"▓"},
			path{"░"},
			space{" "},
			spacing{vue.spacing} {}
		
		/**
		 * Asks if the players want to add another player
		 * @return true if the players want to add another player
		 */
		bool ConsoleView::addNewPlayer(void) const {
			return getYesNoAnswer("Would you like to add another player ?");
		}
		
		/**
		 * Asks the name for the new player in the game
		 * @return the name of the new player
		 */
		std::string ConsoleView::newPlayerName(void) const {
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
			
			for(unsigned int j = 0; j < board->getMaxSizeY(); j++) {
				for(unsigned int k = 0; k < ConsoleView::tileSize; k++) {
					for(unsigned int i = 0; i < board->getMaxSizeX(); i++) {
						std::cout << this->printTile(board->getTiles().at(j * board->getMaxSizeX() + i), k);
						if(this->spacing) {
							std::cout << ConsoleView::space;
						}
					}
					std::cout << std::endl;
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
		
	}  // namespace console
}  // namespace Labyrinth_44422
