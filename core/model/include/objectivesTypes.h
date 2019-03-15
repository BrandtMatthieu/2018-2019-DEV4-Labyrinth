#ifndef OBJECTIVESTYPES_H
#define OBJECTIVESTYPES_H

#include <string>

namespace Labyrinth_44422 {
	namespace model {

		/**
		 * Represents an objective on an objective tile or on a tile
		 * @author 44422
		 * @version 0.1.0
		 * @since 2019-03-03
		 */
		class ObjectivesTypes {
			public:
				enum Value : uint8_t {
					BAT,
					BEETLE,
					BONES,
					BUTTERFLY,
					CANDLESTICK,
					CROWN,
					DRAGON,
					EMERALD,
					FAIRY,
					GENIUS,
					GHOST,
					GNOME,
					GOLDEN_PURSE,
					GRIMOIRE,
					HELM,
					KEYS,
					LIZARD,
					MAP,
					OWL,
					RAT,
					RING,
					SPIDER,
					SWORD,
					TREASURE_CHEST
				};
			
				static const std::string objective_names[];
			private:
				Value value;
				
				/**
				* The name of the different objectives in the enum
				*/
				
			
			public:
			
				ObjectivesTypes() = default;
				explicit ObjectivesTypes(const Value & objective) : value(objective) {};
				
				bool operator== (const ObjectivesTypes & objective) const { return this->value == objective.value; }
				bool operator!= (const ObjectivesTypes & objective) const { return this->value != objective.value; }
				
				std::string getObjectiveName(void) {
					unsigned int index = 0;
					while(this->value != Value(index)) {
						index++;
					}
					return ObjectivesTypes::objective_names[index];
				}
				
				static ObjectivesTypes get(unsigned int index) {
					return ObjectivesTypes(Value(index));
				}
		};
		
	}
}

#endif // OBJECTIVESTYPES_H
