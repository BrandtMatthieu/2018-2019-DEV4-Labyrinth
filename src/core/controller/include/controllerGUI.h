#ifndef CONTROLLERGUI_H
#define CONTROLLERGUI_H

#include "../../model/include/game.h"
#include "./../../../gui/include/guiView.h"

namespace Labyrinth_44422 {
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

				Labyrinth_44422::gui::GUIView *guiView;

			public:
				ControllerGUI(void);

				ControllerGUI(const ControllerGUI &controllerGui) = default;

				~ControllerGUI(void);

				void start(void);
		};

	} // namespace controller
} // namespace Labyrinth_44422


#endif //CONTROLLERGUI_H
