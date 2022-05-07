/**
 * Created by talko on 4/24/22.
 */

#include "Ambassador.hpp"

void coup::Ambassador::transfer(coup::Player p1, coup::Player p2) {
    if (game->turn() == this->name() && !this->is_dead() && !this->must_coup()){
        int price = 1;
        p1.pay(price);
        p2.coins() += price;
        this->moves().push_back(TRANSFER);
        next_turn();
    } else {
        throw invalid_argument("Wrong Player Turn");
    }
}

void coup::Ambassador::block(coup::Player p1) {
    if (game->turn() == this->name() && !this->is_dead() && !this->must_coup()){
        int price = 2;
        size_t size = p1.moves().size();
        if (p1.moves().at(size) == FOREIGN_AID || p1.moves().at(size) == STEAL){
            p1.pay(price);
        }
        this->moves().push_back(BLOCK);
        next_turn();
    } else {
        throw invalid_argument("Wrong Player Turn");
    }
}
