#include <iostream>
#include <sstream>

#include <QApplication>
#include <QDebug>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QInputDialog>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>

#include "./../include/boardView.h"
#include "./../include/guiView.h"
#include "./../include/playerInfos.h"
#include "./../include/rulesWindow.h"
#include "./../include/availableTile.h"
#include "./../../core/controller/include/controllerGUI.h"

namespace Labyrinth_44422 {
	namespace gui {

		/**
		 * Creates the main window of the Labyrinth game
		 * @param game the game to display
		 * @param controller the controller of the game
		 */
		GUIView::GUIView(model::Game *game, controller::ControllerGUI *controller) : QMainWindow{nullptr}, game{game}, controller{controller} {

			this->setWindowTitle(QString::fromStdString("Labyrinth | n°15 - 44422 - D112 - DEVG4 - 2018-2019"));
			this->setMinimumSize(1200, 900);

			auto *centralWidget = new QWidget(this);
			auto *centralLayout = new QHBoxLayout();
			centralWidget->setLayout(centralLayout);

			// centralLayout->addWidget(new BoardView(centralWidget, game));


			this->vLayout = new QVBoxLayout(centralWidget);
			this->vLayout->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);

			centralLayout->addLayout(this->vLayout, 200);

			this->show();
			this->activateWindow();

			QMessageBox::StandardButton reply = QMessageBox::question(this, "Labyrinth | Bienvenue", "Bienvenue dans Labyrinth.\n\nVoulez-vous voir les instructions avant de commencer ?", QMessageBox::Yes | QMessageBox::No);
			if (reply == QMessageBox::Yes) {
				this->displayRules();
			}

			while ((!this->game->hasEnoughPlayers()) || ((this->game->getPlayersCount() < this->game->getMaxPlayers()) && (QMessageBox::question(this, "Labyrinth | Ajouter joueur", "Voulez-vous ajouter un autre joueur dans la partie ?", QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes))) {
				QString text = QInputDialog::getText(this, "Labyrinth | Ajouter joueur", "Entrez un nom pour le joueur");
				if (text.length() == 0) {
					text = QString::fromStdString("Joueur " + std::to_string(this->game->getPlayersCount() + 1));
				}
				this->controller->addPlayer(text.toStdString());
			}

			this->setCentralWidget(centralWidget);
		}

		/**
		 * Creates a new GUI View and adds the main compononents
		 */
		void GUIView::init(void) {

			this->boardView = new BoardView(this, game, controller);
			this->centralWidget()->layout()->addWidget(boardView);

			this->vLayout->addWidget(new QLabel("Tuile disponible :", this));
			this->availableTile = new AvailableTile(this, this->game, controller);
			this->vLayout->addLayout(this->availableTile);

			this->vLayout->addWidget(new QLabel("Joueurs :", this));
			for (unsigned int i = 0; i < this->game->getPlayersCount(); i++) {
				auto *playerInfoBox = new PlayerInfos(this, this->game->getPlayerAt(i), this->game->getPlayerAt(i) == this->game->getCurrentPlayer());
				this->playersInfos.push_back(playerInfoBox);
				this->vLayout->addWidget(playerInfoBox);
			}


			this->updateDisplay();
		}

		/**
		 * Updates the window with the latest changes
		 */
		void GUIView::updateDisplay(void) {
			this->boardView->updateDisplay();
			this->availableTile->updateDisplay();
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
		 * Displays the Winner of the game
		 */
		void GUIView::displayWinner() {
			std::stringstream message;
			message << this->game->getWinner()->getNickname() << " est le gagnant de cette partie.";
			QMessageBox::StandardButton reply = QMessageBox::question(this, "Labyrinth | Gagnant", QString::fromStdString(message.str()), QMessageBox::Yes | QMessageBox::No);
			if (reply == QMessageBox::Yes) {
				QApplication::quit();
			}
		}

	}
}
