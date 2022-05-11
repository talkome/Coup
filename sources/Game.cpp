/**
 * Created by talko on 4/26/22.
 */

#include "Game.hpp"
#include "Player.hpp"

vector<string> coup::Game::players() const{
    return this->players_names;
}

string coup::Game::turn() {
    Player* selected = this->playing_queue[i];
    return selected->name();
}

string& coup::Game::winner() {
    if(this->playing){
        throw invalid_argument("There is no winner at the moment the game is still running");
    }
    if (!this->game_over) {
        throw invalid_argument("No winner at the moment The game is not over yet");
    }
    for (size_t j = 0; j < this->playing_queue.size(); ++j) {
        if (!playing_queue[j]->is_dead()) {
            win = playing_queue[j]->name();
        }
    }
    return win;

}

bool& coup::Game::is_over() {
    if (this->players_names.size() == 1 && this->playing){
        int count = 0;
        for (size_t j = 0; j < this->playing_queue.size(); ++j) {
            if (!playing_queue[j]->is_dead()){
                count++;
            }
        }
        if (count == 1){
            this->playing = false;
            this->game_over = true;
        }
    }
    return this->game_over;

}



