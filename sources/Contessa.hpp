/**
 * Created by talko on 4/24/22.
 */

#pragma once
#include "Player.hpp"
#include "Assassin.hpp"

using namespace std;

namespace coup {

    class Contessa : public Player {

    public:
        Contessa(coup::Game& g, string n) : Player(g,n,0, false) {
            player_roles = "Contessa";
            addPlayer(n);
            int index = getIndex(g.players_names,n);
            g.playing_members.insert(pair<int,Player*>(index,& *this));
        }

        string role() const override;
        string& role() override;
        void block(Assassin a1);
    };
}
