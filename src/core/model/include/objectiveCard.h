#ifndef OBJECTIVECARD_H
#define OBJECTIVECARD_H

#include <string>

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
            std::string objective = "";
        public:
            explicit ObjectiveCard(const std::string &objective);

            ObjectiveCard(const ObjectiveCard &objectiveCard);

            ~ObjectiveCard(void) = default;

            bool operator==(const ObjectiveCard &card) const;

            bool operator!=(const ObjectiveCard &card) const;

            std::string getObjective(void) const;

            bool hasObjective(void) const;


        };

    } // namespace model
} // namespace Labyrinth_44422

#endif // OBJECTIVECARD_H
