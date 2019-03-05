#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

#include "./colors.h"
#include "./objectiveCard.h"
#include "./position.h"

namespace Labyrinth_44422 {
	namespace model {

		/**
		 * Represents a player for the game
		 * @author 44422
		 * @version 0.1.1
		 * @since 2019-03-01
		 */
		class Player {
			private:
				std::string nickname;
				Colors color;
				unsigned int positionVerticale;
				unsigned int positionHorizontale;
				std::vector<ObjectiveCard *> objectiveCards;

			public:
				Player(std::string nickname, Colors color);
				std::string getNickname(void) const;
				Colors getColor(void) const;
				unsigned int getPositionVerticale(void) const;
				unsigned int getPositionHorizontale(void) const;
				ObjectiveCard * getCurrentObjective(void) const;
				unsigned int getObjectiveCount(void) const;
				void completeCurrentObjective(void);
				void insertTile(Position position, InsertSide side);
				void movePawn(Position position);
				void endTurn(void);
		};

	}
}

#endif // PLAYER_H
