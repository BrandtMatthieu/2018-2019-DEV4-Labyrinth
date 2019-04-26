#ifndef CONSOLEVIEW_H
#define CONSOLEVIEW_H

#include <string>

#include "./../../core/model/include/game.h"

namespace Labyrinth_44422 {
    namespace console {

        /**
         * Represents a console view of the Labyrinth game
         * @author 44422
         * @version 0.1.3
         * @since 2019-03-05
         */
        class ConsoleView {
        private:
            const unsigned int pathSize = 3;
            const unsigned int tileSize = 3 * pathSize + 2;

            const unsigned int wall1 = pathSize;
            const unsigned int wall2 = 2 * pathSize + 1;

            const std::string wall;
            const std::string path;
            const std::string space;
            const std::string objective;
            const bool spacing = true;
            const bool arrows = true;

            void printTileLine(const Labyrinth_44422::model::Tile *const tile, const unsigned int &ligneDansTuile,
                               std::string &str) const;

        public:
            explicit ConsoleView(const bool spacing, const bool arrows);

            ConsoleView(const ConsoleView &vue);

            ~ConsoleView() = default;

            bool getYesNoAnswer(const std::string &message) const;

            std::string getNewPlayerName(void) const;

            std::string getCommand(void) const;

            void printGameInfos(const model::Game *const game) const;

            void printBoard(const model::Board *const board) const;

            void printPlayerInfos(const model::Player *const player) const;

            void printWinner(model::Player *player);

            void printMessage(const std::string &message) const;

            void printError(const std::string &error) const;

            void printHelp(const model::Board *const board) const;

            void printWelcome(void) const;

            void printInstructions(void) const;

            void printTile(const Labyrinth_44422::model::Tile *const tile) const;

            void printBoardObjectives(model::Board *board, std::vector<model::Tile *> availableTiles) const;

            void printAvailableTile(model::Tile *&tile) const;

            void printPlayersInfos(std::vector<model::Player *> players) const;

            void clearScreen(void) const;

            void lineBreak(void) const;
        };
    } // namespace console
} // namespace Labyrinth_44422

#endif // CONSOLEVIEW_H
