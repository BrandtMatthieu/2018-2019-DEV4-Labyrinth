#ifndef CLICKABLETILE_H
#define CLICKABLETILE_H

#include <QPushButton>
#include <QToolButton>

#include "./../../core/model/include/tile.h"

namespace Labyrinth_44422 {
	namespace controller {
		class ControllerGUI;
	}

	namespace gui {

		class ClickableTile : public QToolButton {

			Q_OBJECT

			private:
				model::Tile *tile = nullptr;

				controller::ControllerGUI *controller = nullptr;

				unsigned int x = 0;

				unsigned int y = 0;

				unsigned int width = 100;

				unsigned int height = 100;

				QImage *result = nullptr;

			public:
				explicit ClickableTile(QWidget *parent, model::Tile *tile, unsigned int x, unsigned int y, unsigned int width, unsigned int height, bool clickable, controller::ControllerGUI *controller);
				~ClickableTile() = default;

				void updateDisplay(model::Tile *tile, bool clickable);

		};

	} // namespace gui
} // namespace Labyrinth_44422

#endif // CLICKABLETILE_H
