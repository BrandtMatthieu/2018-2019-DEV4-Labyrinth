#include <iostream>

#include "./../include/controllerGUI.h"
#include "./../../../gui/include/guiView.h"

namespace Labyrinth_44422 {
	namespace controller {

		/**
		 * Creates a new controller for the game in gui mode
		 */
		ControllerGUI::ControllerGUI(void) : game{new model::Game()} {
			this->guiView = new gui::GUIView(this->game, this);

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

		/**
		 * Makes the available tile turn 90° left
		 */
		void ControllerGUI::currentPlayerTurnTileLeft() {
			try {
				this->game->getAvailableTiles().at(0)->rotateLeft90();
				this->guiView->updateDisplay();
			} catch (std::exception const &e) {
				std::cout << e.what() << std::endl;
			}
		}

		/**
		 * Makes the available tile turn 90° right
		 */
		void ControllerGUI::currentPlayerTurnTileRight() {
			try {
				this->game->getAvailableTiles().at(0)->rotateRight90();
				this->guiView->updateDisplay();
			} catch (std::exception const &e) {
				std::cout << e.what() << std::endl;
			}
		}

		/**
		 * Tries to insert a tile in the Labyrinth
		 * @param side the side to insert the tile
		 * @param line the line to insert the tile
		 */
		void ControllerGUI::currentPlayerTryInsertTile(Labyrinth_44422::model::InsertSide side, unsigned int line) {
			try {
				if (this->game->canCurrentPlayerInsertTile()) {
					this->game->currentPlayerInsertTile(line, side);
				}
				this->guiView->updateDisplay();
			} catch (std::exception const &e) {
				std::cout << e.what() << std::endl;
			}
		}

		/**
		 * Tries to go to a tile on the board
		 * @param x the x position of the tile
		 * @param y the y position of the tile
		 */
		void ControllerGUI::currentPlayerTryGoTo(unsigned int x, unsigned int y) {
			try {
				if (this->game->canCurrentPlayerGoTo(model::Position{x, y})) {
					this->game->currentPlayerGoTo(model::Position{x, y});
					std::cout << "Goto " << x << " " << y << std::endl;
					this->game->currentPlayerCheckObjective();
					if (this->game->hasWinner()) {
						this->guiView->displayWinner();
					}
					this->game->nextPlayer();
				} else {
					std::cerr << "Cannot goto " << x << " " << y << std::endl;
				}
				this->guiView->updateDisplay();
			} catch (std::exception const &e) {
				std::cout << e.what() << std::endl;
			}
		}

	} // namespace controller
} // namespace Labyrinth_44422
