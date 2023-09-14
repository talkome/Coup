//
// Created by talko on 4/24/22.
//

#include "Assassin.hpp"

void coup::Assassin::coup(coup::Player p1) {
    this->pay(3);
    if (std::find(game->players_names.begin(), game->players_names.end(), p1.name()) != game->players_names.end()) {
        game->players_names.erase(remove(game->players_names.begin(), game->players_names.end(), p1.name()), game->players_names.end());
        cout << p1.name() << " as removed" << endl;
        next_turn();
    } else {
        throw invalid_argument("This Player not playing");
    }
}
