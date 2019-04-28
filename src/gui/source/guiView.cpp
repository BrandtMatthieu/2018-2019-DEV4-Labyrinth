#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QWidget>
#include <QPushButton>


#include <iostream>

#include "./../include/guiView.h"
#include "./../include/playerInfos.h"
#include "./../include/welcomeWindow.h"

namespace Labyrinth_44422 {
	namespace gui {

		GUIView::GUIView(model::Game *game) :
			QMainWindow{nullptr},
			game{game} {

			this->setWindowTitle(QString::fromStdString(this->windowsTitle));
			this->setMinimumSize(800, 600);

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

		void GUIView::updateDisplay(void) {
/*
			for(auto * el : this->vLayout->children()) {
				this->vLayout->removeItem(el);
				delete el;
			}
*/

			std::cout << std::to_string(this->game->getPlayersCount()) << std::endl;

			for(unsigned int i = 0; i < this->game->getPlayersCount(); i++) {
				auto * playerInfoBox = new PlayerInfos(this, this->game->getPlayerAt(i), this->game->getPlayerAt(i) == this->game->getCurrentPlayer());
				this->vLayout->addLayout(playerInfoBox);
			}
			this->vLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
			this->update();
		}

		void GUIView::displayWelcome(void) {
			new WelcomeWindow(this);
		}

		std::string GUIView::askPlayerName(void) {
			return "";
		}

	}
}
