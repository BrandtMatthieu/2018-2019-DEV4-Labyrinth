#ifndef GAME_H
#define GAME_H

#include <vector>

#include "./Board.h"
#include "./Tile.h"
#include "./Player.h"

namespace Labyrinth_44422 {
	namespace model {

		class Game {
			private:
				unsigned int minPlayers = 2;
				unsigned int maxPlayers = 4;
				std::vector<Player *> players;
				Board * board;
				Player * winner;
				std::vector<Tile *> avaliableTiles;
				unsigned int currentPlayerIndex;

			public:
				Game();
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
