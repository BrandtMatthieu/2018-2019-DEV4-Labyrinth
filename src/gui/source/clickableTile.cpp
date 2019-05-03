#include <sstream>

#include "./../include/clickableTile.h"

namespace Labyrinth_44422 {
	namespace gui {

		ClickableTile::ClickableTile(QWidget *parent, model::Tile *tile, unsigned int width, unsigned int height, bool clickable) : QPushButton{parent}, tile{tile} {
			this->setMinimumSize(width, height);
			this->updateDisplay(tile, clickable);
		}

		void ClickableTile::updateDisplay(model::Tile *tile, bool clickable) {
			// TODO
			this->setEnabled(clickable);


			std::stringstream path;
			path << ":/resource/" << (tile->getPathLEFT() ? "t" : "f") << (tile->getPathDOWN() ? "t" : "f") << (tile->getPathRIGHT() ? "t" : "f") << (tile->getPathUP() ? "t" : "f") << ".png";

			QPixmap pixmap(QString::fromStdString(path.str()));
			QPalette palette = this->palette();
			palette.setBrush(this->backgroundRole(), QBrush(pixmap));
			this->setAutoFillBackground(true);
			this->setPalette(palette);

			this->update();
			this->show();
		}

	} // namespace gui
} // namespace Labyrinth_44422
