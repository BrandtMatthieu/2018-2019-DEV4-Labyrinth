#include "./../include/controllerGUI.h"
#include "./../../../gui/include/askPlayerNameWindow.h"

namespace Labyrinth_44422 {
	namespace controller {

		/**
		 * Creates a new controller for the game in gui mode
		 */
		ControllerGUI::ControllerGUI(void) : game{new model::Game()}, guiView{new gui::GUIView(game)} {
			this->start();
		}

		/**
		 * Deletes the controller for the Labyrinth game
		 */
		ControllerGUI::~ControllerGUI(void) {
			delete this->game;
			delete this->guiView;
		}

		/**
		 * Starts the controller
		 */
		void ControllerGUI::start(void) {

			this->game->generateTiles();

			this->game->addPlayer("Player 1");
			this->game->addPlayer("Player 2");
			this->game->addPlayer("Player 3");
			this->game->addPlayer("Player 4");

			this->game->dealObjectiveCardsToPlayers();
			this->game->start();

			this->guiView->updateDisplay();
		}

	} // namespace controller
} // namespace Labyrinth_44422
