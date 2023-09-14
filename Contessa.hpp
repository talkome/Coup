/**
 * Created by talko on 4/24/22.
 */

#include "Player.hpp"

using namespace std;

namespace coup {

    class Contessa : public Player {

    public:
        Contessa(coup::Game& g, string n) : Player(g,n,0) {
            player_roles = "Contessa";
            g.players_names.push_back(n);
        }

        void block(Player p1);
    };
}
