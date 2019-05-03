#include <iostream>

#include <QApplication>
#include <QDebug>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include "./../include/boardView.h"
#include "./../include/guiView.h"
#include "./../include/playerInfos.h"
#include "./../include/rulesWindow.h"
#include "./../include/availableTile.h"

namespace Labyrinth_44422 {
	namespace gui {

		/**
		 * Creates the main window of the Labyrinth game
		 * @param game the game to display
		 */
		GUIView::GUIView(model::Game *game) : QMainWindow{nullptr}, game{game} {

			this->setWindowTitle(QString::fromStdString("Labyrinth | n°15 - 44422 - D112 - DEVG4 - 2018-2019"));
			this->setMinimumSize(1200, 800);

			auto *centralWidget = new QWidget(this);
			auto *centralLayout = new QHBoxLayout();
			centralWidget->setLayout(centralLayout);

			centralLayout->addLayout(new QGridLayout(centralWidget));


			this->vLayout = new QVBoxLayout(centralWidget);
			this->vLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);

			centralLayout->addLayout(this->vLayout, 200);

			this->show();
			this->activateWindow();

			QMessageBox::StandardButton reply = QMessageBox::question(this, "Labyrinth | Bienvenue", "Bienvenue dans Labyrinth.\n\nVoulez-vous voir les instructions avant de commencer ?", QMessageBox::Yes | QMessageBox::No);
			if (reply == QMessageBox::Yes) {
				this->displayRules();
			}

			// QString text = QInputDialog::getText(parent,"Title","text");

			/*
			for(unsigned int i = 7; i > 0; i--) {
				auto * btn = new QPushButton(QString::fromStdString(std::string("test").append(std::to_string(i))));
				btn->setStyleSheet("border-image:url(:/Icons/images/Sfondo.png);");
				vLayout->addWidget(btn);
			}
			*/
			/*
			for (unsigned int i = 0; i < game->getPlayersCount(); i++) {
				vLayout->addItem(new PlayerInfos(centralWidget, game->getPlayerAt(i)));
			}
			*/
			this->setCentralWidget(centralWidget);
		}

		void GUIView::init(void) {
			this->boardView = new BoardView(this, game);


			this->vLayout->addWidget(new QLabel("Tuile disponible :", this));
			this->vLayout->addLayout(new AvailableTile(this, this->game));

			this->vLayout->addWidget(new QLabel("Joueurs :", this));
			for (unsigned int i = 0; i < this->game->getPlayersCount(); i++) {
				auto *playerInfoBox = new PlayerInfos(this, this->game->getPlayerAt(i), this->game->getPlayerAt(i) == this->game->getCurrentPlayer());
				this->playersInfos.push_back(playerInfoBox);
				this->vLayout->addLayout(playerInfoBox);
			}

			this->updateDisplay();
		}

		/**
		 * Updates the window with the latest changes
		 */
		void GUIView::updateDisplay(void) {
			this->boardView->updateDisplay();
			for (auto *player : this->playersInfos) {
				player->updateDisplay(player->getPlayer() == this->game->getCurrentPlayer());
			}
			this->update();
			this->show();
			this->activateWindow();
		}

		/**
		 * Displays the rules to the user
		 */
		void GUIView::displayRules(void) {
			new RulesWindow(this);
		}

		/**
		 * Asks a name for the player
		 * @return the name of the new player
		 */
		std::string GUIView::askPlayerName(void) {
			// TODO
			return "";
		}

	}
}
