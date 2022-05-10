/**
 * Created by talko on 4/24/22.
 */

#include "Captain.hpp"

void coup::Captain::steal(coup::Player p1) { // TODO: check
    if (game->turn() == this->name() && !this->must_coup()){
        const int price = 1;
        this->coins() += price;
        p1.pay(price);
        this->moves().push_back(STEAL);
        next_turn();
    } else {
        throw invalid_argument("Wrong Player Turn");
    }
}

void coup::Captain::block(coup::Player &p1) {
    if (game->turn() == this->name() && !this->must_coup()){
        if (p1.is_dead()){
            throw invalid_argument("This Player is lost");
        }
        if (p1.role() == "Captain"){
            const int price = 2;
            p1.pay(price);
            size_t size = p1.moves().size();
            if (p1.moves().at(size) == STEAL){
                p1.pay(price);
            }
            this->moves().push_back(BLOCK);
            next_turn();
        } else {
            throw invalid_argument("You Can Only Block Captain");
        }

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
