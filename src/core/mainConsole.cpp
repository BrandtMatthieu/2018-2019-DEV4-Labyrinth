#include <iostream>
#include <exception>

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
        
	} catch(const std::exception & exception) {
		
		std::cout << "Labyrinth has encountered an error and had to close." << std::endl << exception.what() << std::endl;
		return -1;
		
	}

	return 0;
}
