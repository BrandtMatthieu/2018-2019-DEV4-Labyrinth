#ifndef OBJECTIVECARD_H
#define OBJECTIVECARD_H

#include "./objectivesTypes.h"

namespace Labyrinth_44422 {
	namespace model {
		
		/**
		 * Represents an objective card for the players
		 * @author 44422
		 * @version 0.1.0
		 * @since 2019-03-03
		 */
		class ObjectiveCard {
			private:
				ObjectivesTypes objective;
			public:
				ObjectiveCard(ObjectivesTypes & objective);
				ObjectivesTypes getObjective(void) const;
		};
		
	}
}

#endif // OBJECTIVECARD_H
