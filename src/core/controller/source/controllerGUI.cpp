#include "./../include/controllerGUI.h"
#include "./../../../gui/include/guiView.h"

namespace Labyrinth_44422 {
	namespace controller {

		/**
		 * Creates a new controller for the game in gui mode
		 */
		ControllerGUI::ControllerGUI(void) : game{new model::Game()}, guiView{new gui::GUIView(this->game)} {


			this->game->addPlayer("Player 1");
			this->game->addPlayer("Player 2");
			this->game->addPlayer("Player 3");
			this->game->addPlayer("Player 4");

			this->game->generateTiles();

			this->game->dealObjectiveCardsToPlayers();
			this->game->start();

			this->guiView->init();
		}

		/**
		 * Deletes the controller for the Labyrinth game
		 */
		ControllerGUI::~ControllerGUI(void) {
			delete this->game;
			delete this->guiView;
		}

	} // namespace controller
} // namespace Labyrinth_44422
