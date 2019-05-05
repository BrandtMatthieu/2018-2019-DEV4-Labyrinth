#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include <vector>

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>

#include "./clickableTile.h"
#include "./insertButton.h"
#include "./../../core/model/include/game.h"

namespace Labyrinth_44422 {
	namespace controller {
		class ControllerGUI;
	}

	namespace gui {

		/**
		 * Represents the board of the Labyrinth
		 * @author 44422
		 * @version 0.1.1
		 * @since 2019-05-01
		 */
		class BoardView : public QWidget {

			Q_OBJECT

			private:
				model::Game *game = nullptr;

				controller::ControllerGUI *controller = nullptr;

				std::vector<ClickableTile *> tiles;

				std::vector<InsertButton *> buttons;

			public:
				explicit BoardView(QWidget *parent, model::Game *game, controller::ControllerGUI *controller);

				~BoardView(void) = default;

				void updateDisplay(void);
		};

	} // namespace gui
} // namespace Labyrinth_44422

#endif // BOARDVIEW_H
