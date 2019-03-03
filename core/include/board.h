#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include "./tile.h"

namespace Labyrinth_44422 {
	namespace model {
	
		/**
		 * Represents the board in the Labyrinth game
		 * @author 44422
		 * @version 0.1.0
		 * @since 2019-03-01
		 */
		class Board {
			private:
				unsigned int sizeHorizontal = 7;
				unsigned int sizeVertical = 7;
				std::vector<Tile *> tiles;

			public:
				Board();
				unsigned int getSizeHorizontal() const;
				unsigned int getSizeVertical() const;
				std::vector<Tile *> getTiles() const;
				void setTile();
				bool canInsertTile() const;
				void insertTile();
				bool canPlayerGoTo() const;
		};

	}
}

#endif // BOARD_H
