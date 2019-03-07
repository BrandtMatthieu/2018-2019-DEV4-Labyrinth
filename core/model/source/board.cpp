#include <stdexcept>
#include <core/model/include/board.h>


#include "../include/board.h"

namespace Labyrinth_44422 {
	namespace model {

		/**
		 * Creates a new board for the Labyrinth game
		 */
		Board::Board(void) {
		
		}
		
		/**
		 * Destroys the board object and cleans its members
		 */
		Board::~Board() {
			for(const auto & tile : this->tiles) {
				delete tile;
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
		Tile * Board::getTileAt(Position & position) const {
			if(this->positionInsideBoard(position)) {
				return this->tiles.at(position.getX() + position.getY() * this->getSizeHorizontal());
			} else {
				throw std::invalid_argument("Cannot get tile at " + position.toString() +
				".\nPosition is out of board's bounds (0;0) to (" + std::to_string(this->getSizeHorizontal()));
			}
		}
		
		/**
 * Checks if the provided position is inside the board
 * @param position the position to check
 * @return true if the provided position in inside the game's board
 */
		bool Board::positionInsideBoard(Position position) const {
			return position.getX() >= 0
				   && position.getX() < this->maxPosition.getX()
				   && position.getY() >= 0
				   && position.getY() < this->maxPosition.getY();
		}
		
		/**
		 * Sets a tile in the game's board
		 * @param position the position of where to set the tile
		 * @param tile the tile to set at the provided position
		 */
		void Board::setTile(Position & position, Tile * tile) {
			// TODO
		}
		
		/**
		 * Returns true if a tile can be inserted at the provided position
		 * @param position the position to check where to insert the tile
		 * @param side which side the tile need to be inserted in
		 * @return true if a tile can be inserted at the provided position
		 */
		bool Board::canInsertTile(Position & position, InsertSide & side) const {
			// TODO
			return false;
		}
		
		/**
		 * Inserts the tile at the provided position onto the game's board
		 * @param position the position where to insert the tile
		 * @param tile the tile to insert
		 * @param side what side to insert the tile at
		 */
		void Board::insertTile(Position & position, Tile * tile, InsertSide &side) {
			// TODO
		}
		
		/**
		 * Returns true if a player can go to a provided position
		 * @param position the position to check to player can go to
		 * @param player the player
		 * @return true if a player can go to a provided position
		 */
		bool Board::canPlayerGoTo(Position & position, Player * player) const {
			// TODO
			return false;
		}
	}
}
