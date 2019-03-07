#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../../../console/include/consoleView.h"

namespace Labyrinth_44422 {
	namespace controller {
		
		/**
		 * Controls the flow of the labyrinth game
		 * @author 44422
		 * @version 0.1.1
		 * @since 2019-03-04
		 */
		class Controller {
		private:
			Labyrinth_44422::console::ConsoleView * consoleView;
			void start(void);
		public:
			Controller(Labyrinth_44422::console::ConsoleView * consoleView);
		};
		
	}
}

#endif // CONTROLLER_H
