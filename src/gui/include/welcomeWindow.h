#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QMessageBox>
#include <QWidget>

namespace Labyrinth_44422 {
	namespace gui {

		/**
		 * Represents a dialog window that welcomes the user
		 * @author 44422
		 * @version 0.1.0
		 * @since 2019-04-27
		 */
		class WelcomeWindow : public QMessageBox {

			Q_OBJECT

			public:

				explicit WelcomeWindow(QWidget *parent = nullptr);

				~WelcomeWindow(void) = default;
		};

	} // namespace gui
} // namespace Labyrinth_44422

#endif // WELCOMEWINDOW_H
