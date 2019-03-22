#include "../include/objectiveCard.h"

namespace Labyrinth_44422 {
	namespace model {
		
		/**
		 * Creates a new objective card
		 * @param objective the objective on the card
		 */
		ObjectiveCard::ObjectiveCard(const std::string & objective) :
			objective{objective} {};
		
		/**
		 * Creates a new objective card from an other objective card
		 * aka. copy constructor
		 * @param objectiveCard
		 */
		ObjectiveCard::ObjectiveCard(const ObjectiveCard & objectiveCard) :
		objective{objectiveCard.getObjective()} {}
		
		/**
		 * Returns the objective on the objective card
		 * @return the objective on the objective card
		 */
		std::string ObjectiveCard::getObjective() const {
			return this->objective;
		}
	}
}
