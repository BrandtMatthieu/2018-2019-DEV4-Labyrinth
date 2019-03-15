#include <iostream>
#include <exception>

#include "controller/include/controller_console.h"
#include "../console/include/consoleView.h"

/**
 * Entry point for the console version of Labyrinth game
 * @return 0 exit code if program encounters no errors
*/
int main() {

    try {
		Labyrinth_44422::controller::ControllerConsole controller(new Labyrinth_44422::console::ConsoleView(true));
		controller.start();
	} catch(std::exception & exception) {
		std::cout << "Labyrinth a rencontre une erreur et doit fermer." << std::endl << exception.what() << std::endl;
		return -1;
	}

	return 0;
}
