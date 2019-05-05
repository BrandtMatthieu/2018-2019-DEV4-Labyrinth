#include <sstream>
#include <string>

#include <QCoreApplication>
#include <QLabel>
#include <QLayout>
#include <QPixmap>
#include <QPushButton>
#include <QSizePolicy>
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
		 * @param game the current game
		 * @param controller the controller of the game
		 */
		AvailableTile::AvailableTile(QWidget *parent, model::Game *game, controller::ControllerGUI *controller) : QVBoxLayout{parent}, game{game}, controller{controller} {

			this->tile = new ClickableTile(parent, this->game->getAvailableTiles().at(0), 0, 0, 200, 200, false, controller);
			this->tile->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

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

		/**
		 * Updates the available tile
		 */
		void AvailableTile::updateDisplay() {

			this->tile->updateDisplay(this->game->getAvailableTiles().at(0), false);

			this->update();
		}

	} // namespace gui
} // namespace Labyrinth_44422
