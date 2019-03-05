#include "../include/player.h"

namespace Labyrinth_44422 {
	namespace model {
		
		/**
		 * Creates anew player for the game
		 * @param nickname the nickname of the player
		 * @param color the color of the player's pawn
		 */
		Player::Player(std::string nickname, Colors color) {
			this->nickname = nickname;
			this->color = color;
		}
	}
}
