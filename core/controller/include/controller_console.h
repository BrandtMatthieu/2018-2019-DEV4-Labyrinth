#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../../../console/include/consoleView.h"
#include "../../model/include/game.h"

namespace Labyrinth_44422 {
	namespace controller {
		
		/**
		 * Controls the flow of the labyrinth game
		 * @author 44422
		 * @version 0.1.1
		 * @since 2019-03-04
		 */
		class ControllerConsole {
			private:
				Labyrinth_44422::console::ConsoleView * consoleView;
				Labyrinth_44422::model::Game * game;
			public:
				ControllerConsole(const Labyrinth_44422::console::ConsoleView * const consoleView);
				ControllerConsole(const ControllerConsole & controllerConsole);
				ControllerConsole & operator= (const ControllerConsole & controllerConsole);
				ControllerConsole(ControllerConsole && controllerConsole) noexcept;
				ControllerConsole & operator= (ControllerConsole && controllerConsole) noexcept;
				~ControllerConsole();

				void start();
		};
		
	}
}

#endif // CONTROLLER_H
