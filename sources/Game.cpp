/**
 * Created by talko on 4/26/22.
 */

#include "Game.hpp"
#include "Player.hpp"

vector<string> coup::Game::players() {
    return this->players_names;
}

string coup::Game::turn() {
    Player* selected = this->playing_queue[i];
    return selected->name();
}

string& coup::Game::winner() {
    if (this->players_names.size() == 1 && this->begin){
        for (size_t j = 0; j < this->playing_queue.size(); ++j) {
            if (!playing_queue[j]->is_dead()){
                win = playing_queue[j]->name();
            }
        }
        return win;
    } else {
        throw invalid_argument("No Winner Yet");
    }
}



