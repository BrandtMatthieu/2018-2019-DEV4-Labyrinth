#ifndef OBJECTIVECARD_H
#define OBJECTIVECARD_H

#include "./objectivesTypes.h"

namespace Labyrinth_44422 {
	namespace model {
		
		class ObjectiveCard {
			private:
				ObjectivesTypes objective;
			public:
				ObjectiveCard();
				ObjectivesTypes getObjective() const;
		};
		
	}
}

#endif // OBJECTIVECARD_H
