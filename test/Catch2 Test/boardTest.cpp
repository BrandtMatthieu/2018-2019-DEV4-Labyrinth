#include "./../../src/core/model/include/board.h"

#include <vector>

#include "./catch.hpp"

TEST_CASE("board infos don't change over time") {
	Labyrinth_44422::model::Board myBoard{Labyrinth_44422::model::Position{7, 7}};
	std::vector<Labyrinth_44422::model::Position> playersDefaultPositions = {Labyrinth_44422::model::Position{0, 6}, Labyrinth_44422::model::Position{6, 6}, Labyrinth_44422::model::Position{6, 0}, Labyrinth_44422::model::Position{0, 0}};

	REQUIRE(myBoard.getMaxSize() == Labyrinth_44422::model::Position{7, 7});
	REQUIRE(myBoard.getMaxSizeX() == 7);
	REQUIRE(myBoard.getMaxSizeY() == 7);
	REQUIRE(myBoard.getTilesCount() == 0);
	REQUIRE(myBoard.getTilesAt(0) == nullptr);
	REQUIRE(myBoard.getTiles().empty());
	REQUIRE(myBoard.getPlayersDefaultPositions() == playersDefaultPositions);
}
