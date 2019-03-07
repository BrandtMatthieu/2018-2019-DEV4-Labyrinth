#include <iostream>

#include "core/controller/include/controller_console.h"
#include "../console/include/consoleView.h"

int main () {
	try {
		Labyrinth_44422::controller::Controller controller(Labyrinth_44422::console::ConsoleView());
	} catch(std::exception exception) {
		std::cout 	<< "Labyrinth a rencontré une erreur et doit fermer" << std::endl
					<< exception.what() << std::endl;
		return -1;
	}
	return 0;
}
