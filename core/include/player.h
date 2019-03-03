#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

#include "./colors.h"
#include "./objectiveCard.h"

namespace Labyrinth_44422 {
	namespace model {

		class Player {
			private:
				std::string nickname;
				Colors color;
				unsigned int positionVerticale;
				unsigned int positionHorizontale;
				std::vector<ObjectiveCard *> objectiveCards;

			public:
				Player();
				std::string getNickname() const;
				Colors getColor() const;
				unsigned int getPositionVerticale() const;
				unsigned int getPositionHorizontale() const;
				ObjectiveCard * getCurrentObjective() const;
				unsigned int getObjectiveCount() const;
				void completeCurrentObjective();
				void insertTile();
				void movePawn();
				void endTurn();
		};

	}
}

#endif // PLAYER_H
