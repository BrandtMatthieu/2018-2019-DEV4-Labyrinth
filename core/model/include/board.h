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
				Position maxPosition{7, 7};
				std::vector<Tile *> tiles;

			public:
				Board(const Position & maxPosition); // default constructor
				Board(const Board & board); // copy constructor
				Board & operator= (const Board & board); // copy assignment operator
				Board(Board && board) noexcept; // move constructor
				Board & operator= (Board && board) noexcept; // move assignement operator
				~Board(void); // destructor
			
				unsigned int getSizeHorizontal(void) const;
				unsigned int getSizeVertical(void) const;
				Position getMaxPosition(void) const;
				std::vector<Tile *> getTiles(void) const;
				Tile * getTileAt(const Position & position) const;
				
				void setTile(const Position & position,  Tile const * tile);
				bool canInsertTile(const Position & position, const InsertSide & side) const;
				void insertTile(const Position & position, 	Tile const * tile,  const InsertSide & side);
				bool canPlayerGoTo(const Position & position, Player const * player) const;
				bool positionInsideBoard(const Position & position) const;

                };
	}
}

#endif // BOARD_H
