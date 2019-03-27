#include <algorithm>
#include <ctime>
#include <iostream>
#include <stdexcept>

#include "./../include/game.h"
#include "../include/game.h"


namespace Labyrinth_44422 {
	namespace model {
		
		/**
		 * Returns the first color available for the new player
		 * @return the first color available for the new player
		 */
		std::string Game::getFirstPlayerColor(void) {
			if(this->playerColors.empty()) {
				throw std::runtime_error("Error while assigning a player a color. No more colors available.");
			}
			
			std::string color = this->playerColors[0];
			this->playerColors.erase(this->playerColors.begin(), this->playerColors.begin() + 1);
			this->playerColors.shrink_to_fit();
			return color;
		}
		
		/**
		 * Creates a new Labyrinth game
		 */
		Game::Game(void) :
		board{new Board(Position{7, 7})},
		objectiveCards{} {
			
			srand(static_cast<unsigned int>(time(nullptr)));
			
			/* 6 d’entres elles sont des « T » marquées d’un objectif, */
			for(unsigned int i = 0; i < 6; i++) {
				Tile * tile = new Tile(true, true, true, false, Position{0, 0}, true, "objective", 0); // TODO pick random objective left and set position
				for(unsigned int j = static_cast<unsigned int>(rand() % 4); j > 0; j--) {
					tile->rotateLeft90();
				}
				this->availableTiles.push_back(tile);
			}
			
			/* 12 d’entre elles sont des « I » non marquées, */
			for(unsigned int i = 0; i < 12; i++) {
				Tile * tile = new Tile(true, true, false, false, Position{0, 0}, true, "", 0);
				for(unsigned int j = static_cast<unsigned int>(rand() % 4); j > 0; j--) {
					tile->rotateLeft90();
				}
				this->availableTiles.push_back(tile);
			}
			
			/* 16 d’entre elles sont des « L », dont six sont marquées d’un objectif. */
			for(unsigned int i = 0; i < 10; i++) {
				Tile * tile = new Tile(true, false, true, false, Position{0, 0}, true, "", 0); // TODO pick random objective left ans set position
				for(unsigned int j = static_cast<unsigned int>(rand() % 4); j > 0; j--) {
					tile->rotateLeft90();
				}
				this->availableTiles.push_back(tile);
			}
			
			/* 16 d’entre elles sont des « L », dont six sont marquées d’un objectif. */
			for(unsigned int i = 0; i < 6; i++) {
				Tile * tile = new Tile(true, false, true, false, Position{0, 0}, true, "objective", 0); // TODO pick random objective left and set position
				for(unsigned int j = static_cast<unsigned int>(rand() % 4); j > 0; j--) {
					tile->rotateLeft90();
				}
				this->availableTiles.push_back(tile);
			}
		}

		/**
		 * Creates a new game from an existing game object
		 * @param game the game to create the new game from
		 * aka. copy constructor
		 */
		Game::Game(const Game & game) :
			board{new Board(* game.board)},
			currentPlayerIndex{game.currentPlayerIndex} {
			for(Player * const & player_ptr : game.players) {
				this->players.push_back(new Player(* player_ptr));
			}

			if(game.winner == nullptr) {
				this->winner = nullptr;
			} else {
				unsigned int index = 0;
				while(game.players.at(index) != game.winner) {
					index++;
				}
				this->winner = this->players.at(index);
			}

			for(Tile * const & tile_ptr : game.availableTiles) {
				this->availableTiles.push_back(new Tile(* tile_ptr));
			}
		}
		
		void Game::operator=(const Game & game) {
			this->minPlayers = game.minPlayers;
			this->maxPlayers = game.maxPlayers;
			
			this->players.erase(this->players.begin());
			for(Player * const & player : game.players) {
				this->players.push_back(new Player(*player));
			}
			
			this->board = new Board(*game.board);
			
			if(game.winner == nullptr) {
				this->winner = nullptr;
			} else {
				unsigned int i = 0;
				while(game.players.at(i) != winner) {
					i++;
				}
				this->winner = this->players.at(i);
			}
			
			this->availableTiles.erase(this->availableTiles.begin());
			for(Tile * const & tile : game.availableTiles) {
				this->availableTiles.push_back(new Tile(*tile));
			}
			
			this->currentPlayerIndex = game.currentPlayerIndex;
		}

		/**
		 * Cleans the game item before it is getting destroyed
		 */
		Game::~Game(void) {
			for(const auto & player : this->players) {
				delete player;
			}
			this->players.clear();

			delete this->board;

			this->winner = nullptr;

			for(const auto & tile : this->availableTiles) {
				delete tile;
			}
			this->availableTiles.clear();
		}

		/**
		 * Returns the minimum number of players a game needs before being able to start
		 * @return the minimum number of players a game needs before being able to start
		 */
		unsigned int Game::getMinPlayers(void) const {
			return this->minPlayers;
		}

		/**
		 * Returns the maximum number of players a game may have
		 * @return the maximum number of players a game may have
		 */
		unsigned int Game::getMaxPlayers(void) const {
			return this->maxPlayers;
		}

		/**
		 * Returns a new vector containing the addresses of the players in the game
		 * @return a new vector containing the addresses of the players in the game
		 */
		std::vector<Player *> Game::getPlayers(void) const {
			return std::vector<Player *>(this->players);
		}
		
		/**
		 * Return the player at the provided index
		 * @param index the index of the player to return
		 * @return the player at the index
		 */
		Player * Game::getPlayerAt(const unsigned int index) const {
			if(index >= this->players.size()) {
				throw std::invalid_argument("Error while getting player at index. Index is out of bounds");
			}
			
			return this->players.at(index);
		}

		/**
		 * Returns the amount of players that are currently in the game
		 * @return the amount of players that are currently in the game
		 */
		unsigned int Game::getPlayersCount(void) const {
			return this->players.size();
		}

		/**
		 * Returns true if the game has enough players to start
		 * @return true if the game has enough players to start
		 */
		bool Game::hasEnoughPlayers(void) const {
			return this->players.size() >= this->minPlayers;
		}

		/**
		 * Returns true if the game has a winner
		 * @return true if the game has a winner
		 */
		bool Game::hasWinner(void) const {
			return this->winner != nullptr;
		}

		/**
		 * Returns the address of the board of the current game
		 * @return the address of the board of the current game
		 */
		Board * Game::getBoard(void) const {
			return this->board;
		}

		/**
		 * Returns the address of the player who is the winner of the game
		 * @return the address of the player who is the winner of the game
		 */
		Player * Game::getWinner(void) const {
			return this->winner;
		}

		/**
		 * Returns a new vector with the addresses of the tiles that are available in the current game
		 * @return
		 */
		std::vector<Tile *> Game::getAvailableTiles(void) const {
			return std::vector<Tile *>(this->availableTiles);
		}

		/**
		 * Returns the address of the current player of the game
		 * @return the address of the current player of the game
		 */
		Player * Game::getCurrentPlayer(void) const {
			return this->players.at(this->currentPlayerIndex);
		}

		/**
		 * Adds a new player to the current game
		 * @param name the nickname of the player to add
		 * @param color the color of the player to add
		 */
		void Game::addPlayer(const std::string & name) {
			if(this->getPlayers().size() >= this->getMaxPlayers()) {
				throw std::length_error("Error while adding player. Maximum amount of player (" +
				std::to_string(this->getMaxPlayers()) + ") already reached.");
			}

			this->players.push_back(new Player(name, this->getFirstPlayerColor(), this->board->getPlayersDefaultPositions().at(this->players.size())));
		}


		/**
		 * Skips turn of current player and select the next player
		 */
		void Game::nextPlayer(void) {
			try {
				this->currentPlayerIndex = ((this->currentPlayerIndex + 1) % this->getPlayersCount());
			} catch(std::exception & e) {
				throw std::runtime_error("Error while going to nex player. Current player not a number");
			}
		}

		/**
		 * Starts the game (method is pretty useless)
		 */
		void Game::start(void) {
			if(this->getPlayers().size() < this->getMinPlayers()) {
				throw std::runtime_error("Error while starting the game. Too few players to start the game");
			}

			this->currentPlayerIndex = 0;
		}
		
		void Game::generateObjectiveCards(void) {
			std::random_shuffle(this->gameObjectives.begin(), this->gameObjectives.end());
			for(auto & objective : this->gameObjectives) {
				this->objectiveCards.push_back(new model::ObjectiveCard(objective));
			}
		}
		
		void Game::dealObjectiveCardsToPlayers(void) {
			for(unsigned int playerIndex = 0; !objectiveCards.empty(); playerIndex = ((playerIndex + 1) % this->getPlayersCount())) {
				this->players.at(playerIndex)->addObjective(this->objectiveCards.at(0));
				this->objectiveCards.erase(this->objectiveCards.begin(), this->objectiveCards.begin() + 1);
			}
		}
		
		void Game::currentPlayerCheckObjective(void) {
			if(this->getCurrentPlayer()->getCurrentObjective()->getObjective() ==
			this->getBoard()->getTilesAt(this->getCurrentPlayer()->getPosition())->getObjective()) {
				this->getCurrentPlayer()->completeCurrentObjective();
			}
		}
	}  // namespace model
}  // namespace Labyrinth_44422
