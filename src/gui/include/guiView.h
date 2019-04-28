#ifndef GUIVIEW_H
#define GUIVIEW_H

#include "string"

#include <QtWidgets/QMainWindow>
#include <QHBoxLayout>
#include <QMainWindow>

#include "./../../core/model/include/position.h"
#include "./../../core/model/include/game.h"

namespace Labyrinth_44422 {
	namespace gui {

		class GUIView : public QMainWindow {

			Q_OBJECT

			private:
				QWidget *centralWidget;
				QHBoxLayout *centralLayout;

				QGridLayout *gLayout;
				QVBoxLayout *vLayout;

				model::Game * game = nullptr;

				model::Position windowsSize = model::Position(800, 600);
				model::Position windowsmaxSize = model::Position(1600, 1200);
				model::Position windowsminSize = model::Position(400, 300);

				model::Position windowsLocation = model::Position(0, 0);

				std::string windowsTitle = "Labyrinth | n°15 | 44422 | D112 | DEVG4 | 2018-2019";

			public:
				explicit GUIView(model::Game * game = nullptr);
				~GUIView(void) = default;

				void updateDisplay(void);

				void displayWelcome(void);
				std::string askPlayerName(void);
		};

	} // namespace gui
} // namespace Labyrinth_44422

#endif
