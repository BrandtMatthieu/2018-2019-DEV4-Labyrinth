#ifndef PLAYERINFOS_H
#define PLAYERINFOS_H

#include <QFormLayout>

#include "./../../core/model/include/player.h"

namespace Labyrinth_44422 {
	namespace gui {

		/**
		 * Represents a player infobox containing all the infos about a player
		 * @author 44422
		 * @version 0.1.0
		 * @since 2019-04-27
		 */
		class PlayerInfos : public QHBoxLayout {

			Q_OBJECT

			private:
				model::Player *player = nullptr;

			public:
				PlayerInfos(QWidget *parent, model::Player *player, bool isCurrentPlayer);

				~PlayerInfos() = default;
		};

	} // namespace gui
} // namespace Labyrinth_44422

#endif // PLAYERINFOS_H
