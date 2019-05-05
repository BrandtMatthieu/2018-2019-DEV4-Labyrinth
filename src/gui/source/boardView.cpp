#include <iostream>
#include <sstream>
#include <string>

#include <QWidget>

#include "./../include/boardView.h"
#include "./../include/clickableTile.h"
#include "./../../core/controller/include/controllerGUI.h"

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
		 * @param controller the controller of the game
		 */
		BoardView::BoardView(QWidget *parent, model::Game *game, controller::ControllerGUI *controller) : QWidget{parent}, game{game}, controller{controller} {

			const unsigned int sizeButton = 100;

			auto *grid = new QGridLayout(this);
			this->setLayout(grid);
			auto policy = this->sizePolicy();
			policy.setWidthForHeight(true);
			this->setSizePolicy(policy);

			for (unsigned int i = 0; i < this->game->getBoard()->getTilesCount(); i++) {
				auto *clickableTile = new ClickableTile(parent, this->game->getBoard()->getTilesAt(i), i % this->game->getBoard()->getMaxSizeX(), i / this->game->getBoard()->getMaxSizeX(), sizeButton, sizeButton, false, controller);
				this->tiles.push_back(clickableTile);
				grid->addWidget(clickableTile, (i / this->game->getBoard()->getMaxSizeX()) + 1, (i % this->game->getBoard()->getMaxSizeX()) + 1);
			}

			// vertical buttons
			for (unsigned int i = 0; i < this->game->getBoard()->getMaxSizeY(); i++) {
				if (this->game->getBoard()->canInsertTile(i, model::InsertSide::RIGHT)) {
					auto *insertButtonRight = new InsertButton(parent, model::InsertSide::RIGHT, i);
					auto *insertButtonLeft = new InsertButton(parent, model::InsertSide::LEFT, i);

					insertButtonRight->setMaximumHeight(sizeButton);
					auto policyRight = insertButtonRight->sizePolicy();
					policyRight.setWidthForHeight(true);
					insertButtonRight->setSizePolicy(policyRight);
					insertButtonRight->resize(sizeButton, sizeButton);
					QObject::connect(insertButtonRight, &QPushButton::clicked, this, [insertButtonRight, this]() {
						this->controller->currentPlayerTryInsertTile(insertButtonRight->getSide(), insertButtonRight->getLine());
					});

					insertButtonLeft->setMaximumHeight(sizeButton);
					auto policyLeft = insertButtonLeft->sizePolicy();
					policyLeft.setWidthForHeight(true);
					insertButtonLeft->setSizePolicy(policyLeft);
					insertButtonLeft->resize(sizeButton, sizeButton);
					QObject::connect(insertButtonLeft, &QPushButton::clicked, this, [insertButtonLeft, this]() {
						this->controller->currentPlayerTryInsertTile(insertButtonLeft->getSide(), insertButtonLeft->getLine());
					});

					this->buttons.push_back(insertButtonRight);
					this->buttons.push_back(insertButtonLeft);

					grid->addWidget(insertButtonRight, i + 1, 0);
					grid->addWidget(insertButtonLeft, i + 1, this->game->getBoard()->getMaxSizeX() + 1);
				}
			}

			// horizontal buttons
			for (unsigned int i = 0; i < this->game->getBoard()->getMaxSizeX(); i++) {
				if (this->game->getBoard()->canInsertTile(i, model::InsertSide::DOWN)) {
					auto *insertButtonUp = new InsertButton(parent, model::InsertSide::UP, i);
					auto *insertButtonDown = new InsertButton(parent, model::InsertSide::DOWN, i);

					insertButtonUp->setMaximumWidth(sizeButton);
					auto policyUp = insertButtonUp->sizePolicy();
					policyUp.setHeightForWidth(true);
					insertButtonUp->setSizePolicy(policyUp);
					insertButtonUp->resize(sizeButton, sizeButton);
					QObject::connect(insertButtonUp, &QPushButton::clicked, this, [insertButtonUp, this]() {
						this->controller->currentPlayerTryInsertTile(insertButtonUp->getSide(), insertButtonUp->getLine());
					});

					insertButtonDown->setMaximumWidth(sizeButton);
					auto policyDown = insertButtonDown->sizePolicy();
					policyDown.setHeightForWidth(true);
					insertButtonDown->setSizePolicy(policyDown);
					insertButtonDown->resize(sizeButton, sizeButton);
					QObject::connect(insertButtonDown, &QPushButton::clicked, this, [insertButtonDown, this]() {
						this->controller->currentPlayerTryInsertTile(insertButtonDown->getSide(), insertButtonDown->getLine());
					});

					this->buttons.push_back(insertButtonUp);
					this->buttons.push_back(insertButtonDown);

					grid->addWidget(insertButtonUp, this->game->getBoard()->getMaxSizeY() + 1, i + 1);
					grid->addWidget(insertButtonDown, 0, i + 1);
				}
			}

			this->updateDisplay();
		}

		/**
		 * Updates the player infos
		 */
		void BoardView::updateDisplay() {

			for (unsigned int i = 0; i < this->game->getBoard()->getTilesCount(); i++) {
				this->tiles.at(i)->updateDisplay(this->game->getBoard()->getTilesAt(i), this->game->canCurrentPlayerGoTo());
			}
			for (auto *button : this->buttons) {
				button->updateDisplay(this->game->canCurrentPlayerInsertTile());
			}

			this->update();
			this->show();
		}

	}  // namespace gui
}  // namespace Labyrinth_44422
