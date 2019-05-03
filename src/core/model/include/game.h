#ifndef GAME_H
#define GAME_H

#include <vector>

#include "./board.h"
#include "./player.h"
#include "./tile.h"

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

				Board *board = nullptr;

				Player *winner = nullptr;

				std::vector<Tile *> availableTiles;

				unsigned int currentPlayerIndex = 0;

				std::vector<std::string> playerColors = {"Red", "Blue", "Green", "Yellow"};

				std::vector<ObjectiveCard *> objectiveCards;

				std::string getFirstPlayerColor(void);

				std::string getFirstGameObjective(void);

				void generateObjectiveCards(void);

				void playersFixPosition(const Position &position, const InsertSide &side);

			public:
				std::vector<std::string> gameObjectives = {"bat", "beetle", "bones", "butterfly", "candlestick", "crown", "dragon", "emerald", "fairy", "genius", "ghost", "gnome", "golden_purse", "grimoire", "helm", "keys", "lizard", "map", "owl", "rat", "ring", "spider", "sword", "treasure_chest"};

			public:
				Game(void);

				Game(const Game &game);

				Game &operator=(const Game &game);

				~Game(void);

				unsigned int getMinPlayers(void) const;

				unsigned int getMaxPlayers(void) const;

				std::vector<Player *> getPlayers(void) const;

				Player *getPlayerAt(const unsigned int index) const;

				unsigned int getPlayersCount(void) const;

				bool hasEnoughPlayers(void) const;

				Board *getBoard(void) const;

				Player *getWinner(void) const;

				bool hasWinner(void) const;

				std::vector<Tile *> getAvailableTiles(void) const;

				Player *getCurrentPlayer(void) const;

				void addPlayer(const std::string &name);

				void nextPlayer(void);

				void start(void);

				void dealObjectiveCardsToPlayers(void);

				void generateTiles(void);

				void currentPlayerCheckObjective(void);

				void currentPlayerInsertTile(const Position &position, const InsertSide &side);

				void currentPlayerGoTo(const Position &position);

				bool canCurrentPlayerGoTo(const Position &position);

				bool canCurrentPlayerInsertTile(void);
		};

	}  // namespace model
}  // namespace Labyrinth_44422

#endif // GAME_H
