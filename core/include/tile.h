#ifndef TILE_H
#define TILE_H

#include <stdbool.h>

#include "./tileTypes.h"
#include "./objectivesTypes.h"

namespace Labyrinth_44422 {
	namespace model {

		/**
		 * Represents a tile for the board game Labyrinth
		 * @author 44422
		 * @version 0.1.0
		 * @since 2019-03-01
		 */
		class Tile {
			private:
				TileTypes type;
				bool movable;
				ObjectivesTypes objective;
				unsigned int startNumber;

			public:
				Tile();
				TileTypes getType() const;
				bool isMovable() const;
				ObjectivesTypes getObjective() const;
				unsigned int getStartNumber() const;
		};

	}
}

#endif // TILE_H
