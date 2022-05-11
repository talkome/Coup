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

void coup::Player::get_paid(int num) {
    this->coins() += num;
    const int max_coins = 10;
    if (this->coins() >= max_coins){
        this->must_coup() = true;
    }
}

void coup::Player::next_turn() {
    size_t size = game->playing_queue.size();
    this->game->playing = true;
    if (!this->game->is_over()){
        game->i++;
        if (game->i >= size) {
            game->i = game->i % size;
        }

        while (game->playing_queue[game->i]->is_dead()){
            game->i++;
            if (game->i >= size) {
                game->i = game->i % size;
            }
        }
    }
}

void coup::Player::income() {
    if(this->game->players_names.size() == 1){
        throw invalid_argument("The game must contain at least 2 players");
    }
    if(this->must_coup()){
        throw invalid_argument("You are required to make a coup");
    }
    if (game->turn() == this->name()){
        this->game->playing = true;
        const int price = 1;
        this->get_paid(price);
        this->players_moves.push_back(INCOME);
        next_turn();
    } else {
        throw invalid_argument("Wrong Player Turn");
    }
}

void coup::Player::foreign_aid() {
    if(this->game->players_names.size() == 1){
        throw invalid_argument("The game must contain at least 2 players");
    }
    if (this->must_coup()){
        throw invalid_argument("You are required to make a coup");
    }
    if (game->turn() == this->name()){
        const int price = 2;
        this->get_paid(price);
        this->players_moves.push_back(FOREIGN_AID);
        next_turn();
    } else {
        throw invalid_argument("Wrong Player Turn");
    }
}

void coup::Player::coup(coup::Player &p1) {
    if (!p1.is_dead()) {
        const int price = 7;
        this->pay(price);
        p1.is_dead() = true;
        this->game->players_names.erase(remove(this->game->players_names.begin(), this->game->players_names.end(), p1.name()), this->game->players_names.end());
        this->players_moves.push_back(COUP);
        this->must_coup() = false;
        next_turn();
    } else {
        throw invalid_argument("This Player not playing_queue");
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

void coup::Player::addBack(Player* p) {
    p->is_dead() = false;
    vector<string> new_players_name;
    for (auto & player : this->game->playing_queue) {
        if (!player->is_dead()){
            new_players_name.push_back(player->name());
        }
    }
    this->game->players_names = new_players_name;
}

void coup::Player::addPlayer(string const &p_name) {
    if (this->game->playing){
        throw invalid_argument("No new players can be added after the game has started");
    }
    if (this->game->is_over()){
        throw invalid_argument("No new players can be added after the game has started");
    }
    const int max_player = 6;
    if (this->game->players_names.size() < max_player) {
        this->game->players_names.push_back(p_name);
    } else {
        throw invalid_argument("Invalid number of players");
    }
}
