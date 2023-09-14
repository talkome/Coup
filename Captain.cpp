/**
 * Created by talko on 4/24/22.
 */

#include "Captain.hpp"

void coup::Captain::steal(coup::Player p1) {
    if (game->players_names.at(game->i) == this->name()){
        if (p1.role() != "Captain" || p1.role() != "Ambassador"){
            this->coins() += 2;
            p1.pay(2);
            cout << this->name() <<  " steal from " << p1.name() << endl;
        }
        next_turn();
    } else {
        throw invalid_argument("Wrong Player Turn");
    }
}

void coup::Captain::block(coup::Player p1) {
    if (game->players_names.at(game->i) == this->name()){
        p1.pay(2);
        next_turn();
    } else {
        throw invalid_argument("Wrong Player Turn");
    }
}
