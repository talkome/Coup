/**
 * Created by talko on 4/24/22.
 */

#pragma once
#include <iostream>
#include "Game.hpp"

using namespace std;

namespace coup{

    enum MOVES { INCOME = 1, FOREIGN_AID = 2, COUP = 3, TAX = 4, BLOCK = 5, TRANSFER = 6, STEAL_FIRST_PRICE = 7,
            ASSASSIN_ATTACK = 8, STEAL_SECOND_PRICE = 9 };

    class Game;

    class Player {

    protected:
        Game* game;
        string player_name;
        string player_roles;
        vector<MOVES> players_moves;

        bool isDead;
        bool mustCoup;
        int curr_coins;

    public:
        vector<Player*> victims_list;
        Player* robbed;

        // Constructor
        Player(Game& g, string name){
            game = &g;
            player_name = name;
            curr_coins = 0;
            player_roles = "Player";
            isDead = false;
            mustCoup = false;
        }

        Player(Game& g, string name, int c, bool state){
            game = &g;
            player_name = name;
            curr_coins = c;
            isDead = state;
            mustCoup = false;
            player_roles = "Player";
        }

        // Destructor
        ~Player()= default;

        void income();
        void foreign_aid();
        virtual void coup(Player &p1);

        void next_turn();
        void pay(int);
        void get_paid(int);

        virtual void block(Player &p1) = 0;

        vector<MOVES>& moves();

        string name() const;
        string& name();

        bool is_dead() const;
        bool& is_dead();

        int coins() const;
        int& coins();

        bool must_coup() const;
        bool& must_coup();

        virtual string role() const;
        virtual string& role();

        void addBack(Player*);
        void addPlayer(string const &);

    };
}