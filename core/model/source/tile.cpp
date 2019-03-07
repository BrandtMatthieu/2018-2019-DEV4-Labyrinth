
#include <core/model/include/tile.h>

#include "../include/tile.h"

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
		 * @param startNumber
		 */
		Tile::Tile(bool & pathUP, bool & pathDOWN, bool & pathRIGHT, bool & pathLEFT, Position & position, bool & movable,
				   ObjectivesTypes & objective, unsigned int startNumber = NULL): position{position.getX(), position.getY()} {
			this->pathUP = pathUP;
			this->pathDOWN = pathDOWN;
			this->pathRIGHT = pathRIGHT;
			this->pathLEFT = pathLEFT;
			this->position = position;
			this->movable = movable;
			this->objective = objective;
			this->startNumber = startNumber;
		}
		
		/**
		 * Creates a new tile from another tile
		 * aka. copy constructor
		 * @param tile the tile to create the new tile from
		 */
		Tile::Tile(Tile & tile): position{position} {
			this->pathUP = tile.getPathUP();
			this->pathDOWN = tile.getPathDOWN();
			this->pathRIGHT = tile.getPathRIGHT();
			this->pathLEFT = tile.getPathLEFT();
			this->position = tile.getPosition();
			this->movable = tile.isMovable();
			this->objective = tile.getObjective();
			this->startNumber = tile.getStartNumber();
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
			return false;
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
		ObjectivesTypes Tile::getObjective(void) const {
			return this->objective;
		}
		
		/**
		 * Returns the start number on the tile
		 * @return the start number on the tile
		 */
		unsigned int Tile::getStartNumber(void) const {
			return 0;
		}
	}
}
