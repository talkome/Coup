/**
 * Created by talko on 4/24/22.
 */

#include "Captain.hpp"

void coup::Captain::steal(coup::Player p1) {
    if (game->turn() == this->name() && !this->is_dead() && !this->must_coup()){
        if (p1.role() != "Captain" || p1.role() != "Ambassador"){
            int price = 2;
            this->coins() += price;
            p1.pay(price);
        }
        this->moves().push_back(STEAL);
        next_turn();
    } else {
        throw invalid_argument("Wrong Player Turn");
    }
}

void coup::Captain::block(coup::Player p1) {
    if (game->turn() == this->name() && !this->is_dead() && !this->must_coup()){
        int price = 2;
        p1.pay(price);
        size_t size = p1.moves().size();
        if (p1.moves().at(size) == STEAL){
            p1.pay(price);
        }
        this->moves().push_back(BLOCK);
        next_turn();
    } else {
        throw invalid_argument("Wrong Player Turn");
    }
}

string coup::Captain::role() const {
    return this->player_roles;
}

string &coup::Captain::role() {
    return this->player_roles;
}
