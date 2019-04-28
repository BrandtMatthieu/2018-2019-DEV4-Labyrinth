#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QMessageBox>
#include <QWidget>

namespace Labyrinth_44422 {
	namespace gui {

		class WelcomeWindow : public QMessageBox {

			Q_OBJECT

			public:

				explicit WelcomeWindow(QWidget * parent = nullptr);
				~WelcomeWindow(void) = default;
		};

	} // namespace gui
} // namespace Labyrinth_44422

#endif // WELCOMEWINDOW_H
