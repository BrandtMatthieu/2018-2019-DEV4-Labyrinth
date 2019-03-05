#include "../include/objectiveCard.h"

namespace Labyrinth_44422 {
	namespace model {
		
		/**
		 * Creates a new objective card
		 * @param objective the objective on the card
		 */
		ObjectiveCard::ObjectiveCard(ObjectivesTypes & objective) {
			this->objective = objective;
		};
		
	}
}
