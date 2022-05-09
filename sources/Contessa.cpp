/**
 * Created by talko on 4/24/22.
 */

#include "Contessa.hpp"

void coup::Contessa::block(coup::Assassin a1) {
    if (game->turn() == this->name() && !this->is_dead() && !this->must_coup()){
        int price = 2;
        a1.pay(price);
        size_t size = a1.moves().size();
        if (a1.moves().at(size) == COUP){
            for (int i = 0; i < a1.victim().size(); ++i) {
                addBack(a1.victim()[i]);
            }
        }
        this->moves().push_back(BLOCK);
        next_turn();
    } else {
        throw invalid_argument("Wrong Player Turn");
    }
}

string &coup::Contessa::role() {
    return this->player_roles;
}

string coup::Contessa::role() const {
    return this->player_roles;
}
