#ifndef GAME_H
#define GAME_H

#include <vector>

#include "./board.h"
#include "./tile.h"
#include "./player.h"

namespace Labyrinth_44422 {
	namespace model {

		/**
		 * Represents the labyrinth board game
		 * @author 44422
		 * @version 0.1.0
		 * @since 2019-03-01
		 */
		class Game {
			private:
				unsigned int minPlayers = 2;
				unsigned int maxPlayers = 4;
				std::vector<Player *> players;
				Board * board = nullptr;
				Player * winner = nullptr;
				std::vector<Tile *> avaliableTiles;
				unsigned int currentPlayerIndex = 0;

			public:
				Game(void);
				~Game(void);
				unsigned int getMinPlayers() const;
				unsigned int getMaxPlayers() const;
				std::vector<Player *> getPlayers() const;
				Board * getBoard() const;
				Player * getWinner() const;
				std::vector<Tile *> getAvaliableTiles() const;
				Player * getCurrentPlayer() const;
				void addPlayer(Player * player);
				void nextPlayer();
				void start();
		};

	}
}

#endif // GAME_H
