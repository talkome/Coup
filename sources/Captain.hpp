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
            int index = getIndex(g.players_names,n);
            g.playing_members.insert(pair<int,Player*>(index,& *this));
        }

        string role() const override;
        string& role() override;
        void steal(Player p1);
        void block(Player p1);
    };
}