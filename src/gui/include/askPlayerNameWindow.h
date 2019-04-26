#ifndef ASKPLAYERNAME_H
#define ASKPLAYERNAME_H

#include <QInputDialog>
#include <QWidget>

namespace Labyrinth_44422 {
	namespace gui {

		class AskPlayerName : public QInputDialog {

			Q_OBJECT

			public:
				AskPlayerName(QWidget * parent = nullptr);
				~AskPlayerName(void) = default;

		};

	} // namespace gui
} // namespace Labyrinth_44422

#endif
