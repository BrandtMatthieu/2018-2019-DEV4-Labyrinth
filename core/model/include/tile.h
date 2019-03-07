#ifndef TILE_H
#define TILE_H

#include <stdbool.h>

#include "./tileTypes.h"
#include "./objectivesTypes.h"
#include "./position.h"

namespace Labyrinth_44422 {
	namespace model {

		/**
		 * Represents a tile for the board game Labyrinth
		 * @author 44422
		 * @version 0.1.1
		 * @since 2019-03-01
		 */
		class Tile {
			private:
				bool pathUP;
				bool pathDOWN;
				bool pathRIGHT;
				bool pathLEFT;
				
				Position position;
				bool movable;
				ObjectivesTypes objective;
				unsigned int startNumber = NULL;

			public:
				Tile(bool & pathUP, bool & pathDOWN, bool & pathRIGHT, bool & pathLEFT, Position & position, bool & movable, ObjectivesTypes & objective, unsigned int startNumber);
				Tile(Tile & tile);
				
				bool getPathUP(void) const;
				bool getPathDOWN(void) const;
				bool getPathRIGHT(void) const;
				bool getPathLEFT(void) const;
				
				Position getPosition(void) const;
				bool isMovable(void) const;
				ObjectivesTypes getObjective(void) const;
				unsigned int getStartNumber(void) const;
		};

	}
}

#endif // TILE_H
