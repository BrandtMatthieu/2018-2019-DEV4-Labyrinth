#ifndef INSERTSIDE_H
#define INSERTSIDE_H

namespace Labyrinth_44422 {
	namespace model {
		
		/**
		 * Represents the different sides it's possible to insert a tile from
		 */
		enum class InsertSide {
			UP,
			DOWN,
			RIGHT,
			LEFT,
		};
		
		/**
		 * The names of the different directions in the enum
		 */
		const std::string insertSide_names[] = {
			"up",
			"down",
			"right",
			"left"
		};
		
	}
}

#endif // INSERTSIDE_H
