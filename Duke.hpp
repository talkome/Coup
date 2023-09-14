/**
 * Created by talko on 4/24/22.
 */

#include "Player.hpp"

using namespace std;

namespace coup {

    class Duke : public Player {

    public:
        Duke(coup::Game& g, string n) : Player(g,n,0) {
            player_roles = "Duke";
            g.players_names.push_back(n);
        }

        void tax();
        void block(Player p1);
    };

}