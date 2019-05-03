#ifndef CLICKABLETILE_H
#define CLICKABLETILE_H

#include <QPushButton>

#include "./../../core/model/include/tile.h"

namespace Labyrinth_44422 {
	namespace gui {

		class ClickableTile : public QPushButton {

			Q_OBJECT

			private:
				model::Tile *tile = nullptr;

			public:
				explicit ClickableTile(QWidget *parent, model::Tile *tile, unsigned int width, unsigned int height, bool clickable);
				~ClickableTile() = default;

				void updateDisplay(model::Tile *tile, bool clickable);

		};

	} // namespace gui
} // namespace Labyrinth_44422

#endif // CLICKABLETILE_H
