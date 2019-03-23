#include <stdexcept>
#include <math.h>

#include "../include/board.h"
#include "../include/tile.h"

namespace Labyrinth_44422 {
	namespace model {
		
		/**
		 * Finds a tile in a vector of tiles and returns it's index
		 * @param myVector the vector where to search
		 * @param tile the tile to search for
		 * @return the index of the tiles in the provided vector
		 */
		unsigned int Board::indexOf(std::vector<Tile *> & myVector, Tile * tile) const {
			if(!this->includes(myVector, tile)) {
				throw std::runtime_error("Error while getting the index of the tile. The tile doesn't exists inside the vector.");
			}
			
			for(unsigned int i = 0; i < myVector.size(); i++) {
				if(this->tiles[i] == tile) {
					return i;
				}
			}
			return 0;
		}
		
		/**
		 * Returns true if an element exists in a vector
		 * @param myVector the vector where to search
		 * @param tile the tile to search for
		 * @return true if an element exists in a vector
		 */
		bool Board::includes(std::vector<Tile *> & myVector, Tile * tile) const {
			for(unsigned int i = 0; i < myVector.size(); i++) {
				if(this->tiles[i] == tile) {
					return true;
				}
			}
			return false;
		}

		/**
		 * Creates a new board for the Labyrinth game
		 */
		Board::Board(const Position & maxPosition) :
			maxSize{this->positionInsideBoard(maxPosition)
				?maxPosition
				:throw std::runtime_error("Error while initializing the board. Position not inside bounds.")},
			tiles{std::vector<Tile *>()} {}

		/**
		 * Creates a new board from an existing board
		 * aka. copy constructor
		 * @param board the board to create the new board from
		 */
		Board::Board(const Board & board) :
			maxSize{board.getMaxSize()},
			tiles{std::vector<Tile *>()} {
			for(Tile * const & tile_ptr : board.tiles) {
				this->tiles.push_back(new Tile(* tile_ptr));
			}
		}
		
		/**
		 * Destroys the board object and cleans its members
		 */
		Board::~Board() {
			for(Tile * const & tile_ptr : this->tiles) {
				delete tile_ptr;
			}
			this->tiles.clear();
		}
		
		/**
		 * Returns the horizontal size of the game's board
		 * @return the horizontal size of the game's board
		 */
		unsigned int Board::getMaxSizeX(void) const {
			return this->maxSize.getX();
		}
		
		/**
		 * Returns the vertical size of the game's board
		 * @return the vertical size of the game's board
		 */
		unsigned int Board::getMaxSizeY(void) const {
			return this->maxSize.getY();
		}

		/**
		 * Returns the max positions of the board
		 * @return the max positions of the board
		 */
		Position Board::getMaxSize(void) const {
			return this->maxSize;
		}
		
		/**
		 * Returns the vector containing the addresses of the tiles of the game
		 * @return the vector containing the addresses of the tiles of the game
		 */
		std::vector<Tile *> Board::getTiles(void) const {
			return this->tiles;
		}
		
		/**
		 * Returns the address of the tile at a provided position
		 * @param position  the position of the tile to get
		 * @return the address of the tile at a provided position
		 */
		Tile * Board::getTilesAt(const Position & position) const {
			if(!this->positionInsideBoard(position)) {
				throw std::invalid_argument("Error while getting the tile at " + position.toString() +
											". Position is out of board's bounds (0;0) to " +
											this->maxSize.toString());
			}
			
			return this->tiles.at(position.getX() + position.getY() * this->getMaxSizeX());
		}
		
		/**
		 * Checks if the provided position is inside the board
		 * @param position the position to check
		 * @return true if the provided position in inside the game's board
		 */
		bool Board::positionInsideBoard(const Position & position) const {
			return position.getX() < this->maxSize.getX() &&
					position.getY() < this->maxSize.getY();
		}
		
		/**
		 * Sets a tile in the game's board
		 * @param position the position of where to set the tile
		 * @param tile the tile to set at the provided position
		 */
		void Board::setTile(const Position & position, const Tile * const tile) {
			if(!this->positionInsideBoard(position)) {
				throw std::invalid_argument("Error while setting a tile at a position. Position is out of bounds");
			}
			
			this->tiles[position.getX() + position.getY() * this->getMaxSizeX()] = const_cast<Tile *>(tile);
		}
		
		/**
		 * Returns true if a tile can be inserted at the provided position
		 * @param position the position to check where to insert the tile
		 * @param side which side the tile need to be inserted in
		 * @return true if a tile can be inserted at the provided position
		 */
		bool Board::canInsertTile(const Position & position, const InsertSide & side) const {
			if(!this->positionInsideBoard(position)) {
				throw std::invalid_argument("Error while inserting a tile at a position. Position is out of bounds.");
			}
			
			bool lineMovable = true;
			switch(side) {
				case InsertSide::UP:
				case InsertSide::DOWN:
					for(unsigned int i = position.getX(); i < this->tiles.size(); i = i + this->getMaxSizeX()) {
						lineMovable = lineMovable && this->tiles.at(i)->isMovable();
					}
					break;
				case InsertSide::RIGHT:
				case InsertSide::LEFT:
					for(unsigned int i = position.getY() * this->getMaxSizeX(); i < (position.getY() + 1) *
																								  this->getMaxSizeX(); i++) {
						lineMovable = lineMovable && this->tiles.at(i)->isMovable();
					}
					break;
			}
			return lineMovable;
		}
		
		/**
		 * Inserts the tile at the provided position onto the game's board
		 * @param position the position where to insert the tile
		 * @param tile the tile to insert
		 * @param side what side to insert the tile at
		 */
		void Board::insertTile(const Position & position, const Tile * const tile, const InsertSide & side) {
			if(!this->positionInsideBoard(position)) {
				throw std::runtime_error("Error while inserting a tile. Position out of bounds.");
			}
			if(!this->canInsertTile(position, side)) {
				throw std::runtime_error("Error while inserting a tile. Column or row cannot move.");
			}
			
			switch(side) {
				case InsertSide::LEFT:
				case InsertSide::RIGHT:
					break;
				case InsertSide::DOWN:
				case InsertSide::UP:
					break;
			}
		}
		
		/**
		 * Returns true if a player can go to a provided position
		 * @param position the position to check to player can go to
		 * @param player the player
		 * @return true if a player can go to a provided position
		 */
		bool Board::canGoToFrom(Position & from, Position & to) {
			if(!this->positionInsideBoard(from)) {
				throw std::invalid_argument("Error while checking valid tiles. \"From\" position is out of bounds");
			}
			if(!this->positionInsideBoard(to)) {
				throw std::invalid_argument("Error while checking valid tiles. \"To\" position is out of bounds");
			}
			
			std::vector<Tile *> tilesToCheck;
			std::vector<Tile *> tilesPossible;
			std::vector<Tile *> tilesNotPossible;
			
			tilesPossible.push_back(this->tiles[from.getX() + from.getY() * (this->maxSize.getX())]);
			tilesToCheck.push_back(this->tiles[from.getX() + from.getY() * (this->maxSize.getX())]);
			
			unsigned int currentTileX;
			unsigned int currentTileY;
			
			while (!tilesToCheck.empty()) {
				Tile * currentTile = tilesToCheck[0];
				
				currentTileX = this->indexOf(this->tiles, currentTile) % this->maxSize.getX();
				currentTileY = this->indexOf(this->tiles, currentTile) / this->maxSize.getX();
				
				unsigned int index;
				if (currentTileX + 1 < this->maxSize.getX()) {
					index = (currentTileX + 1) + currentTileY * this->maxSize.getX();
					if (currentTile->getPathRIGHT() && this->tiles[index]->getPathLEFT() && !this->includes(tilesPossible, this->tiles[index])) {
						if (!this->includes(tilesToCheck, this->tiles[index])) {
							tilesToCheck.push_back(this->tiles[index]);
						}
						if (!this->includes(tilesPossible, this->tiles[index])) {
							tilesPossible.push_back(this->tiles[index]);
						}
						if (this->includes(tilesNotPossible, this->tiles[index])) {
							tilesNotPossible.erase(tilesNotPossible.begin() + this->indexOf(tilesNotPossible, this->tiles[index]));
						}
					} else {
						if (!this->includes(tilesNotPossible, this->tiles[index])) {
							tilesNotPossible.push_back(this->tiles[index]);
						}
					}
				}
				if (currentTileX >= 1) {
					index = (currentTileX - 1) + currentTileY * this->maxSize.getX();
					if (currentTile->getPathLEFT() && this->tiles[index]->getPathRIGHT() && !this->includes(tilesPossible, this->tiles[index])) {
						if (!this->includes(tilesToCheck, this->tiles[index])) {
							tilesToCheck.push_back(this->tiles[index]);
						}
						if (!this->includes(tilesPossible, this->tiles[index])) {
							tilesPossible.push_back(this->tiles[index]);
						}
						if (this->includes(tilesNotPossible, this->tiles[index])) {
							tilesNotPossible.erase(tilesNotPossible.begin() + this->indexOf(tilesNotPossible, this->tiles[index]));
						}
					} else {
						if (!this->includes(tilesNotPossible, this->tiles[index])) {
							tilesNotPossible.push_back(this->tiles[index]);
						}
					}
				}
				if (currentTileY >= 1) {
					index = currentTileX + (currentTileY - 1) * this->maxSize.getX();
					if (currentTile->getPathUP() && this->tiles[index]->getPathDOWN() && !this->includes(tilesPossible, this->tiles[index])) {
						if (!this->includes(tilesToCheck, this->tiles[index])) {
							tilesToCheck.push_back(this->tiles[index]);
						}
						if (!this->includes(tilesPossible, this->tiles[index])) {
							tilesPossible.push_back(this->tiles[index]);
						}
						if (this->includes(tilesNotPossible, this->tiles[index])) {
							tilesNotPossible.erase(tilesNotPossible.begin() + this->indexOf(tilesNotPossible, this->tiles[index]));
						}
					} else {
						if (!this->includes(tilesNotPossible, this->tiles[index])) {
							tilesNotPossible.push_back(this->tiles[index]);
						}
					}
				}
				if (currentTileY + 1 < this->maxSize.getY()) {
					index = currentTileX + (currentTileY + 1) * this->maxSize.getX();
					if (currentTile->getPathDOWN() && this->tiles[index]->getPathUP() && !this->includes(tilesPossible, this->tiles[index])) {
						if (!this->includes(tilesToCheck, this->tiles[index])) {
							tilesToCheck.push_back(this->tiles[index]);
						}
						if (!this->includes(tilesPossible, this->tiles[index])) {
							tilesPossible.push_back(this->tiles[index]);
						}
						if (this->includes(tilesNotPossible, this->tiles[index])) {
							tilesNotPossible.erase(tilesNotPossible.begin() + this->indexOf(tilesNotPossible, this->tiles[index]));
						}
					} else {
						if (!this->includes(tilesNotPossible, this->tiles[index])) {
							tilesNotPossible.push_back(this->tiles[index]);
						}
					}
				}
				tilesToCheck.erase(tilesToCheck.begin() + 0);
			}
			
			
			return this->includes(tilesPossible, this->tiles[to.getX() + to.getY() * this->maxSize.getX()]);
		}
	}
}
