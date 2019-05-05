#include <iostream>
#include <sstream>
#include <QPainter>

#include "./../include/clickableTile.h"
#include  "./../../core/controller/include/controllerGUI.h"

namespace Labyrinth_44422 {
	namespace gui {

		/**
		 * Creates a new clickable tile
		 * @param parent the parent of the tile
		 * @param tile the tile to display
		 * @param x the x position of the tile
		 * @param y the y position of the tile
		 * @param width the width of the tile
		 * @param height the height of the tile
		 * @param clickable if the tile is clickable or not
		 * @param controller the controller
		 */
		ClickableTile::ClickableTile(QWidget *parent, model::Tile *tile, unsigned int x, unsigned int y, unsigned int width, unsigned int height, bool clickable, controller::ControllerGUI *controller) : QToolButton{parent}, tile{tile}, x{x}, y{y}, width{width}, height{height}, controller{controller} {
			this->setMinimumSize(width, height);
			this->setMaximumSize(width, height);

			this->setIconSize(QSize(width, height));

			QSizePolicy sp = this->sizePolicy();
			sp.setHeightForWidth(true);
			sp.setWidthForHeight(true);
			this->setSizePolicy(sp);

			this->setAutoFillBackground(true);

			QObject::connect(this, &QToolButton::clicked, this, [this]() {
				this->controller->currentPlayerTryGoTo(this->x, this->y);
			});

			this->updateDisplay(tile, clickable);
		}

		/**
		 * Updates the clickable tile
		 * @param tile the new tile
		 * @param clickable if the tile is clickable
		 */
		void ClickableTile::updateDisplay(model::Tile *tile, bool clickable) {
			this->tile = tile;
			this->setEnabled(clickable);

			std::cout << (this->tile->hasObjective()?this->tile->getObjective():"pas obj") <<std::endl << this->tile->getPosition().toString() << std::endl;

			delete this->result;
			result = new QImage(QSize(500, 500), QImage::Format_RGBA64_Premultiplied);

			QImage background;
			std::stringstream tileBackground;
			tileBackground << ":/resource/tiles/" << (tile->getPathLEFT() ? "t" : "f") << (tile->getPathDOWN() ? "t" : "f") << (tile->getPathRIGHT() ? "t" : "f") << (tile->getPathUP() ? "t" : "f") << ".png";

			QPainter painter(this->result);
			painter.setCompositionMode(QPainter::CompositionMode_Source);
			painter.fillRect(this->result->rect(), Qt::transparent);
			painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
			painter.drawImage(QPoint(0, 0), QImage(QString::fromStdString(tileBackground.str())), QRect(0, 0, 500, 500), Qt::ImageConversionFlag::AutoColor);

			if (this->tile->hasObjective()) {
				std::stringstream tileObjective;
				tileObjective << ":/resource/icons/" << this->tile->getObjective() << ".png";
				painter.drawImage(0, 0, QImage(QString::fromStdString(tileBackground.str())));
			}

			painter.scale(this->size().width(), this->size().height());
			painter.end();

			auto * pal = new QPalette();
			pal->setBrush(this->backgroundRole(), QBrush(QPixmap::fromImage(*this->result, Qt::ImageConversionFlag::AutoColor)));
			this->setPalette(*pal);

			this->setIcon(QIcon(QPixmap::fromImage(*this->result, Qt::ImageConversionFlag::AutoColor)));
			this->setIconSize(QSize(this->width, this->height));
/*
			QPixmap pixmap(QString::fromStdString(path.str()));
			QPalette palette = this->palette();
			palette.setBrush(this->backgroundRole(), QBrush(pixmap));
			this->setAutoFillBackground(true);
			this->setPalette(palette);
*/
/*
			QImage result(100, 100, QImage::Format_RGB32);
			QImage source1(":/resource/tiles/tttt.png");
			source1.scaled(QSize(100, 100));
			QImage source2(":/resource/pawns/red.png");
			source2.scaled(QSize(100, 100));
*/
/*
			QPainter painter(&result);
			painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);
			painter.drawImage(result.rect(), source1);
			painter.drawImage(result.rect(), source2);
			painter.end();
*/

			this->update();
			this->show();
		}
	} // namespace gui
} // namespace Labyrinth_44422
