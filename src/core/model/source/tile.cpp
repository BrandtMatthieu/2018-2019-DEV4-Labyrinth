#include "./../include/tile.h"

namespace Labyrinth_44422 {
	namespace model {

		/**
		 * Creates a new tile
		 * @param pathUP if there is a way up
		 * @param pathDOWN if there is a way down
		 * @param pathRIGHT if there is a way to the right
		 * @param pathLEFT if there is a way to the left
		 * @param position the position of the tile
		 * @param movable if the tile can be moved
		 * @param objective the objective of the tile
		 * @param startNumber the start number of the player
		 */
		Tile::Tile(const bool &pathUP, const bool &pathDOWN, const bool &pathRIGHT, const bool &pathLEFT, const Position &position, const bool &movable, const std::string &objective, const unsigned int startNumber) : pathUP{pathUP}, pathDOWN{pathDOWN}, pathRIGHT{pathRIGHT}, pathLEFT{pathLEFT}, position{position}, movable{movable}, objective{objective}, startNumber{startNumber} {
		}

		/**
		 * Creates a new tile from another tile
		 * aka. copy constructor
		 * @param tile the tile to create the new tile from
		 */
		Tile::Tile(const Tile &tile) : pathUP{tile.pathUP}, pathDOWN{tile.pathDOWN}, pathRIGHT{tile.pathRIGHT}, pathLEFT{tile.pathLEFT}, position{tile.position}, movable{tile.movable}, objective{tile.objective}, startNumber{tile.startNumber} {
		}

		/**
		 * Returns true if two tiles are equals
		 * @param tile another tile
		 * @return true if both tiles are equals
		 */
		bool Tile::operator==(const Tile &tile) const {
			return pathUP == tile.pathUP && pathDOWN == tile.pathDOWN && pathRIGHT == tile.pathRIGHT && pathLEFT == tile.pathLEFT && position == tile.position && movable == tile.movable && objective == tile.objective && startNumber == tile.startNumber;
		}

		/**
		 * Returns true if two tiles are different
		 * @param tile another tile
		 * @return true if two tiles are different
		 */
		bool Tile::operator!=(const Tile &tile) const {
			return pathUP != tile.pathUP || pathDOWN != tile.pathDOWN || pathRIGHT != tile.pathRIGHT || pathLEFT != tile.pathLEFT || position != tile.position || movable != tile.movable || objective != tile.objective || startNumber != tile.startNumber;
		}

		/**
		 * Returns true if the tile has a path up
		 * @return true if the tile has a path up
		 */
		bool Tile::getPathUP(void) const {
			return this->pathUP;
		}

		/**
		 * Returns true if the tile has a path down
		 * @return true if the tile has a path down
		 */
		bool Tile::getPathDOWN(void) const {
			return this->pathDOWN;
		}

		/**
		 * Returns true if the tile has a path right
		 * @return true if the tile has a path right
		 */
		bool Tile::getPathRIGHT(void) const {
			return this->pathRIGHT;
		}

		/**
		 * Returns true if the tile has a path left
		 * @return true if the tile has a path left
		 */
		bool Tile::getPathLEFT(void) const {
			return this->pathLEFT;
		}

		/**
		 * Returns true if the tile can be moved
		 * @return true if the tile can be moved
		 */
		bool Tile::isMovable(void) const {
			return this->movable;
		}

		/**
		 * Returns the position of the tile on the board
		 * @return the position of the tile on the board
		 */
		Position Tile::getPosition(void) const {
			return this->position;
		}

		/**
		 * Returns the objective on the tile
		 * @return the objective on the tile
		 */
		std::string Tile::getObjective(void) const {
			return this->objective;
		}

		/**
		 * Returns true if the tile has an objective
		 * @return true if the tile has an objective
		 */
		bool Tile::hasObjective(void) const {
			return this->objective != "";
		}

		/**
		 * Returns the start number on the tile
		 * @return the start number on the tile
		 */
		unsigned int Tile::getStartNumber(void) const {
			return this->startNumber;
		}

		/**
		 * Returns true if tile has a start number
		 * @return
		 */
		bool Tile::hasStartNumber(void) const {
			return this->startNumber > 0;
		}

		/**
		 * Sets the position of the tile
		 * @param position the new position of the tile
		 */
		void Tile::setPosition(const Position &position) {
			this->position = position;
		}

		/**
		 * Rotates the tile 90° to the right (clockwise)
		 * Changes the path to match the rotated tile
		 */
		void Tile::rotateRight90(void) {
			bool up = this->pathUP;
			this->pathUP = this->pathLEFT;
			this->pathLEFT = this->pathDOWN;
			this->pathDOWN = this->pathRIGHT;
			this->pathRIGHT = up;
		}

		/**
		 * Rotates the tile 90° to the left (counter-clockwise)
		 * Changes the path to match the rotated tile
		 */
		void Tile::rotateLeft90(void) {
			bool up = this->pathUP;
			this->pathUP = this->pathRIGHT;
			this->pathRIGHT = this->pathDOWN;
			this->pathDOWN = this->pathLEFT;
			this->pathLEFT = up;
		}

		/**
		 * Moves the tile 1 cell in the provided way
		 * @param side the way to move the side to
		 */
		void Tile::move(const InsertSide &side) {
			this->position.move(1, side);
		}
	}  // namespace model
}  // namespace Labyrinth_44422
