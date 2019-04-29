#include <QWidget>

#include "./../include/welcomeWindow.h"

namespace Labyrinth_44422 {
	namespace gui {

		/**
		 * Creates a welcome window
		 * @parent the parent window
		 */
		WelcomeWindow::WelcomeWindow(QWidget *parent) : QMessageBox{parent} {
			this->setWindowTitle("Labyrinth | Bienvenue");
			this->setMinimumSize(480, 360);
			this->setText("Bienvenue dans Labyrinth.\nVoulez-vous lire les règles avant de commencer ?");
			this->activateWindow();
			this->show();
		}

	} // namespace gui
} // namespace Labyrinth_44422
