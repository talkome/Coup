/**
 * Created by talko on 4/24/22.
 */

#include "Player.hpp"

using namespace std;

namespace coup{

    class Assassin : public Player{

        public:
            Assassin(coup::Game& g, string n): Player(g,n,0){
                player_roles = "Assassin";
                g.players_names.push_back(n);
            }

        void coup(Player p1);
    };
}