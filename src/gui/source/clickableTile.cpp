#include <sstream>

#include "./../include/clickableTile.h"
#include  "./../../core/controller/include/controllerGUI.h"

namespace Labyrinth_44422 {
	namespace gui {

		ClickableTile::ClickableTile(QWidget *parent, model::Tile *tile, unsigned int width, unsigned int height, bool clickable, controller::ControllerGUI *controller) : QPushButton{parent}, tile{tile}, controller{controller} {
			this->setMinimumSize(width, height);
			this->setMaximumSize(width, height);
			QSizePolicy sp = this->sizePolicy();
			sp.setHeightForWidth(true);
			sp.setWidthForHeight(true);
			this->setSizePolicy(sp);

			QObject::connect(this, &QPushButton::clicked, this, [this]() {
				this->controller->currentPlayerTryGoTo(this->tile->getPosition().getX(), this->tile->getPosition().getY());
			});

			this->updateDisplay(tile, clickable);
		}

		void ClickableTile::updateDisplay(model::Tile *tile, bool clickable) {
			this->setEnabled(clickable);

			/*
			QPixmap pixmap(QString::fromStdString(path.str()));
			QPalette palette = this->palette();
			palette.setBrush(this->backgroundRole(), QBrush(pixmap));
			this->setAutoFillBackground(true);
			this->setPalette(palette);
			*/

			std::stringstream path;
			path << "background-image: url(./../resource/" << (tile->getPathLEFT() ? "t" : "f") << (tile->getPathDOWN() ? "t" : "f") << (tile->getPathRIGHT() ? "t" : "f") << (tile->getPathUP() ? "t" : "f") << ".png)0 0 0 0 stretch stretch;";
			this->setStyleSheet(QString::fromStdString(path.str()));

			this->update();
			this->show();
		}

	} // namespace gui
} // namespace Labyrinth_44422
