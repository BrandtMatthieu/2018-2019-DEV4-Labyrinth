#include <iostream>

#include <QApplication>
#include <QDebug>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include "./../include/guiView.h"
#include "./../include/playerInfos.h"
#include "./../include/rulesWindow.h"
#include "./../include/tilePreviewer.h"
#include "./../include/welcomeWindow.h"

namespace Labyrinth_44422 {
	namespace gui {

		/**
		 * Creates the main window of the Labyrinth game
		 * @param game the game to display
		 */
		GUIView::GUIView(model::Game *game) : QMainWindow{nullptr}, game{game} {

			this->setWindowTitle(QString::fromStdString(this->windowsTitle));
			this->setMinimumSize(1200, 800);

			this->centralWidget = new QWidget(this);

			this->centralLayout = new QHBoxLayout(centralWidget); //

			this->gLayout = new QGridLayout(centralWidget);
			this->gLayout->addWidget(new QPushButton(centralWidget));
			this->gLayout->addWidget(new QPushButton(centralWidget));
			this->gLayout->addWidget(new QPushButton(centralWidget));
			this->gLayout->addWidget(new QPushButton(centralWidget));
			this->gLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
			this->vLayout = new QVBoxLayout(centralWidget);

			centralLayout->addLayout(this->gLayout, 200);

			centralLayout->addLayout(this->vLayout, 200);

			QMessageBox::StandardButton reply = QMessageBox::question(this, "Labyrinth | Bienvenue", "Bienvenue dans Labyrinth.\n\nVoulez-vous voir les instructions avant de commencer ?", QMessageBox::Yes | QMessageBox::No);
			if (reply == QMessageBox::Yes) {
				this->displayRules();
			}
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
			setCentralWidget(this->centralWidget);

			this->show();
			this->activateWindow();
		}

		/**
		 * Updates the window with the latest changes
		 */
		void GUIView::updateDisplay(void) {
			/*
			for(auto * el : this->vLayout->children()) {
				this->vLayout->removeItem(el);
				delete el;
			}
			*/
			this->vLayout->addWidget(new QLabel("Tuile disponible :", this));
			this->vLayout->addLayout(new TilePreviewer(this, this->game->getAvailableTiles().at(0)));

			this->vLayout->addWidget(new QLabel("Joueurs :", this));
			for (unsigned int i = 0; i < this->game->getPlayersCount(); i++) {
				auto *playerInfoBox = new PlayerInfos(this, this->game->getPlayerAt(i), this->game->getPlayerAt(i) == this->game->getCurrentPlayer());
				this->vLayout->addLayout(playerInfoBox);
			}
			this->vLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
			this->update();
		}

		/**
		 * Displays the welcome message to the user
		 */
		void GUIView::displayWelcome(void) {
			new WelcomeWindow(this);
		}

		/**
		 * Displays the rules to the user
		 */
		void GUIView::displayRules(void) {
			new RulesWindow(this);
		}

		/**
		 * Asks a name for the player
		 */
		std::string GUIView::askPlayerName(void) {
			return "";
		}

	}
}
