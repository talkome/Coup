/**
 * Created by talko on 4/26/22.
 */

#include "Game.hpp"

map<int,coup::Player*> coup::Game::players() const {
    return this->playing_members;
}

string coup::Game::turn() const {
    return this->playing_members.at(i)->name();
}

string coup::Game::winner() const {
    if (win == "playing"){
        throw invalid_argument("No Winner Yet");
    }
    return this->win;
}


