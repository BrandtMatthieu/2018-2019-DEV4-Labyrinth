#ifndef ASKPLAYERNAME_H
#define ASKPLAYERNAME_H

#include <QInputDialog>
#include <QWidget>

namespace Labyrinth_44422 {
	namespace gui {

		/**
		 * Represents a dialog window that asks for a player's nickname
		 * @author 44422
		 * @version 0.1.0
		 * @since 2019-04-27
		 */
		class AskPlayerName : public QInputDialog {

			Q_OBJECT

			public:
				explicit AskPlayerName(QWidget *parent = nullptr);

				~AskPlayerName(void) = default;

		};

	} // namespace gui
} // namespace Labyrinth_44422

#endif
