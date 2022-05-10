/**
 * Created by talko on 4/24/22.
 */

#include "Player.hpp"
#include "Assassin.hpp"

using namespace std;

namespace coup {
    class Contessa : public Player {

    public:
        Contessa(coup::Game& g, string n) : Player(g,n,0, false) {
            player_roles = "Contessa";
            addPlayer(n);
            g.playing_queue.push_back(& *this);
        }

        string role() const override;
        string& role() override;
        void block(coup::Assassin&);
    };
}
