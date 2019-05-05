#ifndef PLAYERINFOS_H
#define PLAYERINFOS_H

#include <QFormLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPalette>

#include "./../../core/model/include/player.h"

namespace Labyrinth_44422 {
	namespace gui {

		/**
		 * Represents a player infobox containing all the infos about a player
		 * @author 44422
		 * @version 0.1.0
		 * @since 2019-04-27
		 */
		class PlayerInfos : public QWidget {

			Q_OBJECT

			private:

				QHBoxLayout *layout = nullptr;

				model::Player *player = nullptr;

				QPalette *palette = nullptr;

				QWidget *currentPlayerColor = nullptr;

				QLabel *playerLocation = nullptr;

				QLabel *playerCurrentObjective = nullptr;

				QLabel *playerObjectiveCompleted = nullptr;

			public:
				explicit PlayerInfos(QWidget *parent, model::Player *player, bool isCurrentPlayer);

				~PlayerInfos() = default;

				void updateDisplay(bool isCurrentPlayer);

				model::Player *getPlayer();
		};

	} // namespace gui
} // namespace Labyrinth_44422

#endif // PLAYERINFOS_H
