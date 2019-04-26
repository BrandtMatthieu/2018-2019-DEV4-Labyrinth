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
			/*
			this->game->generateTiles();
			this->guiView->displayWelcome();
			while (!this->game->hasEnoughPlayers()) {
				std::string name = this->guiView->askPlayerName();
				this->game->addPlayer(name);
			}
			this->guiView->show();
			*/
		}
	} // namespace controller
} // namespace Labyrinth_44422
