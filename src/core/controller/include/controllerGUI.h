#ifndef CONTROLLERGUI_H
#define CONTROLLERGUI_H

#include <string>

#include "./../../model/include/game.h"
#include "./../../model/include/insertSide.h"

namespace Labyrinth_44422 {
	namespace gui {
		class GUIView;
	}

	namespace controller {

		/**
		 * Controls the flow of the labyrinth game
		 * @author 44422
		 * @version 0.1.1
		 * @since 2019-04-27
		 */
		class ControllerGUI {

			private:
				Labyrinth_44422::model::Game *game;

				gui::GUIView *guiView;

			public:
				ControllerGUI(void);

				ControllerGUI(const ControllerGUI &controllerGui) = default;

				~ControllerGUI(void);

				void addPlayer(std::string nickname);

				void currentPlayerTurnTileLeft();
				void currentPlayerTurnTileRight();

				void currentPlayerTryInsertTile(Labyrinth_44422::model::InsertSide side, unsigned int line);
				void currentPlayerTryGoTo(unsigned int x, unsigned int y);

		};

	} // namespace controller
} // namespace Labyrinth_44422


#endif //CONTROLLERGUI_H
