/**
 * Created by talko on 4/24/22.
 */

#pragma once
#include "Player.hpp"

using namespace std;

namespace coup{

    class Assassin : public Player {

    public:
        vector<Player*> victims_list;

            Assassin(coup::Game& g, string n): Player(g,n,0, false){
                player_roles = "Assassin";
                addPlayer(n);
                g.playing_queue.push_back(& *this);
            }

        void coup(Player &p1) override;
        string role() const override;
        string& role() override;
        void block(Player &p1) override;
    };
}