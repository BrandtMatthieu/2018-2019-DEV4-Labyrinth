#ifndef PLAYERINFOS_H
#define PLAYERINFOS_H

#include <QFormLayout>

#include "./../../core/model/include/player.h"

namespace Labyrinth_44422 {
	namespace gui {

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
