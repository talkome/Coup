/**
 * Created by talko on 4/24/22.
 */

#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

#ifndef MY_SYMBOL_HH
#define MY_SYMBOL_HH

namespace coup{

    class Game {

        public:
            vector<string> players_names;
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

#endif

