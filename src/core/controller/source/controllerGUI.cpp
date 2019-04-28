#include "./../include/controllerGUI.h"
#include "./../../../gui/include/guiView.h"
#include "./../../../gui/include/askPlayerNameWindow.h"

namespace Labyrinth_44422 {
	namespace controller {


		ControllerGUI::ControllerGUI(void) :
			game{new model::Game()},
			guiView{new gui::GUIView(game)} {
			this->start();
		}

		ControllerGUI::~ControllerGUI(void) {
			delete this->game;
			delete this->guiView;
		}

		void ControllerGUI::start(void) {

			this->game->generateTiles();
			//this->guiView->displayWelcome();

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
