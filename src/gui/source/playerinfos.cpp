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
		PlayerInfos::PlayerInfos(QWidget *parent, model::Player *player, bool isCurrentPlayer) : QHBoxLayout(parent), player{player} {

			auto *currentPlayerColor = new QWidget(parent);
			currentPlayerColor->setMaximumWidth(20);

			if (isCurrentPlayer) {
				auto *palette = new QPalette();
				if (player->getColor() == "Red") {
					palette->setColor(QPalette::Background, Qt::red);
				} else if (player->getColor() == "Blue") {
					palette->setColor(QPalette::Background, Qt::blue);
				} else if (player->getColor() == "Green") {
					palette->setColor(QPalette::Background, Qt::green);
				} else if (player->getColor() == "Yellow") {
					palette->setColor(QPalette::Background, Qt::yellow);
				} else {
					palette->setColor(QPalette::Background, Qt::black);
				}

				currentPlayerColor->setAutoFillBackground(true);
				currentPlayerColor->setPalette(*palette);
			}
			this->addWidget(currentPlayerColor);

			auto *infos = new QWidget();
			auto *infosLayout = new QFormLayout();
			infos->setLayout(infosLayout);
			this->addWidget(infos);

			infosLayout->addRow(new QLabel("Player"), new QLabel(QString::fromStdString(this->player->getNickname())));
			infosLayout->addRow(new QLabel("Color"), new QLabel(QString::fromStdString(this->player->getColor())));
			infosLayout->addRow(new QLabel("Location"), new QLabel(QString::fromStdString(this->player->getPosition().toString())));
			if (isCurrentPlayer) {
				infosLayout->addRow(new QLabel("Current Objective"), new QLabel(QString::fromStdString(this->player->getCurrentObjective()->getObjective())));
			} else {
				infosLayout->addRow(new QLabel("Current Objective"), new QLabel(QString::fromStdString("?")));
			}
			infosLayout->addRow(new QLabel("Objective Completed"), new QLabel(QString::fromStdString(std::to_string(this->player->getCompletedObjectiveCardsCount()) + " / " + std::to_string(this->player->getObjectiveCardsLeftCount() + this->player->getCompletedObjectiveCardsCount()))));
		}

	} // namespace gui
} // namespace Labyrinth_44422
