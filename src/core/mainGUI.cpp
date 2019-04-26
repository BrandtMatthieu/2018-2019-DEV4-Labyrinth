#include <iostream>

#include <QApplication>

#include "./../gui/include/guiView.h"
#include "./controller/include/controllerGUI.h"


/**
 * Entry point for the console version of Labyrinth game
 * @return 0 exit code if program encounters no errors
 */
int main(int argc, char *argv[]) {

    try {

        QApplication app(argc, argv);
        Labyrinth_44422::controller::ControllerGUI controllerGui;
        app.exec();

    } catch (const std::exception &exception) {

        std::cout << std::endl << "Labyrinth has encountered an error and had to close.";
        std::cout << std::endl << exception.what();
        exit(-1);

    }

    exit(0);
}
