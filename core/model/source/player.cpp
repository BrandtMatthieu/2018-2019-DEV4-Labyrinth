
#include <core/model/include/player.h>
#include <stdexcept>

#include "../include/player.h"

namespace Labyrinth_44422 {
	namespace model {
		
		/**
		 * Creates anew player for the game
		 * @param nickname the nickname of the player
		 * @param color the color of the player's pawn
		 */
		Player::Player(std::string & nickname, Colors & color, Position & position): position{position.getX(), position.getY()} {
			this->nickname = nickname;
			this->color = color;
			this->position = position;
		}
		
		/**
		 * Destroy the player and cleans it's members
		 */
		Player::~Player(void) {
			for(const auto & objectiveCard : this->objectiveCardsLeft) {
				delete objectiveCard;
			}
			this->objectiveCardsLeft.clear();
			
			for(const auto & objectiveCard : this->completedObjectiveCards) {
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
		Colors Player::getColor(void) const {
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
		 * @return the player's current objective
		 */
		ObjectiveCard * Player::getCurrentObjective(void) const {
			if(this->objectiveCardsLeft.size()>0) {
				return this->objectiveCardsLeft.at(0);
			} else {
				throw std::range_error("Cannot return the player's current objective.\nThere are no objective cards left.");
			}

		}
		
		/**
		 * Returns the number of objective cards the player has left
		 * @return the number of objective cards the player has left
		 */
		unsigned int Player::getObjectiveCount(void) const {
			return this->objectiveCardsLeft.size();
		}
		
		/**
		 * Returns true if the player has already inserted a tile in the board
		 * @return true if the player has already inserted a tile in the board
		 */
		bool Player::getHasInsertedTile(void) const {
			return this->hasInsertedTile;
		}
		/**
		 * Returns true if the player has already moved his pawn
		 * @return true if the player has already moved his pawn
		 */
		bool Player::getHasMovedPawn(void) const {
			return this->hasMovedPawn;
		}
		
		/**
		 * Completes the current objective card of the player and adds it to the completed objectives
		 */
		void Player::completeCurrentObjective(void) {
			if(this->objectiveCardsLeft.size()>0) {
				this->completedObjectiveCards.push_back(this->objectiveCardsLeft.at(0));
				this->objectiveCardsLeft.erase(this->objectiveCardsLeft.begin());
			} else {
				throw std::range_error("Cannot complete current objective.\nThere are no objective cards left.");
			}
			
		}
		
		/**
		 * Adds an objective to the player
		 * @param objectiveCard the objective card to add to the player
		 */
		void Player::addObjective(ObjectiveCard * objectiveCard) {
			this->objectiveCardsLeft.push_back(objectiveCard);
		}
		
		/**
		 * Makes the player insert a tile on the board
		 */
		void Player::insertTile() {
			this->hasInsertedTile = true;
		}
		
		/**
		 * Move the player's pawn
		 * @param position the new position of the player's pawn
		 */
		void Player::movePawn(Position & position) {
			if(!this->hasMovedPawn) {
				this->position = position;
				this->hasMovedPawn = true;
			} else {
				throw std::runtime_error("Cannot move pawn. Pawn has already been moved.");
			}
		}
		
		/**
		 * Ends the player's turn
		 */
		void Player::endTurn(void) {
			this->hasInsertedTile = false;
			this->hasMovedPawn = false;
		}
	}
}
