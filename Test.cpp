/**
 * Created by talko on 4/24/22.
 *
 */

#include "doctest.h"
#include "Game.hpp"
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"

using namespace coup;
using namespace std;

TEST_CASE("1. Check Game") {
    Game game_1{};
    Duke duke{game_1, "Moshe"};
    CHECK_EQ(game_1.players().size(),1);
    Assassin assassin{game_1, "Yossi"};
    CHECK_EQ(game_1.players().size(),2);
    Ambassador ambassador{game_1, "Meirav"};
    CHECK_EQ(game_1.players().size(),3);
    Captain captain{game_1, "Reut"};
    CHECK_EQ(game_1.players().size(),4);
    Contessa contessa{game_1, "Gilad"};
    CHECK_EQ(game_1.players().size(),5);

    CHECK_NOTHROW(duke.income());
    CHECK_NOTHROW(assassin.income());
    CHECK_NOTHROW(ambassador.income());
    CHECK_NOTHROW(captain.income());
    CHECK_NOTHROW(contessa.income());
    CHECK_THROWS(contessa.income());
    CHECK_THROWS(ambassador.income());
    CHECK_NOTHROW(duke.income());
    CHECK_NOTHROW(assassin.income());
    CHECK_NOTHROW(ambassador.income());
    CHECK_NOTHROW(captain.income());
    CHECK_NOTHROW(contessa.income());
    CHECK_THROWS(duke.income());
    CHECK_THROWS(duke.income());
}

TEST_CASE("2. Check Coins") {
    Game game_2{};
    Duke duke{game_2, "Moshe"};
    Assassin assassin{game_2, "Yossi"};
    Ambassador ambassador{game_2, "Meirav"};
    Captain captain{game_2, "Reut"};
    Contessa contessa{game_2, "Gilad"};


    for (int i = 0; i < 10; ++i) {
        int c = i+1;
        duke.income();
        CHECK_EQ(duke.coins(),c);
        assassin.income();
        CHECK_EQ(assassin.coins(),c);
        ambassador.income();
        CHECK_EQ(ambassador.coins(),c);
        captain.income();
        CHECK_EQ(captain.coins(),c);
        contessa.income();
        CHECK_EQ(contessa.coins(),c);
    }
}

TEST_CASE("3. Check Transfer") {
    Game game_3{};
    Duke duke{game_3, "Moshe"};
    Assassin assassin{game_3, "Yossi"};
    Ambassador ambassador{game_3, "Meirav"};

    duke.income(); // 1
    assassin.income();// 1
    ambassador.income();// 1
    duke.income();// 2
    assassin.income();// 2
    ambassador.transfer(duke,assassin);
    CHECK_EQ(duke.coins(), 1); // 1
    CHECK_EQ(assassin.coins(), 3);// 3
    duke.income();// 2
    assassin.income();// 4
    ambassador.income();// 2
    duke.income();// 3
    assassin.income();// 5
    ambassador.transfer(duke,assassin);
    CHECK_EQ(duke.coins(), 2);// 2
    CHECK_EQ(assassin.coins(), 6);// 6
    duke.income();// 3
    assassin.income();// 7
    ambassador.transfer(duke,assassin);
    CHECK_EQ(duke.coins(), 2);// 2
    CHECK_EQ(assassin.coins(), 8);// 8
}

TEST_CASE("4. Check Role") {
    Game game_4{};
    Duke duke{game_4, "Moshe"};
    CHECK_EQ(duke.role(),"Duke");
    Assassin assassin{game_4, "Yossi"};
    CHECK_EQ(assassin.role(),"Assassin");
    Ambassador ambassador{game_4, "Meirav"};
    CHECK_EQ(ambassador.role(),"Ambassador");
    Captain captain{game_4, "Reut"};
    CHECK_EQ(captain.role(),"Captain");
    Contessa contessa{game_4, "Gilad"};
    CHECK_EQ(contessa.role(),"Contessa");
}

