#include <QWidget>
#include <QLabel>

#include "../include/playerInfos.h"

namespace Labyrinth_44422 {
	namespace gui {

		PlayerInfos::PlayerInfos(QWidget *parent, model::Player *player, bool isCurrentPlayer) :
			QFormLayout(parent),
			player{player} {
			this->addRow(new QLabel("Player"), new QLabel(QString::fromStdString(this->player->getNickname())));
			this->addRow(new QLabel("Color"), new QLabel(QString::fromStdString(this->player->getColor())));
			this->addRow(new QLabel("Location"),
						 new QLabel(QString::fromStdString(this->player->getPosition().toString())));
			if(isCurrentPlayer) {
				this->addRow(new QLabel("Current Objective"),
							new QLabel(QString::fromStdString(this->player->getCurrentObjective()->getObjective())));
			}
			this->addRow(new QLabel("Objective left"),
						 new QLabel(QString::fromStdString(std::to_string(this->player->getObjectiveCardsLeftCount()) +
						 "/" + std::to_string(this->player->getCompletedObjectiveCardsCount() + this->player->getObjectiveCardsLeftCount()))));
		}

	} // namespace gui
} // namespace Labyrinth_44422
