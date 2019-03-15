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
		 * @version 0.1.1
		 * @since 2019-03-01
		 */
		class Game {
			private:
				unsigned int minPlayers = 2;
				unsigned int maxPlayers = 4;
				std::vector<Player *> players;
				Board * board = nullptr;
				Player * winner = nullptr;
				std::vector<Tile *> availableTiles;
				unsigned int currentPlayerIndex = 0;

			public:
				Game(void);
				Game(const Game & game);
				Game & operator= (const Game & game);
				Game(Game && game) noexcept;
				Game & operator= (Game && game) noexcept;
				~Game(void);

				unsigned int getMinPlayers(void) const;
				unsigned int getMaxPlayers(void) const;
				std::vector<Player *> getPlayers(void) const;
				unsigned int getPlayersCount(void) const;
				bool hasEnoughPlayers(void) const;
				bool hasWinner(void) const;
				Board * getBoard(void) const;
				Player * getWinner(void) const;
				std::vector<Tile *> getAvailableTiles(void) const;
				Player * getCurrentPlayer(void) const;

				void addPlayer(const std::string & name);
				void nextPlayer(void);
				void start(void);
		};

	}
}

#endif // GAME_H
