
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
		Tile::Tile(bool pathUP, bool pathDOWN, bool pathRIGHT, bool pathLEFT, Position position, bool movable,
				   ObjectivesTypes objective, unsigned int startNumber) {
			
		}
		
		Tile::Tile(Tile &tile) {
		
		}
		
		TileTypes Tile::getType(void) const {
			return L;
		}
		
		bool Tile::isMovable(void) const {
			return false;
		}
		
		ObjectivesTypes Tile::getObjective(void) const {
			return CROWN;
		}
		
		unsigned int Tile::getStartNumber(void) const {
			return 0;
		}

	}
}
