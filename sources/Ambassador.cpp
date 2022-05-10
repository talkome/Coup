/**
 * Created by talko on 4/24/22.
 */

#include "Ambassador.hpp"

void coup::Ambassador::transfer(coup::Player &p1, coup::Player &p2) {
    if (game->turn() == this->name() && !this->is_dead() && !this->must_coup()){
        if(!p1.is_dead() && !p2.is_dead()){
            const int price = 1;
            p1.pay(price);
            p2.coins() += price;
            this->moves().push_back(TRANSFER);
            next_turn();
        } else {
            throw invalid_argument("This Players lost");
        }

    } else {
        throw invalid_argument("Wrong Player Turn");
    }
}

void coup::Ambassador::block(coup::Player &p1) {
    if (game->turn() == this->name() && !this->is_dead() && !this->must_coup()){
        if (p1.role() == "Captain"){
            size_t size = p1.moves().size();
            const int price = 2;
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
