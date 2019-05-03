#ifndef INSERTBUTTON_H
#define INSERTBUTTON_H

#include "./../../core/model/include/insertSide.h"

#include <QPushButton>

namespace Labyrinth_44422 {
	namespace gui {

		class InsertButton : public QPushButton {

			Q_OBJECT

			private:
				model::InsertSide side;

				unsigned int line;

			public:
				explicit InsertButton(QWidget *parent, model::InsertSide side, unsigned int line);
				~InsertButton() = default;

				void updateDisplay(bool clickable);

		};

	} // namespace gui
} // namespace Labyrinth_44422

#endif // INSERTBUTTON_H
