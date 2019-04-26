#include <QWidget>

#include "./../include/welcomeWindow.h"

namespace Labyrinth_44422 {
	namespace gui {

		WelcomeWindow::WelcomeWindow(QWidget * parent) : QMessageBox{parent} {
			this->setText("Bienvenue dans Labyrinth");
			this->activateWindow();
			this->show();
		}

	} // namespace gui
} // namespace Labyrinth_44422
