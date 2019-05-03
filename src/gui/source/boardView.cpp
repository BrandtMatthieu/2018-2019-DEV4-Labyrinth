#include <iostream>
#include <sstream>
#include <string>

#include <QWidget>

#include "./../include/boardView.h"
#include "./../include/clickableTile.h"

namespace Labyrinth_44422 {
	namespace gui {

		void deleteWidgets(QLayout *layout) {
			while (QLayoutItem *item = layout->takeAt(0)) {
				if (QWidget *widget = item->widget()) {
					widget->deleteLater();
				}
				if (QLayout *childLayout = item->layout()) {
					deleteWidgets(childLayout);
				}

				delete item;
			}
		}

		/**
		 * Creates a new board display
		 * @param parent the parent window
		 * @param game the game to display
		 */
		BoardView::BoardView(QWidget *parent, model::Game *game) : QGridLayout{parent}, game{game} {
			for (unsigned int i = 0; i < this->game->getBoard()->getTilesCount(); i++) {
				auto * clickableTile = new ClickableTile(parent, this->game->getBoard()->getTilesAt(i), 20, 20, true);
				this->tiles.push_back(clickableTile);
				this->addWidget(clickableTile, (i / this->game->getBoard()->getMaxSizeX()) + 1, (i % this->game->getBoard()->getMaxSizeX()) + 1);
				this->tiles.at(i)->updateDisplay(this->game->getBoard()->getTilesAt(i), true);
			}

			this->updateDisplay();
			// générer toutes les tuiles et les boutons
		}

		/**
		 * Updates the player infos
		 */
		void BoardView::updateDisplay() {

			for (unsigned int i = 0; i < this->game->getBoard()->getTilesCount(); i++) {
				this->tiles.at(i)->updateDisplay(this->game->getBoard()->getTilesAt(i), true);
			}
			for (auto *button : this->buttons) {
				button->updateDisplay(this->game->canCurrentPlayerInsertTile());
			}
/* 			auto * qtile = new QWidget();
			qtile->setMinimumSize(50, 50);

			std::stringstream path;
			path << "background: url(./../resource/" << (tile->getPathLEFT() ? "t" : "f") << (tile->getPathDOWN() ? "t" : "f") << (tile->getPathRIGHT() ? "t" : "f") << (tile->getPathUP() ? "t" : "f") << ".png) 0 0 0 0 stretch stretch;"
																																																			"background-repeat: none; width: 50px; height: 50px;";
			qtile->setStyleSheet(QString::fromStdString(path.str()));

			std::cout << tile->getPosition().toString() << std::endl;
			this->addWidget(qtile, tile->getPosition().getX() + 1, tile->getPosition().getY() + 1); */

			this->update();
		}

	}  // namespace gui
}  // namespace Labyrinth_44422
