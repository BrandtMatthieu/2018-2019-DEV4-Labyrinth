#include <stdexcept>

#include "../include/game.h"

namespace Labyrinth_44422 {
	namespace model {

		/**
		 * Creates a new Labyrinth game
		 */
		Game::Game(void) :
			board{new Board(Position(7, 7))} {}

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

			this->players.insert(this->players.end(), new Player(name, "red", Position(0, 0)));
			// TODO changer la position initiale du joueur dynamiquement
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
		 * Starts the game
		 */
		void Game::start(void) {
			if(this->getPlayers().size() < this->getMinPlayers()) {
				throw std::runtime_error("Error while starting the game. Too few players to start the game");
			}

			this->currentPlayerIndex = 0;
		}

	}
}
