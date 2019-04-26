#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QWidget>
#include <QPushButton>

#include "./../include/guiView.h"
#include "./../include/playerInfos.h"
#include "./../include/welcomeWindow.h"

namespace Labyrinth_44422 {
	namespace gui {

		GUIView::GUIView(model::Game *game) :
			QMainWindow{nullptr},
			game{game},
			centralWidget{new QWidget(this)},
			centralLayout{new QHBoxLayout(this)},
			gLayout{new QGridLayout(centralWidget)},
			vLayout{new QVBoxLayout(centralWidget)} {

			this->show();
			this->activateWindow();
			this->setWindowTitle(QString::fromStdString(this->windowsTitle));

			centralLayout->addLayout(this->gLayout);

			centralLayout->addLayout(this->vLayout);
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
			centralWidget->setLayout(centralLayout);
			setCentralWidget(centralWidget);

		}

		void GUIView::update(void) {
			/*
			for(auto * el : this->vLayout->children()) {
				this->vLayout->removeItem(el);
				delete el;
			}
*/
			for(unsigned int i = 0; i < this->game->getPlayersCount(); i++) {
				this->vLayout->addItem(new PlayerInfos(this->centralWidget, this->game->getPlayerAt(i), this->game->getPlayerAt(i) == this->game->getCurrentPlayer()));
			}
		}

		void GUIView::displayWelcome(void) {
			WelcomeWindow ww(this);
		}

		std::string GUIView::askPlayerName(void) {
			return "";
		}

	}
}
