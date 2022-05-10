/**
 * Created by talko on 4/24/22.
 */

#include "Ambassador.hpp"
#define TRANSFER_PRICE
#define BLOCK_PRICE

void coup::Ambassador::transfer(coup::Player const &p1, coup::Player const &p2) {
    if (game->turn() == this->name() && !this->is_dead() && !this->must_coup()){
        p1.pay(TRANSFER_PRICE);
        p2.coins() += TRANSFER_PRICE;
        this->moves().push_back(TRANSFER);
        next_turn();
    } else {
        throw invalid_argument("Wrong Player Turn");
    }
}

void coup::Ambassador::block(coup::Player &p1) {
    if (game->turn() == this->name() && !this->is_dead() && !this->must_coup()){
        size_t size = p1.moves().size();
        if (p1.moves().at(size) == FOREIGN_AID || p1.moves().at(size) == STEAL){
            p1.pay(BLOCK_PRICE);
        }
        this->moves().push_back(BLOCK);
        next_turn();
    } else {
        throw invalid_argument("Wrong Player Turn");
    }
}
