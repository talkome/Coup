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
    if (this->name() == game->players_names.at(game->i)){
        this->coins()++;
        next_turn();
    } else {
        throw invalid_argument("Wrong Player Turn");
    }
}

void coup::Player::foreign_aid() {
    if (game->players_names.at(game->i) == this->name()){
        this->coins() += 2;
        next_turn();
    } else {
        throw invalid_argument("Wrong Player Turn");
    }
}

void coup::Player::coup(coup::Player p1) {
    this->pay(7);
    if (std::find(game->players_names.begin(), game->players_names.end(), p1.name()) != game->players_names.end()) {
        game->players_names.erase(remove(game->players_names.begin(), game->players_names.end(), p1.name()), game->players_names.end());
        cout << p1.name() << " as removed" << endl;
        next_turn();
    } else {
        throw invalid_argument("This Player not playing");
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
