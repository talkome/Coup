/**
 * Created by talko on 4/24/22.
 */

#include "Player.hpp"

using namespace std;

namespace coup {

    class Duke : public Player {

    public:
        Duke(coup::Game& g, string n) : Player(g,n,0,false) {
            player_roles = "Duke";
            addPlayer(n);
            g.playing_queue.push_back(& *this);
        }

        void tax();
        string role() const override;
        string& role() override;
        void block(Player &p1);
    };

}