/**
 * Created by talko on 4/24/22.
 */

#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include <set>

using namespace std;

namespace coup{

    class Player;

    class Game {

        public:
            set<string> players_names;
            vector<Player*> playing_queue;
            unsigned long i;
            string win;

            Game(){
                win = "playing";
                i = 0;
            }

            set<string> players() const;
            string turn() const;
            string& winner();
    };
}

