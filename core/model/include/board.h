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
		 * @version 0.1.2
		 * @since 2019-03-01
		 */
		class Board {
			private:
				Position maxSize{7, 7};
				std::vector<Tile *> tiles;
			
				unsigned int indexOf(std::vector<Tile *> & myVector, Tile * tile) const;
				bool includes(std::vector<Tile *> & myVector, Tile * tile) const;

			public:
				Board(const Position & maxPosition); // default constructor
				Board(const Board & board); // copy constructor
				Board & operator= (const Board & board); // copy assignment operator
				Board(Board && board) noexcept; // move constructor
				Board & operator= (Board && board) noexcept; // move assignment operator
				~Board(void); // destructor
			
				Position getMaxSize(void) const;
				unsigned int getMaxSizeX(void) const;
				unsigned int getMaxSizeY(void) const;
				bool positionInsideBoard(const Position & position) const;
				
				std::vector<Tile *> getTiles(void) const;
				unsigned int getTilewCount(void) const;
				Tile * getTilesAt(const Position &position) const;
				void setTile(const Position & position, const Tile * const tile);
				void setTile(const unsigned int index, const Tile * const tile);
				
				bool canInsertTile(const Position & position, const InsertSide & side) const;
				void insertTile(const Position & position, const Tile * const tile,  const InsertSide & side);
				
				bool canGoToFrom(Position & from, Position & to);
		};
	}
}

#endif // BOARD_H
