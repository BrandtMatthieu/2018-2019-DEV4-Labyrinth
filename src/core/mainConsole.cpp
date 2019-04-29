#include <iostream>

#include "./../console/include/consoleView.h"
#include "./controller/include/controllerConsole.h"


/**
 * Entry point for the console version of Labyrinth game
 * @return 0 exit code if program encounters no errors
 */
int main() {

	try {

		Labyrinth_44422::controller::ControllerConsole controller(new Labyrinth_44422::console::ConsoleView(true, true));
		controller.start();

	} catch (const std::exception &exception) {

		std::cout << std::endl << "Labyrinth has encountered an error and had to close.";
		std::cout << std::endl << exception.what();
		exit(-1);

	}

	exit(0);
}
