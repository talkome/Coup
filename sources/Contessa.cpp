/**
 * Created by talko on 4/24/22.
 */

#include "Contessa.hpp"

void coup::Contessa::block(coup::Assassin &p1) {
    if (!this->must_coup()) {
        size_t size = p1.moves().size();
        if (p1.moves().at(size - 1) == COUP) {
            for (auto & i : p1.victims_list) {
                addBack(i);
            }
            p1.victims_list.clear();
        }
        this->moves().push_back(BLOCK);
    }
}

string &coup::Contessa::role() {
    return this->player_roles;
}

string coup::Contessa::role() const {
    return this->player_roles;
}
