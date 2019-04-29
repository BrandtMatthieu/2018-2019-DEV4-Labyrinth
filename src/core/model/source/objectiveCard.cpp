#include "./../include/objectiveCard.h"

namespace Labyrinth_44422 {
	namespace model {

		/**
		 * Creates a new objective card
		 * @param objective the objective on the card
		 */
		ObjectiveCard::ObjectiveCard(const std::string &objective) : objective{objective} {
		}

		/**
		 * Creates a new objective card from an other objective card
		 * aka. copy constructor
		 * @param objectiveCard
		 */
		ObjectiveCard::ObjectiveCard(const ObjectiveCard &objectiveCard) : objective{objectiveCard.getObjective()} {
		}

		/**
		 * Returns true if two objective cards are equals
		 * @param card another card
		 * @return true if both objective cards are equals
		 */
		bool ObjectiveCard::operator==(const ObjectiveCard &card) const {
			return this->hasObjective() && card.hasObjective() && this->getObjective() == card.getObjective();
		}

		/**
		 * Returns true if two objective cards are different
		 * @param card another card
		 * @return true if both objective cards are different
		 */
		bool ObjectiveCard::operator!=(const ObjectiveCard &card) const {
			return (this->hasObjective() && !card.hasObjective()) || (!this->hasObjective() && card.hasObjective()) || (this->hasObjective() && card.hasObjective() && this->getObjective() != card.getObjective());
		}

		/**
		 * Returns the objective on the objective card
		 * @return the objective on the objective card
		 */
		std::string ObjectiveCard::getObjective(void) const {
			return this->objective;
		}

		/**
		 * Returns true if the card has an objective on it
		 * @return true if the card has an objective on it
		 */
		bool ObjectiveCard::hasObjective(void) const {
			return !this->objective.empty();
		}
	}  // namespace model
}  // namespace Labyrinth_44422
