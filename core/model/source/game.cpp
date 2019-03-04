#include "../include/game.h"

namespace Labyrinth_44422 {
	namespace model {

		/**
		 * Creates a new Labyrinth game
		 */
		Game::Game(void) {
			this->board = new Board();
		}

		/**
		 * Cleans the game item before it is getting destroyed
		 */
		Game::~Game(void) {
			delete this->board;
			for(const auto & element : this->players) {
				delete element;
			}
			this->players.clear();
		}

	}
}
