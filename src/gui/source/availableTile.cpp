#include <sstream>
#include <string>

#include <QCoreApplication>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include "./../include/availableTile.h"
#include "./../include/clickableTile.h"
#include "./../../core/model/include/tile.h"

namespace Labyrinth_44422 {
	namespace gui {

		/**
		 * Creates an infobox to display the available tile in the board
		 * @param parent the parent window
		 * @param tile the tile to display
		 */
		AvailableTile::AvailableTile(QWidget *parent, model::Game *game, controller::ControllerGUI *controller) : QVBoxLayout{parent}, game{game}, controller{controller} {

			this->tile = new ClickableTile(parent, this->game->getAvailableTiles().at(0), 100, 100, false, controller);

			auto *horizontal = new QHBoxLayout(parent);

			auto *leftButton = new QPushButton("Tourner la tuile de -90°", parent);
			auto *rightButton = new QPushButton("Tourner la tuile de 90°", parent);

			QObject::connect(leftButton, &QPushButton::clicked, this, [leftButton, this]() {
				this->controller->currentPlayerTurnTileLeft();
			});
			QObject::connect(rightButton, &QPushButton::clicked, this, [rightButton, this]() {
				this->controller->currentPlayerTurnTileRight();
			});

			horizontal->addWidget(leftButton);
			horizontal->addWidget(rightButton);

			this->addWidget(tile);
			this->addLayout(horizontal);

			this->updateDisplay();

		}

		void AvailableTile::updateDisplay() {

			this->tile->updateDisplay(this->game->getAvailableTiles().at(0), false);

			this->update();
		}

	} // namespace gui
} // namespace Labyrinth_44422
