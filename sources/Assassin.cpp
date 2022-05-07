//
// Created by talko on 4/24/22.
//

#include "Assassin.hpp"

void coup::Assassin::coup(coup::Player p1) {
    int price = 3;
    this->pay(price);
    if (std::find(game->players_names.begin(),game->players_names.end(),p1.name()) != game->players_names.end()) {
        p1.is_dead() = true;
        next_turn();
    } else {
        throw invalid_argument("This Player not playing_members");
    }
}

void coup::Assassin::block(coup::Player p1) {
    if (game->turn() == this->name() && !this->is_dead() && !this->must_coup()){
        int price = 7;
        p1.pay(price);
        size_t size = p1.moves().size();
        if (p1.moves().at(size) == COUP){
            cout << "all the killed players" << endl;
        }
        this->moves().push_back(BLOCK);
        next_turn();
    } else {
        throw invalid_argument("Wrong Player Turn");
    }
}
