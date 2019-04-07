#include <cmath>
#include <stdexcept>

#include "./../include/board.h"


namespace Labyrinth_44422 {
	namespace model {

		/**
		 * Finds a tile in a vector of tiles and returns it's index
		 * @param myVector the vector where to search
		 * @param tile the tile to search for
		 * @throw invalid_argument if tile is null
		 * @throw runtime_error if myVector doesn't includes the tile
		 * @return the index of the tiles in the provided vector
		 */
		unsigned int Board::indexOf(const std::vector<Tile *> & myVector, const Tile * const tile) const {
			if(tile == nullptr) {
				throw std::invalid_argument("Error while initializing the board. Cannot get the index if tile is null.");
			}
			if(!this->includes(myVector, tile)) {
				throw std::runtime_error("Error while getting the index of the tile. The tile doesn't exists inside the vector.");
			}

			for(unsigned int i = 0; i < myVector.size(); i++) {
				if(this->tiles[i] == tile) {
					return i;
				}
			}
			return 0;
		}

		/**
		 * Returns true if an element exists in a vector
		 * @param myVector the vector where to search
		 * @param tile the tile to search for
		 * @throw invalid_argument if tile is null
		 * @return true if an element exists in a vector
		 */
		bool Board::includes(const std::vector<Tile *> & myVector, const Tile * const tile) const {
			if(tile == nullptr) {
				throw std::invalid_argument("Error while initializing the board. Cannot get the index if tile is null.");
			}

			for(unsigned int i = 0; i < myVector.size(); i++) {
				if(this->tiles[i] == tile) {
					return true;
				}
			}
			return false;
		}

		/**
		 * Creates a new board for the Labyrinth game
		 * @param maxPosition the position used to get the size of the board
		 */
		Board::Board(const Position & maxPosition) :
			maxSize{maxPosition},
			tiles{std::vector<Tile *>(maxPosition.getX() * maxPosition.getY())},
			playersDefaultPositions{
				Position{0, maxSize.getY() - 1},
				Position{maxSize.getX() - 1, maxSize.getY() - 1},
				Position{maxSize.getX() - 1, 0},
				Position{0, 0}
			} {
		}

		/**
		 * Creates a new board from an existing board
		 * aka. copy constructor
		 * @param board the board to create the new board from
		 */
		Board::Board(const Board & board) :
			maxSize{board.getMaxSize()},
			tiles{std::vector<Tile *>()} {
			for(Tile * const & tile_ptr : board.tiles) {
				this->tiles.push_back(new Tile(* tile_ptr));
			}
		}

		/**
		 * Creates a new board from another board
		 * @param board another board
		 */
		Board & Board::operator=(const Board & board) {
			if(&board == this) {
				return *this;
			}

			this->maxSize = board.maxSize;

			for(Tile * const & tile : board.tiles) {
				this->tiles.push_back(new Tile(*tile));
			}

			this->playersDefaultPositions = board.playersDefaultPositions;
			return *this;
		}

		/**
		 * Destroys the board object and cleans its members
		 */
		Board::~Board(void) {
			for(Tile * const & tile_ptr : this->tiles) {
				delete tile_ptr;
			}
			this->tiles.clear();
		}

		/**
		 * Returns the horizontal size of the game's board
		 * @return the horizontal size of the game's board
		 */
		unsigned int Board::getMaxSizeX(void) const {
			return this->maxSize.getX();
		}

		/**
		 * Returns the vertical size of the game's board
		 * @return the vertical size of the game's board
		 */
		unsigned int Board::getMaxSizeY(void) const {
			return this->maxSize.getY();
		}

		/**
		 * Returns the max positions of the board
		 * @return the max positions of the board
		 */
		Position Board::getMaxSize(void) const {
			return this->maxSize;
		}

		/**
		 * Returns the vector containing the addresses of the tiles of the game
		 * @return the vector containing the addresses of the tiles of the game
		 */
		std::vector<Tile *> Board::getTiles(void) const {
			return this->tiles;
		}

		/**
		 * Returns the tile count
		 * @return the tile count
		 */
		unsigned int Board::getTilesCount(void) const {
			return this->tiles.size();
		}

		/**
		 * Returns the address of the tile at a provided position
		 * @param position  the position of the tile to get
		 * @throw invalid_argument if the position is out of bounds of the board
		 * @throw runtime_error if the tile retrieved is null (no tile at this position)
		 * @return the address of the tile at a provided position
		 */
		Tile * Board::getTilesAt(const Position & position) const {
			if(!this->isPositionInsideBoard(position)) {
				throw std::invalid_argument("Error while getting the tile at "
					+ position.toString() +
					". Position is out of board's bounds (1;1) to " +
					this->maxSize.toString());
			}

			return this->tiles.at(position.getX() + position.getY() * this->getMaxSizeX());
		}

		/**
		 * Returns the address of the tile at a provided position
		 * @index position  the position of the tile to get
		 * @throw invalid_argument if the position is out of bounds of the board
		 * @throw runtime_error if the tile retrieved is null (no tile at this position)
		 * @return the address of the tile at a provided position
		 */
		Tile * Board::getTilesAt(const unsigned int index) const {
			model::Position position{index % this->getMaxSizeX(), index / this->getMaxSizeX()};
			if(!this->isPositionInsideBoard(position)) {
				throw std::invalid_argument("Error while getting the tile at "
					+ position.toString() +
					". Position is out of board's bounds (1;1) to " +
					this->maxSize.toString());
			}

			return this->tiles.at(index);
		}

		/**
		 * Checks if the provided position is inside the board
		 * @param position the position to check
		 * @return true if the provided position in inside the game's board
		 */
		bool Board::isPositionInsideBoard(const Position & position) const {
			return position.getX() < this->maxSize.getX() &&
					position.getY() < this->maxSize.getY();
		}

		/**
		 * Sets a tile in the game's board
		 * @param position the position of where to set the tile
		 * @param tile the tile to set at the provided position
		 * @throw invalid_argument if position is out of bounds
		 * @throw invalid_argument if tile is null
		 * @throw runtime_error if the tile overlaps an existing tile to prevent memory leaks
		 */
		void Board::setTile(const Position & position, Tile * const tile) {
			if(!this->isPositionInsideBoard(position)) {
				throw std::invalid_argument("Error while setting a tile at a position. Position (position) is out of bounds");
			}
			if(tile == nullptr) {
				throw std::invalid_argument("Error while setting a tile. Cannot set the tile if the tile is null (position).");
			}

			// prevents memory leaks by not letting a tile getting overwritten
			if(this->getTilesAt(position) != nullptr) {
				throw std::runtime_error("Error while setting tile. Cannot overlap tile");
			}


			tile->setPosition(position);

			this->tiles[position.getX() + position.getY() * this->getMaxSizeX()] = tile;
		}

		/**
		 * Sets a tile in the game's board
		 * @param x the x position of the tile to set
		 * @param y the y position of the tile to set
		 * @param tile the tile to set at the provided position
		 * @throw invalid_argument if provided position is out of bounds
		 * @throw invalid_argument if tile is null
		 */
		void Board::setTile(const unsigned int x, const unsigned int y, Tile * const tile) {
			if(!this->isPositionInsideBoard(Position(x, y))) {
				throw std::invalid_argument("Error while setting a tile at a position. Position (x;y) is out of bounds");
			}
			if(tile == nullptr) {
				throw std::invalid_argument("Error while setting a tile. Cannot set the index if the tile is null (x;y).");
			}

			tile->setPosition(Position{x, y});

			this->tiles[x + y * this->getMaxSizeX()] = tile;
		}

		/**
		 * Sets a tile in the game's board
		 * @param index the index of the tile to set
		 * @param tile the tile to set at the provided position
		 * @throw invalid_argument if the provided position is out of bounds
		 * @throw invalid_argument if the tile is null
		 */
		void Board::setTile(const unsigned int index, Tile * const tile) {
			if(index > tiles.size()) {
				throw std::invalid_argument("Error while setting a tile at a position. Position (index) is out of bounds");
			}
			if(tile == nullptr) {
				throw std::invalid_argument("Error while setting a tile. Cannot set the index if the tile is null (index).");
			}

			tile->setPosition(Position{index % this->getMaxSizeX(), index / this->getMaxSizeX()});

			this->tiles[index] = tile;
		}

		/**
		 * Returns the default position for the players
		 * @return the default position for the players
		 */
		std::vector<Position> Board::getPlayersDefaultPositions() const {
			return this->playersDefaultPositions;
		}

		/**
		 * Returns a vector with the position of the unmovable tiles of the 7x7 board
		 * @return a vector with the position of the unmovable tiles of the 7x7 board
		 */
		std::vector<Position> Board::getUnmovableTilesPositions(void) const {
			return std::vector<Position>{
				Position(0, 2),
				Position(0, 4),
				Position(2, 0),
				Position(2, 2),
				Position(2, 4),
				Position(2, 6),
				Position(4, 0),
				Position(4, 2),
				Position(4, 4),
				Position(4, 6),
				Position(6, 2),
				Position(6, 4)
			};
		}

		/**
		 * Returns true if the board is missing a tile
		 * @return true if the board is missing a tile
		 */
		bool Board::hasEmptyTiles(void) const {
			for(unsigned int i = 0; i < this->getTilesCount(); i++) {
				if(this->tiles.at(i) == nullptr) {
					return true;
				}
			}
			return false;
		}

		/**
		 * Returns the position of the first free tile of the board
		 * @throw runtime_error if the board doesn't have any empty tile
		 * @return the position of the first free tile of the board
		 */
		Position Board::getEmptyTile(void) const {
			if(this->hasEmptyTiles()) {
				for(unsigned int i = 0; i < this->getTilesCount(); i++) {
					if(this->tiles.at(i) == nullptr) {
						return Position(i % this->getMaxSizeX(), i / this->getMaxSizeX());
					}
				}
			}
			throw std::runtime_error("Error while retrieving position of empty tile. No empty tile");
		}

		/**
		 * Returns true if a tile can be inserted at the provided position
		 * @param position the position to check where to insert the tile
		 * @param side which side the tile need to be inserted in
		 * @throw invalid_argument if provided position is out of bounds
		 * @return true if a tile can be inserted at the provided position
		 */
		bool Board::canInsertTile(const Position & position, const InsertSide & side) const {
			if(!this->isPositionInsideBoard(position)) {
				throw std::invalid_argument("Error while inserting a tile at a position. Position is out of bounds.");
			}

			bool lineMovable = true;
			switch(side) {
				case InsertSide::UP:
				case InsertSide::DOWN:
					for(unsigned int i = position.getX(); i < this->tiles.size(); i = i + this->getMaxSizeX()) {
						lineMovable = lineMovable && this->tiles.at(i)->isMovable();
					}
					break;
				case InsertSide::RIGHT:
				case InsertSide::LEFT:
					for(unsigned int i = position.getY() * this->getMaxSizeX(); i < (position.getY() + 1) * this->getMaxSizeX(); i++) {
						lineMovable = lineMovable && this->tiles.at(i)->isMovable();
					}
					break;
			}
			return lineMovable;
		}

		/**
		 * Inserts the tile at the provided position onto the game's board
		 * @param position the position where to insert the tile
		 * @param availableTiles the tile to insert
		 * @param side what side to insert the tile at
		 * @throw runtime_error if the provided position is out of bound
		 * @throw runtime_error if the tile cannot be inserted this side
		 * @return the tile kicked
		 */
		Tile * Board::insertTile(const Position & position, std::vector<Tile *> & availableTiles, const InsertSide & side) {
			if(!this->isPositionInsideBoard(position)) {
				throw std::runtime_error("Error while inserting a availableTiles. Position out of bounds.");
			}
			if(!this->canInsertTile(position, side)) {
				throw std::runtime_error("Error while inserting a availableTiles. Column or row cannot move.");
			}

			Tile * kickedTile;

			switch(side) {
				case InsertSide::LEFT:
					kickedTile = getTilesAt(Position(0, position.getY()));
					for(unsigned int i = 0; i < this->maxSize.getX() - 1; i++) {
						this->tiles.at(i + position.getY() * this->getMaxSizeX()) = nullptr;
						setTile(Position(i, position.getY()), getTilesAt(Position(i + 1, position.getY())));
						this->getTilesAt(Position{i, position.getY()})->move(InsertSide::RIGHT);
					}
					setTile(Position(this->maxSize.getX() - 1, position.getY()), availableTiles.at(0));
					break;
				case InsertSide::RIGHT:
					kickedTile = getTilesAt(Position(this->maxSize.getX() - 1, position.getY()));
					for(unsigned int i = this->maxSize.getX() - 1; 0 < i; i--) {
						this->tiles.at(i + position.getY() * this->getMaxSizeX()) = nullptr;
						setTile(Position(i, position.getY()), getTilesAt(Position(i - 1, position.getY())));
						this->getTilesAt(Position{i, position.getY()})->move(InsertSide::LEFT);
					}
					setTile(Position(0, position.getY()), availableTiles.at(0));
					break;
				case InsertSide::UP:
					kickedTile = getTilesAt(Position(position.getX(), 0));
					for(unsigned int i = 0; i < this->maxSize.getY() - 1; i++) {
						this->tiles.at(position.getX() + i * this->getMaxSizeX()) = nullptr;
						setTile(Position(position.getX(), i), getTilesAt(Position(position.getX(), i + 1)));
						this->getTilesAt(Position(position.getX(), i))->move(InsertSide::DOWN);
					}
					setTile(Position(position.getX(), this->maxSize.getY() - 1), availableTiles.at(0));
					break;
				case InsertSide::DOWN:
					kickedTile = getTilesAt(Position(position.getX(), this->maxSize.getY() - 1));
					for(unsigned int i = this->maxSize.getY() - 1; 0 < i; i--) {
						this->tiles.at(position.getX() + i * this->getMaxSizeX()) = nullptr;
						setTile(Position(position.getX(), i), getTilesAt(Position(position.getX(), i - 1)));
						this->getTilesAt(Position(position.getX(), i))->move(InsertSide::UP);
					}
					this->tiles.at(position.getX()) = nullptr;
					setTile(Position(position.getX(), 0), availableTiles.at(0));
					break;
			}

			kickedTile->setPosition(Position{0, 0});

			availableTiles.erase(availableTiles.begin());

			return kickedTile;
		}

		/**
		 * Returns true if a player can go to a provided position
		 * @param position the position to check to player can go to
		 * @param player the player
		 * @throw invalid_argument if the "from" position is out of bounds
		 * @throw invalid_argument if the "to" position is out of bounds
		 * @return true if a player can go to a provided position
		 */
		bool Board::canGoToFrom(const Position & from, const Position & to) {
			if(!this->isPositionInsideBoard(from)) {
				throw std::invalid_argument("Error while checking valid tiles. \"From\" position is out of bounds");
			}
			if(!this->isPositionInsideBoard(to)) {
				throw std::invalid_argument("Error while checking valid tiles. \"To\" position is out of bounds");
			}

			std::vector<Tile *> tilesToCheck;
			std::vector<Tile *> tilesPossible;
			std::vector<Tile *> tilesNotPossible;

			tilesPossible.push_back(this->tiles[from.getX() + from.getY() * (this->maxSize.getX())]);
			tilesToCheck.push_back(this->tiles[from.getX() + from.getY() * (this->maxSize.getX())]);

			while (!tilesToCheck.empty()) {

				unsigned int currentTileX;
				unsigned int currentTileY;

				Tile * currentTile = tilesToCheck[0];

				currentTileX = this->indexOf(this->tiles, currentTile) % this->maxSize.getX();
				currentTileY = this->indexOf(this->tiles, currentTile) / this->maxSize.getX();

				unsigned int index;
				if (currentTileX + 1 < this->maxSize.getX()) {
					index = (currentTileX + 1) + currentTileY * this->maxSize.getX();
					if (currentTile->getPathRIGHT() && this->tiles[index]->getPathLEFT() && !this->includes(tilesPossible, this->tiles[index])) {
						if (!this->includes(tilesToCheck, this->tiles[index])) {
							tilesToCheck.push_back(this->tiles[index]);
						}
						if (!this->includes(tilesPossible, this->tiles[index])) {
							tilesPossible.push_back(this->tiles[index]);
						}
						if (this->includes(tilesNotPossible, this->tiles[index])) {
							tilesNotPossible.erase(tilesNotPossible.begin() + this->indexOf(tilesNotPossible, this->tiles[index]));
						}
					} else {
						if (!this->includes(tilesNotPossible, this->tiles[index])) {
							tilesNotPossible.push_back(this->tiles[index]);
						}
					}
				}
				if (currentTileX >= 1) {
					index = (currentTileX - 1) + currentTileY * this->maxSize.getX();
					if (currentTile->getPathLEFT() && this->tiles[index]->getPathRIGHT() && !this->includes(tilesPossible, this->tiles[index])) {
						if (!this->includes(tilesToCheck, this->tiles[index])) {
							tilesToCheck.push_back(this->tiles[index]);
						}
						if (!this->includes(tilesPossible, this->tiles[index])) {
							tilesPossible.push_back(this->tiles[index]);
						}
						if (this->includes(tilesNotPossible, this->tiles[index])) {
							tilesNotPossible.erase(tilesNotPossible.begin() + this->indexOf(tilesNotPossible, this->tiles[index]));
						}
					} else {
						if (!this->includes(tilesNotPossible, this->tiles[index])) {
							tilesNotPossible.push_back(this->tiles[index]);
						}
					}
				}
				if (currentTileY >= 1) {
					index = currentTileX + (currentTileY - 1) * this->maxSize.getX();
					if (currentTile->getPathUP() && this->tiles[index]->getPathDOWN() && !this->includes(tilesPossible, this->tiles[index])) {
						if (!this->includes(tilesToCheck, this->tiles[index])) {
							tilesToCheck.push_back(this->tiles[index]);
						}
						if (!this->includes(tilesPossible, this->tiles[index])) {
							tilesPossible.push_back(this->tiles[index]);
						}
						if (this->includes(tilesNotPossible, this->tiles[index])) {
							tilesNotPossible.erase(tilesNotPossible.begin() + this->indexOf(tilesNotPossible, this->tiles[index]));
						}
					} else {
						if (!this->includes(tilesNotPossible, this->tiles[index])) {
							tilesNotPossible.push_back(this->tiles[index]);
						}
					}
				}
				if (currentTileY + 1 < this->maxSize.getY()) {
					index = currentTileX + (currentTileY + 1) * this->maxSize.getX();
					if (currentTile->getPathDOWN() && this->tiles[index]->getPathUP() && !this->includes(tilesPossible, this->tiles[index])) {
						if (!this->includes(tilesToCheck, this->tiles[index])) {
							tilesToCheck.push_back(this->tiles[index]);
						}
						if (!this->includes(tilesPossible, this->tiles[index])) {
							tilesPossible.push_back(this->tiles[index]);
						}
						if (this->includes(tilesNotPossible, this->tiles[index])) {
							tilesNotPossible.erase(tilesNotPossible.begin() + this->indexOf(tilesNotPossible, this->tiles[index]));
						}
					} else {
						if (!this->includes(tilesNotPossible, this->tiles[index])) {
							tilesNotPossible.push_back(this->tiles[index]);
						}
					}
				}
				tilesToCheck.erase(tilesToCheck.begin() + 0);
			}

			return this->includes(tilesPossible, this->tiles[to.getX() + to.getY() * this->maxSize.getX()]);
		}
	}  // namespace model
}  // namespace Labyrinth_44422
