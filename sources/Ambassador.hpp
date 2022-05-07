/**
 * Created by talko on 4/24/22.
 */

#include "Player.hpp"

using namespace std;

namespace coup{

    class Ambassador : public Player{

        public:
            Ambassador(coup::Game& g, string n): Player(g,n,0,false){
                player_roles = "Ambassador";
                if (g.players_names.size() < 6){
                    g.players_names.push_back(n);
                }
            }

        void transfer(Player p1, Player p2);
        void block(Player p1);

    };


}

