#include <QWidget>
#include <QLabel>
#include <QPalette>
#include <QLayout>

#include "../include/playerInfos.h"

namespace Labyrinth_44422 {
	namespace gui {

		PlayerInfos::PlayerInfos(QWidget *parent, model::Player *player, bool isCurrentPlayer) :
			QHBoxLayout(parent),
			player{player} {

			//this->setSizeConstraint(SizeConstraint::SetMaximumSize);

			auto * currentPlayerColor = new QWidget(parent);
			currentPlayerColor->setMaximumWidth(20);
			//currentPlayerColor->setGeometry(0, 0, 10, 100);

			if(isCurrentPlayer) {
				auto * palette = new QPalette();
				palette->setColor(QPalette::Background, Qt::blue);
				currentPlayerColor->setAutoFillBackground(true);
				currentPlayerColor->setPalette(*palette);
			}
			this->addWidget(currentPlayerColor);

			auto * infos = new QWidget();
			auto * infosLayout = new QFormLayout();
			infos->setLayout(infosLayout);
			this->addWidget(infos);

			infosLayout->addRow(new QLabel("Player"),
								new QLabel(QString::fromStdString(this->player->getNickname())));
			infosLayout->addRow(new QLabel("Color"),
								new QLabel(QString::fromStdString(this->player->getColor())));
			infosLayout->addRow(new QLabel("Location"),
								new QLabel(QString::fromStdString(this->player->getPosition().toString())));
			if(isCurrentPlayer) {
				infosLayout->addRow(new QLabel("Current Objective"),
									new QLabel(QString::fromStdString(this->player->getCurrentObjective()->getObjective())));
			} else {
				infosLayout->addRow(new QLabel("Current Objective"),
									new QLabel(QString::fromStdString("?")));
			}
			infosLayout->addRow(new QLabel("Objective Completed"),
								new QLabel(QString::fromStdString(std::to_string(this->player->getObjectiveCardsLeftCount()) +
								" / " + std::to_string(this->player->getObjectiveCardsLeftCount() +
														this->player->getCompletedObjectiveCardsCount()))));
		}

	} // namespace gui
} // namespace Labyrinth_44422
