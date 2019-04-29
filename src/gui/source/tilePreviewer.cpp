#include <sstream>
#include <string>

#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include "./../include/tilePreviewer.h"
#include "./../../core/model/include/tile.h"

namespace Labyrinth_44422 {
	namespace gui {

		/**
		 * Creates an infobox to display the available tile in the board
		 * @param parent the parent window
		 * @param tile the tile to display
		 */
		TilePreviewer::TilePreviewer(QWidget *parent, model::Tile *tile) : QVBoxLayout{parent}, tile{tile} {

			auto *tileWidget = new QWidget(parent);
			tileWidget->setMaximumSize(50, 50);

			std::stringstream path;
			path << "background: url(./../resource/" << (tile->getPathLEFT() ? "t" : "f") << (tile->getPathDOWN() ? "t" : "f") << (tile->getPathRIGHT() ? "t" : "f") << (tile->getPathUP() ? "t" : "f") << ".png) 0 0 0 0 stretch stretch;"
																																																		   "background-repeat: none; width: 50px; height: 50px;";
			tileWidget->setStyleSheet(QString::fromStdString(path.str()));

			this->addWidget(tileWidget);

			auto *horizontal = new QHBoxLayout(parent);

			auto *leftButton = new QPushButton("Tourner la tuile de -90°", parent);
			auto *rightButton = new QPushButton("Tourner la tuile de 90°", parent);

			horizontal->addWidget(leftButton);
			horizontal->addWidget(rightButton);

			this->addLayout(horizontal);

		}

	} // namespace gui
} // namespace Labyrinth_44422
