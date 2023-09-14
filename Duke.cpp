/**
 * Created by talko on 4/24/22.
 */

#include "Duke.hpp"

void coup::Duke::tax() {
    if (game->players_names.at(game->i) == this->name()){
        this->coins() += 3;
        next_turn();
    } else {
        throw invalid_argument("Wrong Player Turn");
    }

}

void coup::Duke::block(coup::Player p1) {
    cout << "blocking" << endl;
}
