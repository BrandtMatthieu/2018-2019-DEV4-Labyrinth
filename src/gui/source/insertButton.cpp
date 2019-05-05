#include "./../include/insertButton.h"

#include "./../../core/model/include/insertSide.h"

namespace Labyrinth_44422 {
	namespace gui {

		/**
		 * Creates a new button used to insert a tile
		 * @param parent the parent element
		 * @param side the side this button inserts a tile in
		 * @param line the line this button inserts a tile at
		 */
		InsertButton::InsertButton(QWidget *parent, model::InsertSide side, unsigned int line) : QPushButton{parent}, side{side}, line{line} {

			this->setMinimumSize(0, 0);

			switch (side) {
				case model::InsertSide::DOWN:
					this->setText("v");
					break;
				case model::InsertSide::LEFT:
					this->setText("<");
					break;
				case model::InsertSide::RIGHT:
					this->setText(">");
					break;
				case model::InsertSide::UP:
					this->setText("^");
					break;
			}
		}

		/**
		 * Updates the look of the button
		 * @param clickable if the button is clickable or not
		 */
		void InsertButton::updateDisplay(bool clickable) {
			this->setEnabled(clickable);

			this->update();
			this->show();
		}

		/**
		 * Returns the side of the button
		 * @return the side of the button
		 */
		model::InsertSide InsertButton::getSide() {
			return this->side;
		}

		/**
		 * Returns the line of the button
		 * @return the line of the button
		 */
		unsigned int InsertButton::getLine() {
			return this->line;
		}

	} // namespace gui
} // namespace Labyrinth_44422
