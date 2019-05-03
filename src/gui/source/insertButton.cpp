#include "./../include/insertButton.h"

#include "./../../core/model/include/insertSide.h"

namespace Labyrinth_44422 {
	namespace gui {

		InsertButton::InsertButton(QWidget *parent, model::InsertSide side, unsigned int line) : QPushButton{parent}, side{side}, line{line} {
			switch (side) {
				case model::InsertSide::DOWN:
					this->setText("v\n|");
					break;
				case model::InsertSide::LEFT:
					this->setText("->");
					break;
				case model::InsertSide::RIGHT:
					this->setText("<-");
					break;
				case model::InsertSide::UP:
					this->setText("^\n|");
					break;
			}
		}

		void InsertButton::updateDisplay(bool clickable) {
			this->setEnabled(clickable);

			this->update();
			this->show();
		}

	} // namespace gui
} // namespace Labyrinth_44422
