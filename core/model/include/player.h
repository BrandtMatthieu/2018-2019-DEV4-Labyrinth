#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

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
				std::string color;
				Position position;
				std::vector<ObjectiveCard *> objectiveCardsLeft;
				std::vector<ObjectiveCard *> completedObjectiveCards;

				bool _hasInsertedTile = false;
				bool _hasMovedPawn = false;
				
			public:
				Player(const std::string & nickname, const std::string & color, const Position & position);
				Player(const Player & player);
				Player & operator= (const Player & player);
				Player(Player && player) noexcept;
				Player & operator= (Player && player) noexcept;
				~Player(void);

				std::string getNickname(void) const;
				
				std::string getColor(void) const;
				
				Position getPosition(void) const;
				
				ObjectiveCard * getCurrentObjective(void) const;
				void completeCurrentObjective(void);
				
				std::vector<ObjectiveCard *> getCompletedObjectiveCards(void) const;
				unsigned int getObjectiveCount(void) const;
				
				std::vector<ObjectiveCard *> getObjectiveCardsLeft(void) const;
				unsigned int getObjectiveCardsLeftCount(void) const;
				void addObjective(ObjectiveCard * const & objectiveCard);
				
				bool hasInsertedTile(void) const;
				bool hasMovedPawn(void) const;
				
				void insertTile(void);
				void movePawn(const Position & position);
				void endTurn(void);
		};

	}
}

#endif // PLAYER_H
