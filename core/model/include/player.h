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
				Position position;
				std::vector<ObjectiveCard *> objectiveCardsLeft;
				std::vector<ObjectiveCard *> completedObjectiveCards;

				bool hasInsertedTile = false;
				bool hasMovedPawn = false;
				
			public:
				Player(std::string & nickname, Colors & color, Position & position);
				~Player(void);
				std::string getNickname(void) const;
				Colors getColor(void) const;
				Position getPosition(void) const;
				ObjectiveCard * getCurrentObjective(void) const;
				unsigned int getObjectiveCount(void) const;
				bool getHasInsertedTile(void) const;
				bool getHasMovedPawn(void) const;
				
				void completeCurrentObjective(void);
				void addObjective(ObjectiveCard * objectiveCard);
				void insertTile();
				void movePawn(Position & position);
				void endTurn(void);
		};

	}
}

#endif // PLAYER_H
