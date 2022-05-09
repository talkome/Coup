/**
 * Created by talko on 4/24/22.
 */

#include "Player.hpp"

using namespace std;

namespace coup{

    class Assassin : public Player{
        vector<Player*> victims_list;

    public:
            Assassin(coup::Game& g, string n): Player(g,n,0, false){
                player_roles = "Assassin";
                addPlayer(n);
                int index = getIndex(g.players_names,n);
                g.playing_members.insert(pair<int,Player*>(index,& *this));
            }

        void coup(Player p1) override;
        string role() const override;
        string& role() override;
        void block(Player p1);
        vector<Player*> victim();
    };
}