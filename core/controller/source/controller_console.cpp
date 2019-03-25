#include "../include/controller_console.h"

namespace Labyrinth_44422 {
	namespace controller {
		
		/**
		 * Creates a new controller for the Labyrinth game
		 * @param consoleView the address of a console view
		 */
		ControllerConsole::ControllerConsole(const Labyrinth_44422::console::ConsoleView * const consoleView) :
			consoleView{const_cast<Labyrinth_44422::console::ConsoleView *>(consoleView)},
			game{new Labyrinth_44422::model::Game()} {
			this->consoleView->printMessage("Welcome in the Labyrinth game.\nWould you like to see the instructions?");
			for(unsigned int i = 0; i < this->game->getMinPlayers(); i++) {
				std::string name = this->consoleView->newPlayerName();
				this->game->addPlayer(name);
			}
			
			while(this->game->getPlayersCount() < this->game->getMaxPlayers()
				  && this->consoleView->addNewPlayer()) {
				std::string name = this->consoleView->newPlayerName();
				this->game->addPlayer(name);
			}
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
		 * Starts the game
		 */
		void ControllerConsole::start(void) {
			this->consoleView->printHelp(this->game->getBoard());
			while(!this->game->hasWinner()) {
				this->consoleView->printMessage(this->game->getCurrentPlayer()->getNickname() + ", it's your turn!");
				
				this->game->nextPlayer();
			}
		}
		
		/**
		 * Destroys the console controller object and it's attributes
		 */
		ControllerConsole::~ControllerConsole(void) {
			delete this->game;
			delete this->consoleView;
		}
		
		
	}  // namespace controller
}  // namespace Labyrinth_44422
