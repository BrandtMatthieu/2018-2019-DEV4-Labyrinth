#include <stdexcept>

#include "./../include/player.h"

namespace Labyrinth_44422 {
    namespace model {

        /**
         * Creates a new player for the game
         * @param nickname the nickname of the player
         * @param color the color of the player's pawn
         */
        Player::Player(const std::string &nickname, const std::string &color, const Position &position) :
                nickname{nickname},
                color{color},
                position{position.getX(), position.getY()} {
        }

        /**
         * Creates a new player from an existing player
         * aka. copy constructor
         * @param player the player to create the new player from
         */
        Player::Player(const Player &player) :
                nickname{player.nickname},
                color{player.color},
                position{player.position},
                objectiveCardsLeft{player.objectiveCardsLeft},
                completedObjectiveCards{player.completedObjectiveCards},
                _hasInsertedTile{player._hasInsertedTile},
                _hasMovedPawn{player._hasMovedPawn} {
        }

        /**
         * Destroy the player and cleans it's members
         */
        Player::~Player(void) {
            for (const auto &objectiveCard : this->objectiveCardsLeft) {
                delete objectiveCard;
            }
            this->objectiveCardsLeft.clear();

            for (const auto &objectiveCard : this->completedObjectiveCards) {
                delete objectiveCard;
            }
            this->completedObjectiveCards.clear();
        }

        /**
         * Returns the player's nickname
         * @return the player's nickname
         */
        std::string Player::getNickname(void) const {
            return this->nickname;
        }

        /**
         * Returns the player's color
         * @return the player's color
         */
        std::string Player::getColor(void) const {
            return this->color;
        }

        /**
         * Returns the player's position
         * @return the player's position
         */
        Position Player::getPosition(void) const {
            return this->position;
        }

        /**
         * Returns the player's current objective
         * @throw range_error if there is no current objective to retrieve
         * @return the player's current objective
         */
        ObjectiveCard *Player::getCurrentObjective(void) const {
            if (this->objectiveCardsLeft.empty()) {
                throw std::range_error("Error while getting the player's current objective. There are no objective cards left.");
            }

            return this->objectiveCardsLeft.at(0);
        }

        /**
         * Returns all the completed objective cards inside a vector
         * @return all the completed objective cards inside a vector
         */
        std::vector<ObjectiveCard *> Player::getCompletedObjectiveCards(void) const {
            return this->completedObjectiveCards;
        }

        /**
         * Returns the number of objective cards the player has left
         * @return the number of objective cards the player has left
         */
        unsigned int Player::getCompletedObjectiveCardsCount(void) const {
            return this->completedObjectiveCards.size();
        }

        /**
         * Returns all the objective cards left inside a vector
         * @return all the objective cards left inside a vector
         */
        std::vector<ObjectiveCard *> Player::getObjectiveCardsLeft(void) const {
            return this->objectiveCardsLeft;
        }

        /**
         * Returns the amount of objective cards left
         * @return the amount of objective cards left
         */
        unsigned int Player::getObjectiveCardsLeftCount(void) const {
            return this->objectiveCardsLeft.size();
        }

        /**
         * Returns true if the player has already inserted a tile in the board
         * @return true if the player has already inserted a tile in the board
         */
        bool Player::hasInsertedTile(void) const {
            return this->_hasInsertedTile;
        }

        /**
         * Returns true if the player has already moved his pawn
         * @return true if the player has already moved his pawn
         */
        bool Player::hasMovedPawn(void) const {
            return this->_hasMovedPawn;
        }

        /**
         * Completes the current objective card of the player and adds it to the completed objectives
         * @throw runtime_error if cannot complete the current objective
         */
        void Player::completeCurrentObjective(void) {
            if (this->objectiveCardsLeft.empty()) {
                throw std::runtime_error("Cannot complete current objective. There are no objective cards left.");
            }

            this->completedObjectiveCards.push_back(this->objectiveCardsLeft.at(0));
            this->objectiveCardsLeft.erase(this->objectiveCardsLeft.begin());
        }

        /**
         * Adds an objective to the player
         * @param objectiveCard the objective card to add to the player
         */
        void Player::addObjective(ObjectiveCard *const &objectiveCard) {
            this->objectiveCardsLeft.push_back(objectiveCard);
        }

        /**
         * Makes the player insert a tile on the board
         */
        void Player::insertTile(void) {
            this->_hasInsertedTile = true;
        }

        /**
         * Move the player's pawn
         * @param position the new position of the player's pawn
         * @throw runtime_error if player hasn't inserted a tile in the labyrinth yet
         */
        void Player::movePawn(const Position &position) {
            if (!this->_hasInsertedTile) {
                throw std::runtime_error("Cannot move pawn. You need to insert a tile in the Labyrinth first.");
            }

            this->position = position;
            this->_hasMovedPawn = true;
        }

        /**
         * Ends the player's turn
         */
        void Player::endTurn(void) {
            this->_hasInsertedTile = false;
            this->_hasMovedPawn = false;
        }
    }  // namespace model
}  // namespace Labyrinth_44422
