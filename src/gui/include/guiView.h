#ifndef GUIVIEW_H
#define GUIVIEW_H

#include <vector>

#include <QHBoxLayout>
#include <QMainWindow>
#include <QVBoxLayout>

#include "./../include/boardView.h"
#include "./../include/playerInfos.h"
#include "./../../core/model/include/position.h"
#include "./../../core/model/include/game.h"
#include "./../include/availableTile.h"


namespace Labyrinth_44422 {
	namespace controller {
		class ControllerGUI;
	}

	namespace gui {

		/**
		 * Main window of the Labyrinth game
		 * @author 44422
		 * @version 0.1.0
		 * @since 2019-04-25
		 */
		class GUIView : public QMainWindow {

			Q_OBJECT

			private:
				model::Game *game = nullptr;

				Labyrinth_44422::controller::ControllerGUI *controller = nullptr;

				std::vector<PlayerInfos *> playersInfos;

				BoardView *boardView = nullptr;

				QVBoxLayout *vLayout = nullptr;

				AvailableTile *availableTile = nullptr;

			public:
				explicit GUIView(model::Game *game, controller::ControllerGUI *controller);

				~GUIView(void) = default;

				void init(void);

				void updateDisplay(void);

				void displayRules(void);

				void displayWinner(void);
		};

	} // namespace gui
} // namespace Labyrinth_44422

#endif
