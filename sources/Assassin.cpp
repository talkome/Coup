//
// Created by talko on 4/24/22.
//

#include "Assassin.hpp"

void coup::Assassin::coup(coup::Player p1) {
    if (std::find(game->players_names.begin(),game->players_names.end(),p1.name()) != game->players_names.end()) {
        int price = 3;
        this->pay(price);
        p1.is_dead() = true;
        this->game->playing_members.erase(getIndex(this->game->players_names,p1.name()));
        this->players_moves.push_back(COUP);
        this->victim().push_back(&p1);
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
            for (int i = 0; i < this->victim().size(); ++i) {
                addBack(victim()[i]);
            }
        }
        this->moves().push_back(BLOCK);
        next_turn();
    } else {
        throw invalid_argument("Wrong Player Turn");
    }
}

string coup::Assassin::role() const {
    return this->player_roles;
}

string &coup::Assassin::role() {
    return this->player_roles;
}

vector<coup::Player*> coup::Assassin::victim() {
    return this->victims_list;
}
