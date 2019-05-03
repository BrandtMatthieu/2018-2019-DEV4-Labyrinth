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

namespace Labyrinth_44422 {
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

				std::vector<PlayerInfos *> playersInfos;

				BoardView *boardView = nullptr;

				QVBoxLayout *vLayout = nullptr;

			public:
				explicit GUIView(model::Game *game = nullptr);

				~GUIView(void) = default;

				void init(void);

				void updateDisplay(void);

				void displayRules(void);

				std::string askPlayerName(void);
		};

	} // namespace gui
} // namespace Labyrinth_44422

#endif
