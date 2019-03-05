
#include <core/model/include/position.h>

#include "../include/position.h"

namespace Labyrinth_44422 {
	namespace model {
		
		/**
		 * Creates a new position
		 * @param x the x axis of the position
		 * @param y the y axis of the position
		 */
		Position::Position(unsigned int & x, unsigned int & y) {
			this->x = x;
			this->y = y;
		}
		
		/**
		 * Creates a new position from an existing position
		 * aka. copy constructor
		 * @param position the existing position to create the new position from
		 */
		Position::Position(Position & position) {
			this->x = position.x;
			this->y = position.y;
		}

		/**
		 * Moves the position
		 * @param x the amount to move the position on the x axis
		 * @param y the amount to move the position on the y axis
		 */
		void Position::move(unsigned int &x, unsigned int &y) {
			this->x += x;
			this->y += y;
		}
		
		/**
		 * Moves the position
		 * @param amount the amount to move the position in some axis
		 * @param side the direction to which move the position to
		 */
		void Position::move(unsigned int & amount, InsertSide & side) {
			switch(side) {
				case InsertSide::UP:
					this->y += amount;
					break;
				case InsertSide::DOWN:
					this->y -= amount;
					break;
				case InsertSide::RIGHT:
					this->x += amount;
					break;
				case InsertSide::LEFT:
					this->x -= amount;
					break;
			}
		}
		
		/**
		 * Moves the position
		 * @param position the position to maje the sum from
		 */
		void Position::move(Position & position) {
			this->x += position.x;
			this->y += position.y;
		}
		
		/**
		 * Sets the position to some values
		 * @param x
		 * @param y
		 */
		void Position::set(unsigned int & x, unsigned int & y) {
			this->x = x;
			this->y = y;
		}
		
		/**
		 * Sets the position to some values
		 * @param position the position to take the new position from
		 */
		void Position::set(Position & position) {
			this->x = position.x;
			this->y = position.y;
		}
		
		/**
		 * Returns the position as a string
		 * @return the position as a string
		 */
		std::string Position::toString(void) const {
			return "(" + std::to_string(this->x) + ";" + std::to_string(this->y) + ")";
		}
		
	}
}
