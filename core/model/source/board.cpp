#include <stdexcept>

#include "../include/board.h"
#include "../include/tile.h"

namespace Labyrinth_44422 {
	namespace model {

		/**
		 * Creates a new board for the Labyrinth game
		 */
		Board::Board(const Position & maxPosition) :
			maxPosition{maxPosition},
			tiles{std::vector<Tile *>()} {}

		/**
		 * Creates a new board from an existing board
		 * aka. copy constructor
		 * @param board the board to create the new board from
		 */
		Board::Board(const Board & board) :
			maxPosition{board.getMaxPosition()},
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
		unsigned int Board::getSizeHorizontal(void) const {
			return this->maxPosition.getX();
		}
		
		/**
		 * Returns the vertical size of the game's board
		 * @return the vertical size of the game's board
		 */
		unsigned int Board::getSizeVertical(void) const {
			return this->maxPosition.getY();
		}

		/**
		 * Returns the max positions of the board
		 * @return the max positions of the board
		 */
		Position Board::getMaxPosition(void) const {
			return this->maxPosition;
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
		Tile * Board::getTileAt(const Position & position) const {
			if(this->positionInsideBoard(position)) {
				return this->tiles.at(position.getX() + position.getY() * this->getSizeHorizontal());
			}
			throw std::invalid_argument("Cannot get tile at " + position.toString() +
				".\nPosition is out of board's bounds (0;0) to (" + std::to_string(this->getSizeHorizontal()));
		}
		
		/**
		 * Checks if the provided position is inside the board
		 * @param position the position to check
		 * @return true if the provided position in inside the game's board
		 */
		bool Board::positionInsideBoard(const Position & position) const {
			return position.getX() < this->maxPosition.getX()
				   && position.getY() < this->maxPosition.getY();
		}
		
		/**
		 * Sets a tile in the game's board
		 * @param position the position of where to set the tile
		 * @param tile the tile to set at the provided position
		 */
		void Board::setTile(const Position & position, Tile const * tile) {
			// TODO
		}
		
		/**
		 * Returns true if a tile can be inserted at the provided position
		 * @param position the position to check where to insert the tile
		 * @param side which side the tile need to be inserted in
		 * @return true if a tile can be inserted at the provided position
		 */
		bool Board::canInsertTile(const Position & position, const InsertSide & side) const {
			// TODO
			return false;
		}
		
		/**
		 * Inserts the tile at the provided position onto the game's board
		 * @param position the position where to insert the tile
		 * @param tile the tile to insert
		 * @param side what side to insert the tile at
		 */
		void Board::insertTile(const Position & position, Tile const * tile, const InsertSide & side) {
			// TODO
		}
		
		/**
		 * Returns true if a player can go to a provided position
		 * @param position the position to check to player can go to
		 * @param player the player
		 * @return true if a player can go to a provided position
		 */
		bool Board::canPlayerGoTo(const Position & position, Player const * player) const {
			// TODO
			return false;
		}
	}
}
