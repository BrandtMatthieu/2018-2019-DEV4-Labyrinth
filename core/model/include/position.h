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
				Position(const Position & position);
				Position & operator=(const Position & position);
				~Position() = default;
				
				unsigned int getX(void) const;
				unsigned int getY(void) const;
				
                void move(const unsigned int & x, const unsigned int & y);
				void move(const unsigned int & amount, const InsertSide & side);
				void move(const Position & position);
				void set(const unsigned int & x, const unsigned int & y);
				void set(const Position & position);
				std::string toString(void) const;
		};

	}
}

#endif // POSITION_H
