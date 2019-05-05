#include <iostream>

#include "./../include/controllerGUI.h"
#include "./../../../gui/include/guiView.h"

namespace Labyrinth_44422 {
	namespace controller {

		/**
		 * Creates a new controller for the game in gui mode
		 */
		ControllerGUI::ControllerGUI(void) : game{new model::Game()} {
			this->guiView = new Labyrinth_44422::gui::GUIView(this->game, this);

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

		/**
		 * Adds a player into the game
		 * @param nickname the nickname of the new player
		 */
		void ControllerGUI::addPlayer(std::string nickname) {
			this->game->addPlayer(nickname);
		}

		void ControllerGUI::currentPlayerTurnTileLeft() {
			try {
				this->game->getAvailableTiles().at(0)->rotateLeft90();
				this->guiView->updateDisplay();
				std::cout << "Left" << std::endl;
			} catch (std::exception const &e) {
				std::cout << e.what() << std::endl;
			}
		}

		void ControllerGUI::currentPlayerTurnTileRight() {
			try {
				this->game->getAvailableTiles().at(0)->rotateRight90();
				this->guiView->updateDisplay();
				std::cout << "Right" << std::endl;
			} catch (std::exception const &e) {
				std::cout << e.what() << std::endl;
			}
		}

		void ControllerGUI::currentPlayerTryInsertTile(Labyrinth_44422::model::InsertSide side, unsigned int line) {
			try {
				if (this->game->canCurrentPlayerInsertTile()) {
					this->game->currentPlayerInsertTile(line, side);
					std::cout << "Insert at " << line << std::endl;
				} else {
					std::cerr << "Cannot insert at " << line << std::endl;
				}
				this->guiView->updateDisplay();
			} catch (std::exception const &e) {
				std::cout << e.what() << std::endl;
			}
		}

		void ControllerGUI::currentPlayerTryGoTo(unsigned int x, unsigned int y) {
			try {
				if (this->game->canCurrentPlayerGoTo()) {
					this->game->currentPlayerGoTo(model::Position{x, y});
					this->guiView->updateDisplay();
					std::cout << "Goto " << x << " " << y << std::endl;
					this->game->currentPlayerCheckObjective();
					if (this->game->hasWinner()) {
						this->guiView->displayWinner();
					}
					this->game->nextPlayer();
				} else {
					std::cerr << "Cannot goto " << x << " " << y << std::endl;
				}
			} catch (std::exception const &e) {
				std::cout << e.what() << std::endl;
			}
		}

	} // namespace controller
} // namespace Labyrinth_44422
