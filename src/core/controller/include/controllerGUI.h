#ifndef CONTROLLERGUI_H
#define CONTROLLERGUI_H

#include "../../model/include/game.h"
#include "./../../../gui/include/guiView.h"

namespace Labyrinth_44422 {
	namespace controller {

		class ControllerGUI {
		private:
			Labyrinth_44422::model::Game * game;
			Labyrinth_44422::gui::GUIView * guiView;

		public:
			ControllerGUI(void);

			ControllerGUI(const ControllerGUI & controllerGui) = default;

			~ControllerGUI(void);

			void start(void);
		};

	} // namespace controller
} // namespace Labyrinth_44422


#endif //CONTROLLERGUI_H
