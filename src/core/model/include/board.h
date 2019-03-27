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
				
				std::vector<Position> playersDefaultPositions;
				
				unsigned int indexOf(const std::vector<Tile *> & myVector,const Tile * const tile) const;
				bool includes(const std::vector<Tile *> & myVector,const Tile * const tile) const;

			public:
				explicit Board(const Position & maxPosition); // default constructor
				Board(const Board & board); // copy constructor
				void operator=(const Board & board);
				~Board(void); // destructor
			
				Position getMaxSize(void) const;
				unsigned int getMaxSizeX(void) const;
				unsigned int getMaxSizeY(void) const;
				bool positionInsideBoard(const Position & position) const;
				
				std::vector<Tile *> getTiles(void) const;
				unsigned int getTilesCount(void) const;
				Tile * getTilesAt(const Position &position) const;
				void setTile(const Position & position, const Tile * const tile);
				void setTile(const unsigned int x, const unsigned int y, const Tile * const tile);
				void setTile(const unsigned int index, const Tile * const tile);
				
				std::vector<Position> getPlayersDefaultPositions() const;
				
				bool canInsertTile(const Position & position, const InsertSide & side) const;
				Tile * insertTile(const Position & position, const Tile * const tile,  const InsertSide & side);
				
				bool canGoToFrom(const Position & from, const Position & to);
		};
	}  // namespace model
}  // namespace Labyrinth_44422

#endif // BOARD_H
