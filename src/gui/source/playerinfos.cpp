#include <QLabel>
#include <QLayout>
#include <QPalette>
#include <QWidget>

#include "../include/playerInfos.h"

namespace Labyrinth_44422 {
	namespace gui {

		/**
		 * Creates a player infobox
		 * @param parent the parent window
		 * @param player the player to display the infos from
		 * @param isCurrentPlayer if the player is the current player
		 */
		PlayerInfos::PlayerInfos(QWidget *parent, model::Player *player, bool isCurrentPlayer) : QWidget{parent}, player{player} {

			this->layout = new QHBoxLayout(this);

			this->setLayout(this->layout);

			this->palette = new QPalette();
			this->currentPlayerColor = new QWidget{parent};
			this->playerLocation = new QLabel();
			this->playerCurrentObjective = new QLabel();
			this->playerObjectiveCompleted = new QLabel();

			this->currentPlayerColor->setMaximumWidth(20);
			this->currentPlayerColor->setMinimumWidth(20);
			this->currentPlayerColor->setMaximumHeight(100);
			this->currentPlayerColor->setMinimumHeight(100);

			this->layout->addWidget(currentPlayerColor);

			auto *infos = new QWidget();
			auto *infosLayout = new QFormLayout();
			infos->setLayout(infosLayout);

			this->layout->addWidget(infos);


			infosLayout->addRow(new QLabel("Player"), new QLabel(QString::fromStdString(this->player->getNickname())));
			infosLayout->addRow(new QLabel("Color"), new QLabel(QString::fromStdString(this->player->getColor())));
			infosLayout->addRow(new QLabel("Location"), this->playerLocation);
			infosLayout->addRow(new QLabel("Current Objective"), this->playerCurrentObjective);
			infosLayout->addRow(new QLabel("Objective Completed"), this->playerObjectiveCompleted);

			this->updateDisplay(isCurrentPlayer);
		}

		/**
		 * Updates the infos in the infobox
		 * @param isCurrentPlayer if the player is the current player
		 */
		void PlayerInfos::updateDisplay(bool isCurrentPlayer) {
			if (isCurrentPlayer) {
				if (this->player->getColor() == "Red") {
					this->palette->setColor(QPalette::Background, Qt::red);
				} else if (this->player->getColor() == "Blue") {
					this->palette->setColor(QPalette::Background, Qt::blue);
				} else if (this->player->getColor() == "Green") {
					this->palette->setColor(QPalette::Background, Qt::green);
				} else if (this->player->getColor() == "Yellow") {
					this->palette->setColor(QPalette::Background, Qt::yellow);
				} else {
					this->palette->setColor(QPalette::Background, Qt::black);
				}
			} else {
				this->palette->setColor(QPalette::Background, Qt::white);
			}

			this->currentPlayerColor->setPalette(*palette);

			this->playerLocation->setText(QString::fromStdString(this->player->getPosition().toString()));

			if (isCurrentPlayer) {
				this->playerCurrentObjective->setText(QString::fromStdString(this->player->getCurrentObjective()->getObjective()));
			} else {
				this->playerCurrentObjective->setText(QString::fromStdString("?"));
			}

			this->playerObjectiveCompleted->setText(QString::fromStdString(std::to_string(this->player->getCompletedObjectiveCardsCount()) + " / " + std::to_string(this->player->getObjectiveCardsLeftCount() + this->player->getCompletedObjectiveCardsCount())));

			this->update();
			this->show();
		}

		/**
		 * Returns the player it's displaying the infos from
		 */
		model::Player *PlayerInfos::getPlayer() {
			return this->player;
		}

	} // namespace gui
} // namespace Labyrinth_44422
