#ifndef CONSOLEVIEW_H
#define CONSOLEVIEW_H

#include <string>

#include "../../core/model/include/board.h"
#include "../../core/model/include/game.h"
#include "../../core/model/include/player.h"
#include "../../core/model/include/tile.h"

namespace Labyrinth_44422 {
	namespace console {
		
		/**
		 * Represents a console view of the Labyrinth game
		 * @author 44422
		 * @version 0.1.3
		 * @since 2019-03-05
		 */
		class ConsoleView {
			private:
				static constexpr unsigned int pathSize = 3;
				static constexpr unsigned int tileSize = 3 * pathSize + 2;
			
				const std::string wall;
				const std::string path;
				const std::string space;
				bool spacing = true;
				
				std::string printTile(const Labyrinth_44422::model::Tile * const tile, const unsigned int & k) const;
				bool getYesNoAnswer(const std::string & message) const;
			
			public:
				explicit ConsoleView(bool spacing);
				ConsoleView(const ConsoleView & vue);
				~ConsoleView() = default;
				
				bool addNewPlayer(void) const;
				std::string newPlayerName(void) const;
				
				void printGameInfos(const model::Game * const game) const;
				void printBoard(const model::Board * const board) const;
				void printPlayerInfos(const model::Player * const player) const;
				void printMessage(const std::string & message) const;
				void printError(const std::string & error) const;
				void printHelp(const model::Board * const board) const;
		};
	} // namespace console
} // namespace Labyrinth_44422

#endif // CONSOLEVIEW_H
