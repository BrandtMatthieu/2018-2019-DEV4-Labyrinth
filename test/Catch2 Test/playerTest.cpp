#include "./../../src/core/model/include/player.h"
#include "./../../src/core/model/include/position.h"
#include "./../../src/core/model/include/objectiveCard.h"

#include <vector>

#include "./catch.hpp"

TEST_CASE("Player infos doesn't change over time") {
	Labyrinth_44422::model::Player myPlayer{"playerNickname", "red", Labyrinth_44422::model::Position{3, 5}};

	/**
	 * Without any objective
	 */
	REQUIRE(myPlayer.getNickname() == "playerNickname");
	REQUIRE(myPlayer.getColor() == "red");
	REQUIRE(myPlayer.getPosition() == Labyrinth_44422::model::Position{3, 5});

	Labyrinth_44422::model::ObjectiveCard objectiveCard{"objective"};
	myPlayer.addObjective(&objectiveCard);

	/**
	 * With one objective
	 * Before being completed
	 */
	REQUIRE(myPlayer.getNickname() == "playerNickname");
	REQUIRE(myPlayer.getColor() == "red");
	REQUIRE(myPlayer.getPosition() == Labyrinth_44422::model::Position{3, 5});

	/**
	 * With one objective
	 * After being completed
	 */
	myPlayer.completeCurrentObjective();
	REQUIRE(myPlayer.getNickname() == "playerNickname");
	REQUIRE(myPlayer.getColor() == "red");
	REQUIRE(myPlayer.getPosition() == Labyrinth_44422::model::Position{3, 5});
}

TEST_CASE("Getting current objective from a player over time") {
	Labyrinth_44422::model::Player myPlayer{"playerNickname", "red", Labyrinth_44422::model::Position{3, 5}};

	/**
	 * Without any objective
	 */
	REQUIRE_THROWS(myPlayer.getCurrentObjective());
	REQUIRE(myPlayer.getObjectiveCardsLeft().empty());
	REQUIRE(myPlayer.getObjectiveCardsLeftCount() == 0);

	Labyrinth_44422::model::ObjectiveCard objectiveCard{"objective"};
	myPlayer.addObjective(&objectiveCard);

	/**
	 * With one objective
	 * Before being completed
	 */
	REQUIRE(myPlayer.getCurrentObjective() == &objectiveCard);
	REQUIRE(myPlayer.getObjectiveCardsLeftCount() == 1);

	/**
	 * With one objective
	 * After being completed
	 */
	myPlayer.completeCurrentObjective();
	REQUIRE_THROWS_AS(myPlayer.getCurrentObjective(), std::range_error);
	REQUIRE(myPlayer.getObjectiveCardsLeft().empty());
	REQUIRE(myPlayer.getObjectiveCardsLeftCount() == 0);

	Labyrinth_44422::model::ObjectiveCard objectiveCard2{"objective2"};
	myPlayer.addObjective(&objectiveCard2);
	Labyrinth_44422::model::ObjectiveCard objectiveCard3{"objective3"};
	myPlayer.addObjective(&objectiveCard3);

	/**
	 * With multiple objectives
	 * Before being completed
	 */
	REQUIRE(myPlayer.getCurrentObjective() == &objectiveCard2);
	REQUIRE(!myPlayer.getObjectiveCardsLeft().empty());
	REQUIRE(myPlayer.getObjectiveCardsLeftCount() == 2);

	myPlayer.completeCurrentObjective();
	REQUIRE(myPlayer.getCurrentObjective() == &objectiveCard3);
	REQUIRE(!myPlayer.getObjectiveCardsLeft().empty());
	REQUIRE(myPlayer.getObjectiveCardsLeftCount() == 1);

	/**
	 * With multiple objectives
	 * After being completed
	 */
	myPlayer.completeCurrentObjective();
	REQUIRE_THROWS_AS(myPlayer.getCurrentObjective(), std::range_error);
	REQUIRE(myPlayer.getObjectiveCardsLeft().empty());
	REQUIRE(myPlayer.getObjectiveCardsLeftCount() == 0);
}

TEST_CASE("Getting completed objectives from a player over time") {
	Labyrinth_44422::model::Player myPlayer{"playerNickname", "red", Labyrinth_44422::model::Position{3, 5}};

	/**
	 * Without any objective
	 */
	REQUIRE(myPlayer.getCompletedObjectiveCards().empty());
	REQUIRE(myPlayer.getCompletedObjectiveCardsCount() == 0);

	Labyrinth_44422::model::ObjectiveCard objectiveCard{"objective"};
	myPlayer.addObjective(&objectiveCard);

	/**
	 * With one objective
	 */
	REQUIRE(myPlayer.getCompletedObjectiveCards().empty());
	REQUIRE(myPlayer.getCompletedObjectiveCardsCount() == 0);

	myPlayer.completeCurrentObjective();
	REQUIRE(!myPlayer.getCompletedObjectiveCards().empty());
	REQUIRE(myPlayer.getCompletedObjectiveCardsCount() == 1);

	Labyrinth_44422::model::ObjectiveCard objectiveCard2{"objective2"};
	myPlayer.addObjective(&objectiveCard2);
	Labyrinth_44422::model::ObjectiveCard objectiveCard3{"objective3"};
	myPlayer.addObjective(&objectiveCard3);

	/**
	 * With multiple objectives
	 */
	REQUIRE(!myPlayer.getCompletedObjectiveCards().empty());
	REQUIRE(myPlayer.getCompletedObjectiveCardsCount() == 1);

	myPlayer.completeCurrentObjective();
	REQUIRE(!myPlayer.getCompletedObjectiveCards().empty());
	REQUIRE(myPlayer.getCompletedObjectiveCardsCount() == 2);

	myPlayer.completeCurrentObjective();
	REQUIRE(!myPlayer.getCompletedObjectiveCards().empty());
	REQUIRE(myPlayer.getCompletedObjectiveCardsCount() == 3);
}

TEST_CASE("Getting turn infos from a player over time") {
	Labyrinth_44422::model::Player myPlayer{"playerNickname", "red", Labyrinth_44422::model::Position{3, 5}};

	REQUIRE_FALSE(myPlayer.hasInsertedTile());
	REQUIRE_FALSE(myPlayer.hasMovedPawn());

	myPlayer.insertTile();
	REQUIRE(myPlayer.hasInsertedTile());
	REQUIRE_FALSE(myPlayer.hasMovedPawn());

	myPlayer.movePawn(Labyrinth_44422::model::Position{0, 0});
	REQUIRE(myPlayer.hasInsertedTile());
	REQUIRE(myPlayer.hasMovedPawn());

	myPlayer.endTurn();
	REQUIRE_FALSE(myPlayer.hasInsertedTile());
	REQUIRE_FALSE(myPlayer.hasMovedPawn());

	REQUIRE_THROWS(myPlayer.movePawn(Labyrinth_44422::model::Position{3, 5}));
}
