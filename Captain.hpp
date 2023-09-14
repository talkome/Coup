/**
 * Created by talko on 4/24/22.
 */

#include "Player.hpp"

using namespace std;

namespace coup {

    class Captain : public Player {

    public:
        Captain(coup::Game& g, string n) : Player(g,n,0) {
            player_roles = "Captain";
            g.players_names.push_back(n);
        }

        void steal(Player p1);
        void block(Player p1);
    };
}