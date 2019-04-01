#ifndef TILE_H
#define TILE_H

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
				std::string objective;
				unsigned int startNumber;

			public:
				Tile(	const bool & pathUP,
						const bool & pathDOWN,
						const bool & pathRIGHT,
						const bool & pathLEFT,
						const Position & position,
						const bool & movable,
						const std::string & objective,
						const unsigned int startNumber);
				Tile(const Tile & tile);
				~Tile(void) = default;

				bool getPathUP(void) const;
				bool getPathDOWN(void) const;
				bool getPathRIGHT(void) const;
				bool getPathLEFT(void) const;
				
				Position getPosition(void) const;
				
				bool isMovable(void) const;
				
				std::string getObjective(void) const;
				bool hasObjective(void) const;
				
				unsigned int getStartNumber(void) const;
				bool hasStartNumber(void) const;
			
				void setPosition(const Position & position);
				
				void rotateRight90(void);
				void rotateLeft90(void);
				
				void move(const InsertSide & side);
				
		};

	} // namespace model
} // namespace Labyrinth_44422

#endif // TILE_H
