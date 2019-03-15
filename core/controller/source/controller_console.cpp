#include "../include/controller_console.h"

namespace Labyrinth_44422 {
	namespace controller {
		
		/**
		 * Creates a new controller for the Labyrinth game
		 * @param consoleView the address of a console view
		 */
		ControllerConsole::ControllerConsole(Labyrinth_44422::console::ConsoleView * const consoleView) :
			consoleView{consoleView},
			game{new Labyrinth_44422::model::Game()} {
			for(int i = 0; i < this->game->getMinPlayers(); i++) {
				std::string name = this->consoleView->newPlayerName();
				this->game->addPlayer(name);
			}
			
			while(this->game->getPlayersCount() < this->game->getMaxPlayers()
				  && this->consoleView->addNewPlayer()) {
				std::string name = this->consoleView->newPlayerName();
				this->game->addPlayer(name);
			}
		};
		
		/**
		 * Creates a new controller for the Labyrinth game from an existing controller
		 * @param controllerConsole the controller to create the new controller from
		 * aka. copy constructor
		 */
		ControllerConsole::ControllerConsole(const ControllerConsole & controllerConsole) :
			consoleView{new Labyrinth_44422::console::ConsoleView(* controllerConsole.consoleView)},
			game{new Labyrinth_44422::model::Game(* controllerConsole.game)} {};
		
		/**
		 * Creates a new controller with another provided controller
		 * aka. copy assignment operator
		 * @param controllerConsole the other provided controller
		 * @return a new controller with another provided controller
		 */
	 	/*
		ControllerConsole & ControllerConsole::operator= (const ControllerConsole & controllerConsole) {
			this->game = controllerConsole.game;
			this->consoleView = controllerConsole.consoleView;
			return *this;
		}
	  	*/
		
		/**
		 * Starts the game
		 */
		void ControllerConsole::start() {
			while(!this->game->hasWinner()) {
				
				this->game->nextPlayer();
			}
		}
		
		ControllerConsole::~ControllerConsole() {
			delete this->game;
			delete this->consoleView;
		}
		
		
	}
}
