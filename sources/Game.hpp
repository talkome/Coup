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
            vector<string> players_names;
            vector<Player*> playing_queue;
            unsigned long i;
            string win;
            bool playing;
            bool game_over;

            Game(){
                win = "playing";
                playing = false;
                game_over = false;
                i = 0;
            }

            vector<string> players();
            string turn();
            string& winner();
            bool& is_over();
    };
}

