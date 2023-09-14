/**
 * Created by talko on 4/26/22.
 */

#include "Game.hpp"

vector<string> coup::Game::players() const {
    return this->players_names;
}

string coup::Game::turn() const {
    return players_names[i];
}

string coup::Game::winner() const {
    if (win == "playing"){
        throw invalid_argument("No Winner Yet");
    }
    return this->win;
}