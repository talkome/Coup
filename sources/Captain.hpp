/**
 * Created by talko on 4/24/22.
 */

#include "Player.hpp"

using namespace std;

namespace coup {

    class Captain : public Player {

    public:
        Captain(coup::Game& g, string n) : Player(g,n,0,false) {
            player_roles = "Captain";
            addPlayer(n);
            g.playing_queue.push_back(& *this);
        }

        string role() const override;
        string& role() override;
        void steal(Player &p1);
        void block(Player &p1) override;
    };
}