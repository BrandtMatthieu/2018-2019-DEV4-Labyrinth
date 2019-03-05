#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include "./insertSide.h"
#include "./player.h"
#include "./position.h"
#include "./tile.h"

namespace Labyrinth_44422 {
	namespace model {
	
		/**
		 * Represents the board in the Labyrinth game
		 * @author 44422
		 * @version 0.1.1
		 * @since 2019-03-01
		 */
		class Board {
			private:
				unsigned int sizeHorizontal = 7;
				unsigned int sizeVertical = 7;
				std::vector<Tile *> tiles;

			public:
				Board();
			
				bool positionInsideBoard(Position position) const;
				
				unsigned int getSizeHorizontal(void) const;
				unsigned int getSizeVertical(void) const;
				std::vector<Tile *> getTiles(void) const;
				Tile * getTileAt(Position & position) const;
				
				void setTile(Position & position, 		Tile * tile);
				bool canInsertTile(Position & position, InsertSide & side) const;
				void insertTile(Position & position, 	Tile * tile,  InsertSide & side);
				bool canPlayerGoTo(Position & position, Player * player) const;
		};

	}
}

#endif // BOARD_H
