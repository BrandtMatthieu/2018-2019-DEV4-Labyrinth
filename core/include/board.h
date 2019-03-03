#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include "./tile.h"

namespace Labyrinth_44422 {
	namespace model {

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