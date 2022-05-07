/**
 * Created by talko on 4/24/22.
 */

#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include "Player.hpp"

using namespace std;

namespace coup{

    class Player;

    class Game {

        public:
            vector<string> players_names;
            vector<Player*> playing_members;
            unsigned long i;

            string win;

            Game(){
                win = "playing";
                i = 0;
            }

            vector<string> players() const;
            string turn() const;
            string winner() const;
    };
}

