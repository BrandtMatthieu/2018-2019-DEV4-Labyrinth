#ifndef TILEPREVIEWER_H
#define TILEPREVIEWER_H

#include <QVBoxLayout>
#include <QWidget>

#include "./../../core/model/include/tile.h"

namespace Labyrinth_44422 {
	namespace gui {

		/**
		 * Represents an infobox with the available tile in the board
		 * @author 44422
		 * @version 0.1.0
		 * @since 2019-04-27
		 */
		class TilePreviewer : public QVBoxLayout {

			Q_OBJECT

			private:
				model::Tile *tile;

			public:
				explicit TilePreviewer(QWidget *parent, model::Tile *tile);

				~TilePreviewer() = default;

		};

	} // namespace gui
} // namespace Labyrinth_44422

#endif
