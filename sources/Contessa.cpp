/**
 * Created by talko on 4/24/22.
 */

#include "Contessa.hpp"

void coup::Contessa::block(coup::Player p1) {
    if (game->turn() == this->name() && !this->is_dead() && !this->must_coup()){
        int price = 2;
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
