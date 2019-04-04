#include <algorithm>
#include <stdexcept>
#include <regex>

#include "./../include/controllerConsole.h"

namespace Labyrinth_44422 {
	namespace controller {
		
		/**
		 * Creates a new controller for the Labyrinth game
		 * @param consoleView the address of a console view
		 * @throw invalid_argument if controller is null
		 */
		ControllerConsole::ControllerConsole(const Labyrinth_44422::console::ConsoleView * const consoleView) :
			game{new Labyrinth_44422::model::Game()} {
			
			/* Checking parameters */
			if(consoleView == nullptr) {
				throw std::invalid_argument("Error while initializing the controller. No game was provided.");
			}
			
			this->consoleView = const_cast<Labyrinth_44422::console::ConsoleView *>(consoleView);
		}
		
		/**
		 * Creates a new controller for the Labyrinth game from an existing controller
		 * @param controllerConsole the controller to create the new controller from
		 * aka. copy constructor
		 */
		ControllerConsole::ControllerConsole(const ControllerConsole & controllerConsole) :
			consoleView{new Labyrinth_44422::console::ConsoleView(* controllerConsole.consoleView)},
			game{new Labyrinth_44422::model::Game(* controllerConsole.game)} {}
		
		/**
* Destroys the console controller object and it's attributes
*/
		ControllerConsole::~ControllerConsole(void) {
			delete this->game;
			delete this->consoleView;
		}
		
		/**
		 * Starts the game
		 * @throw runtime_error if provided inside doesn't exists
		 */
		void ControllerConsole::start(void) {
			
			this->game->generateTiles();
			
			this->consoleView->printWelcome();
			
			/* Adding players */
			for(unsigned int i = 0; i < this->game->getMinPlayers(); i++) {
				std::string name = this->consoleView->getNewPlayerName();
				this->game->addPlayer(name);
			}
			while(this->game->getPlayersCount() < this->game->getMaxPlayers() &&
				  this->consoleView->getYesNoAnswer("Would you like to add another player ?")) {
				std::string name = this->consoleView->getNewPlayerName();
				this->game->addPlayer(name);
			}
			
			this->game->generateObjectiveCards();
			this->game->dealObjectiveCardsToPlayers();
			
			
			/* Display Instructions */
			if(this->consoleView->getYesNoAnswer("Would you like to see the instructions?")) {
				this->consoleView->printInstructions();
				this->consoleView->printHelp(this->game->getBoard());
			}
			
			this->game->start();
			
			while(!this->game->hasWinner()) {
				
				this->consoleView->printBoard(this->game->getBoard());
				
				this->consoleView->lineBreak();
				this->consoleView->printMessage(this->game->getCurrentPlayer()->getNickname() + ", it's your turn!");
				
				this->consoleView->printPlayerInfos(this->game->getCurrentPlayer());
				
				while(true) {
					std::string answer = this->consoleView->getCommand();
					std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
					
					if(std::regex_match(answer, std::regex(" {0,}help {0,}"))) {
						this->consoleView->printHelp(this->game->getBoard());
						continue;
						
					} else if(std::regex_match(answer, std::regex(" {0,}insert {1,}[0-9]+ {1,}(up|down|left|right) {0,}"))) {
						this->consoleView->printMessage("INSERT");
						
						std::smatch sideMatch;
						std::regex_search(answer, sideMatch, std::regex("(up|down|left|right)"));
						std::string sideStr = sideMatch.str(1);
						model::InsertSide side;
						
						if(sideStr == "up") {
							side = model::InsertSide::UP;
						} else if (sideStr == "down") {
							side = model::InsertSide::DOWN;
						} else if (sideStr == "right") {
							side = model::InsertSide::RIGHT;
						} else if (sideStr == "left") {
							side = model::InsertSide::LEFT;
						} else {
							this->consoleView->printError("Unknown insert side. Please use only [ UP | DOWN | RIGHT | LEFT ]");
							continue;
						}
						
						std::smatch positionMatch;
						std::regex_search(answer, positionMatch, std::regex("[0-9]+"));
						unsigned int position = static_cast<unsigned int>((std::stoi(positionMatch.str(0)) < 1 ? 1 : std::stoi(positionMatch.str(0))) - 1);
						
						switch(side) {
							case model::InsertSide::UP:
							case model::InsertSide::DOWN:
								if(!this->game->getBoard()->isPositionInsideBoard(model::Position{position, 0})) {
									this->consoleView->printError(
											"You cannot insert a tile at this position. This position is out of the board's bounds.");
									this->consoleView->printError("Please try again.");
									continue;
								}
								if(!this->game->getBoard()->canInsertTile(model::Position{position, 0}, side)) {
									this->consoleView->printError(
											"You cannot move this column. One of the tile cannot be moved.");
									this->consoleView->printError("Please try again with another column.");
									continue;
								}
								this->game->currentPlayerInsertTile(model::Position{position, 0}, side);
								break;
							case model::InsertSide::LEFT:
							case model::InsertSide::RIGHT:
								if(!this->game->getBoard()->isPositionInsideBoard(model::Position{0, position})) {
									this->consoleView->printError(
											"You cannot insert a tile at this position. This position is out of the board's bounds.");
									this->consoleView->printError("Please try again.");
									continue;
								}
								if(!this->game->getBoard()->canInsertTile(model::Position{0, position}, side)) {
									this->consoleView->printError(
											"You cannot move this row. One of the tile cannot be moved.");
									this->consoleView->printError("Please try again with another row.");
									continue;
								}
								this->game->currentPlayerInsertTile(model::Position{0, position}, side);
								break;
						}
						
						
					} else if(std::regex_match(answer, std::regex(" {0,}goto {1,}[0-9]+ {1,}[0-9]+ {0,}"))) {
						this->consoleView->printMessage("GOTO");
						if(!this->game->getCurrentPlayer()->hasInsertedTile()) {
							this->consoleView->printError("You cannot move you pawn now since you haven't inserted a tile in the Labyrinth yet.");
							this->consoleView->printError("Please insert a tile in the Labyrinth first then try again");
							continue;
						} else {
							std::smatch matchCoo;
							std::regex_search(answer, matchCoo, std::regex("[0-9]+"));
							unsigned int x = static_cast<unsigned int>(std::stoi(matchCoo.str(1))) - 1;
							unsigned int y = static_cast<unsigned int>(std::stoi(matchCoo.str(2))) - 1;
							if(this->game->canCurrentPlayerGoTo(model::Position{x, y})) {
								this->game->currentPlayerGoTo(model::Position{x, y});
								break;
							} else {
								this->consoleView->printError("You cannot move to this tile");
								continue;
							}
						}
					} else {
						this->consoleView->printMessage("Unknown command.");
						continue;
					}
				}
				
				this->game->currentPlayerCheckObjective();
				
				this->game->nextPlayer();
			}
			
			this->consoleView->printWinner(this->game->getWinner());
			
			this->consoleView->printMessage("Game over, thanks for playing.");
		}
	}  // namespace controller
}  // namespace Labyrinth_44422
