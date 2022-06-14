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
                addPlayer(n);
                g.playing_queue.push_back(& *this);
            }

        void transfer(Player &p1, Player &p2);
        void block(Player &p1) override;
    };
}

