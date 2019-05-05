#ifndef TILEPREVIEWER_H
#define TILEPREVIEWER_H

#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

#include "./clickableTile.h"
#include "./../../core/controller/include/controllerGUI.h"
#include "./../../core/model/include/game.h"

namespace Labyrinth_44422 {
	namespace gui {

		/**
		 * Represents an infobox with the available tile in the board
		 * @author 44422
		 * @version 0.1.1
		 * @since 2019-04-27
		 */
		class AvailableTile : public QVBoxLayout {

			Q_OBJECT

			private:
				model::Game *game = nullptr;

				controller::ControllerGUI *controller = nullptr;

				ClickableTile *tile = nullptr;

			public:
				explicit AvailableTile(QWidget *parent, model::Game *game, controller::ControllerGUI *controller);

				~AvailableTile() = default;

				void updateDisplay(void);
		};

	} // namespace gui
} // namespace Labyrinth_44422

#endif
