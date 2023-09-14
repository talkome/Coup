//
// Created by talko on 4/24/22.
//

#include "Ambassador.hpp"

void coup::Ambassador::transfer(coup::Player p1, coup::Player p2) {
    if (game->players_names.at(game->i) == this->name()){
        p1.pay(1);
        p2.coins() += 1;
        cout << p1.name() << " transfer to " << p2.name() << endl;
        next_turn();
    } else {
        throw invalid_argument("Wrong Player Turn");
    }
}
