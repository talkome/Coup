/**
 * Created by talko on 4/26/22.
 */

#include "Game.hpp"
#include "Player.hpp"

set<string> coup::Game::players() const {
    return this->players_names;
}

string coup::Game::turn() const {
    Player* selected = this->playing_queue[i];
    return selected->name();
}

string& coup::Game::winner() {
    if (this->players_names.size() == 1){
        for (int j = 0; j < this->playing_queue.size(); ++j) {
            if (!playing_queue[j]->is_dead()){
                win = playing_queue[j]->name();
            }
        }
    } else {
        throw invalid_argument("No Winner Yet");
    }
    return win;
}



