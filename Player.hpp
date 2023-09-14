/**
 * Created by talko on 4/24/22.
 */

#include "Game.hpp"
#include <iostream>

#ifndef MY_SYMBOL_H
#define MY_SYMBOL_H

using namespace std;

namespace coup{

    class Player {

    protected:
        Game* game;
        string player_name;
        string player_roles;
        int curr_coins;

    public:
        // Constructor
        Player(Game& g, string name){
            game = &g;
            player_name = name;
            curr_coins = 0;
            player_roles = "Player";
        }

        Player(Game& g, string name, int c){
            game = &g;
            player_name = name;
            curr_coins = c;
            player_roles = "Player";
        }

        // Destructor
        ~Player()= default;

        void income();
        void foreign_aid();
        void coup(Player p1);
        void next_turn();

        string name() const;
        string& name();

        int coins() const;
        int& coins();

        string role() const;
        string& role();

        void pay(int);

    };
}

#endif


