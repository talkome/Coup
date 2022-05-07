/**
 * Created by talko on 4/24/22.
 */

#include "Player.hpp"

using namespace std;

void coup::Player::pay(int num) {
    if (this->coins() >= num){
        this->coins() -= num;
    } else {
        throw invalid_argument("This Player Cannot Pay");
    }
}

void coup::Player::next_turn() {
    size_t size = game->players_names.size();
    game->i++;
    if (game->i >= game->players_names.size()){
        game->i = game->i % size;
    }
}

void coup::Player::income() {
    if (game->turn() == this->name()){
        this->coins()++;
        this->players_moves.push_back(INCOME);
        if (this->coins() >= 10){
            mustCoup = true;
        }
        next_turn();
    } else {
        throw invalid_argument("Wrong Player Turn");
    }
}

void coup::Player::foreign_aid() {
    if (game->turn() == this->name()){
        int price = 2;
        this->coins() += price;
        this->players_moves.push_back(FOREIGN_AID);
        if (this->coins() >= 10){
            mustCoup = true;
        }
        next_turn();
    } else {
        throw invalid_argument("Wrong Player Turn");
    }
}

void coup::Player::coup(coup::Player p1) {
    if (std::find(game->players_names.begin(), game->players_names.end(), p1.name()) != game->players_names.end()) {
        int price = 7;
        this->pay(price);
        p1.isDead = true;
        this->players_moves.push_back(COUP);
        cout << p1.name() << " as removed" << endl;
        next_turn();
    } else {
        throw invalid_argument("This Player not playing_members");
    }
}

int coup::Player::coins() const {
    return this->curr_coins;
}

int &coup::Player::coins() {
    return this->curr_coins;
}

string coup::Player::role() const {
    return this->player_roles;
}

string& coup::Player::role() {
    return this->player_roles;
}

string coup::Player::name() const{
    return this->player_name;
}

string &coup::Player::name() {
    return this->player_name;
}

bool coup::Player::is_dead() const {
    return this->isDead;
}

bool &coup::Player::is_dead() {
    return this->isDead;
}

bool coup::Player::must_coup() const {
    return this->mustCoup;
}

bool &coup::Player::must_coup() {
    return this->mustCoup;
}

vector<coup::MOVES> coup::Player::moves(){
    return this->players_moves;
}
