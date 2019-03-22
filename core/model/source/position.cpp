#include "../include/position.h"

namespace Labyrinth_44422 {
	namespace model {
		
		/**
		 * Creates a new position
		 * @param x the x axis of the position
		 * @param y the y axis of the position
		 */
		Position::Position(unsigned int x, unsigned int y) :
			x{x},
			y{y}{}
		
		/**
		 * Creates a new position from an existing position
		 * aka. copy constructor
		 * @param position the existing position to create the new position from
		 */
		Position::Position(const Position & position) :
			x{position.x},
			y{position.y}{}
			
		/**
		 * Assigns the value of another object to this object
		 * @param position another position
		 * @return the new modified position
		 */
		Position & Position::operator=(Position const & position) {
			this->x = position.x;
			this->y = position.y;
			return *this;
		}
		
		/**
		 * Gets the x value of the position
		 * @return
		 */
		unsigned int Position::getX(void) const {
			return this->x;
		}
		
		/**
		 * Gets the y value of the position
		 * @return
		 */
		unsigned int Position::getY(void) const {
			return this->y;
		}

		/**
		 * Moves the position
		 * @param x the amount to move the position on the x axis
		 * @param y the amount to move the position on the y axis
		 */
		void Position::move(const unsigned int & x, const unsigned int & y) {
			this->x += x;
			this->y += y;
		}
		
		/**
		 * Moves the position
		 * @param amount the amount to move the position in some axis
		 * @param side the direction to which move the position to
		 */
		void Position::move(const unsigned int & amount, const InsertSide & side) {
			switch(side) {
				case InsertSide::UP:
					if(this->y - amount < 0) {
						this->y = 0;
					} else {
						this->y -= amount; // move towards up so y decreases
					}
					break;
				case InsertSide::DOWN:
					this->y += amount; // move towards down so y increases
					break;
				case InsertSide::RIGHT:
					this->x += amount; // move towards right so x increases
					break;
				case InsertSide::LEFT:
					if(this->x - amount < 0) {
						this->x = 0;
					} else {
						this->x -= amount; // move towards left so x decreases
					}
					break;
			}
		}
		
		/**
		 * Moves the position
		 * @param position the position to maje the sum from
		 */
		void Position::move(const Position & position) {
			this->x += position.x;
			this->y += position.y;
		}
		
		/**
		 * Sets the position to some values
		 * @param x
		 * @param y
		 */
		void Position::set(const unsigned int & x, const unsigned int & y) {
			this->x = x;
			this->y = y;
		}
		
		/**
		 * Sets the position to some values
		 * @param position the position to take the new position from
		 */
		void Position::set(const  Position & position) {
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
