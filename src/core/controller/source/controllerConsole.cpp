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
		 */
		void ControllerConsole::start(void) {
			
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
			
			/* Display Instructions */
			if(this->consoleView->getYesNoAnswer("Would you like to see the instructions?")) {
				this->consoleView->printInstructions();
				this->consoleView->printHelp(this->game->getBoard());
			}
			
			this->game->start();
			
			this->game->generateObjectiveCards();
			this->game->dealObjectiveCardsToPlayers();
			
			while(!this->game->hasWinner()) {
				
				//this->consoleView->printBoard(this->game->getBoard());
				
				this->consoleView->printMessage(this->game->getCurrentPlayer()->getNickname() + ", it's your turn!");
				
				this->consoleView->printPlayerInfos(this->game->getCurrentPlayer());
				
				while(true) {
					std::string answer = this->consoleView->getCommand();
					if(std::regex_match(answer, std::regex(" {0,}help {0,}"))) {
						this->consoleView->printHelp(this->game->getBoard());
						continue;
					} else if(std::regex_match(answer, std::regex(" {0,}insert {1,}[0-9]+ {1,}(UP|DOWN|LEFT|RIGHT) {0,}"))) {
						this->consoleView->printMessage("INSERT");
						break;
					} else if(std::regex_match(answer, std::regex(" {0,}goto {1,}[0-9]+ {1,}[0-9]+ {0,}"))) {
						this->consoleView->printMessage("GOTO");
						if(!this->game->getCurrentPlayer()->hasInsertedTile()) {
							this->consoleView->printError("You cannot move you pawn now since you haven't inserted a tile in the Labyrinth yet.\n"
								"Please insert a tile in the Labyrinth first then try again");
							continue;
						} else {
							unsigned int x = std::stoi("10");
							unsigned int y = std::stoi("10");
							if(this->game->canCurrentPlayerGoTo(model::Position{x, y})) {
								this->game->currentPlayerGoTo(model::Position{x, y});
								break;
							} else {
								this->consoleView->printError("You cannot move to this tile");
								continue;
							};
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
