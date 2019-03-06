#ifndef POSITION_H
#define POSITION_H

#include <string>
#include "../include/insertSide.h"

namespace Labyrinth_44422 {
	namespace model {
		
		/**
		 * Represents a position of any object in the game
		 * @author 44422
		 * @version 0.1.2
		 * @since 2019-03-04
		 */
		class Position {
			private:
				unsigned int x;
				unsigned int y;
			public:
				Position(unsigned x, unsigned y);
				Position(Position & position);
				unsigned int getX(void) const;
				unsigned int getY(void) const;
				void move(unsigned int & x, unsigned int & y);
				void move(unsigned int & amount, InsertSide & side);
				void move(Position & position);
				void set(unsigned int & x, unsigned int & y);
				void set(Position & position);
				std::string toString(void) const;
		};
		
	}
}

#endif // POSITION_H
