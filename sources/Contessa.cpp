/**
 * Created by talko on 4/24/22.
 */

#include "Contessa.hpp"

void coup::Contessa::block(coup::Assassin &p1) {
    if (!p1.is_dead()) {
        size_t size = p1.moves().size();
        if (p1.moves().at(size - 1) == ASSASSIN_ATTACK) {
            for (auto & i : p1.victims_list) {
                addBack(i);
            }
            p1.victims_list.clear();
            this->players_moves.push_back(BLOCK);
        } else {
            throw invalid_argument("Contessa Can Only Block Assassin Attack");
        }

    } else {
        throw invalid_argument("This Player is lost");
    }
}

string &coup::Contessa::role() {
    return this->player_roles;
}

string coup::Contessa::role() const {
    return this->player_roles;
}
