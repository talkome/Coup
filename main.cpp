#include <iostream>
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"


using namespace coup;

#include <stdexcept>
#include <vector>
using namespace std;


int main() {
    Game game_1{};

    /* This player drew the "Duke" card, his name is Moshe
    and he is a player in game_1 */
    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};

    vector<string> players = game_1.players();
    vector<string> moves = {"income","foreign_aid","block","coup"};
    vector<string> captain_moves = {"steal"};
    vector<string> ambassador_moves = {"transfer"};
    vector<string> duke_moves = {"tax"};

    while (!game_1.game_over){
        unsigned long num;
        unsigned long victim_num,victim2;
        cout << "Welcome to the game" << endl
             << "current player name: " << game_1.turn() << endl
             << "status:" << endl;

        for (unsigned long i = 0; i < game_1.playing_queue.size(); ++i) {
            cout << game_1.playing_queue[i]->name() << ": " << game_1.playing_queue[i]->coins() << "$" << endl;
        }

        cout << "Choose Your Desired Move: " << endl
             << "0. " << moves[0] << endl
             << "1. " << moves[1] <<  endl
             << "2. " << moves[2] <<  endl
             << "3. " << moves[3] <<  endl;
        if (game_1.playing_queue[game_1.i]->role() == "Captain"){
            cout << "4. " << captain_moves[0] <<  endl;
        } else if (game_1.playing_queue[game_1.i]->role() == "Ambassador"){
            cout << "4. " << ambassador_moves[0] <<  endl;
        } else if (game_1.playing_queue[game_1.i]->role() == "Duke"){
            cout << "4. " << duke_moves[0] <<  endl;
        }
        cin >> num;

        if (game_1.playing_queue[game_1.i]->role() == "Captain" && num == 4){
            cout << "Choose victim" << endl;
            int j = 0;
            for (unsigned long i = 0; i < game_1.playing_queue.size(); ++i) {
                if (game_1.playing_queue[i]->name() != game_1.turn()){
                    cout << j << ". " << game_1.playing_queue[i]->name() << endl;
                    j++;
                }
            }
            cin >> victim_num;
            captain.steal(*game_1.playing_queue[victim_num]); // steal
            cout <<  game_1.playing_queue[game_1.i]->name() << " is " << captain_moves[0] << endl;
        }

        if (game_1.playing_queue[game_1.i]->role() == "Ambassador" && num == 4){
            cout << "Choose victim" << endl;
            int j = 0;
            for (unsigned long i = 0; i < game_1.playing_queue.size(); ++i) {
                if (game_1.playing_queue[i]->name() != game_1.turn()){
                    cout << j << ". " << game_1.playing_queue[i]->name() << endl;
                    j++;
                }
            }
            cin >> victim_num>> victim2;
            ambassador.transfer(*game_1.playing_queue[victim_num],*game_1.playing_queue[victim2]); // transfer
            cout <<  game_1.playing_queue[game_1.i]->name() << " is " << ambassador_moves[0] << endl;
        }

        if (game_1.playing_queue[game_1.i]->role() == "Duke" && num == 4){
            cout << "Choose victim" << endl;
            int j = 0;
            for (unsigned long i = 0; i < game_1.playing_queue.size(); ++i) {
                if (game_1.playing_queue[i]->name() != game_1.turn()){
                    cout << j << ". " << game_1.playing_queue[i]->name() << endl;
                    j++;
                }

            }
            cin >> victim_num;
            duke.tax(); // tax
            cout <<  game_1.playing_queue[game_1.i]->name() << " is " << duke_moves[0] << endl;
        }

        if (num == 3){
            cout << "Choose victim" << endl;
            int j = 0;
            for (unsigned long i = 0; i < game_1.playing_queue.size(); ++i) {
                if (game_1.playing_queue[i]->name() != game_1.turn()){
                    cout << j << ". " << game_1.playing_queue[i]->name() << endl;
                    j++;
                }
            }
            cin >> victim_num;
        }


        switch (num) {
            case 0:
                game_1.playing_queue[game_1.i]->income();
                cout <<  game_1.playing_queue[game_1.i]->name() << " is " << moves[0] << endl;
                break;

            case 1:
                game_1.playing_queue[game_1.i]->foreign_aid();
                cout << game_1.playing_queue[game_1.i]->name() << " is " << moves[1] << endl;
                break;

            case 2:
                game_1.playing_queue[game_1.i]->block(*game_1.playing_queue[victim_num]);
                cout << game_1.playing_queue[game_1.i]->name() << " is " << moves[2] << game_1.playing_queue[victim_num] << endl;
                break;

            case 3:
                game_1.playing_queue[game_1.i]->coup(*game_1.playing_queue[victim_num]);
                cout << game_1.playing_queue[game_1.i]->name() << " is " << moves[1] << game_1.playing_queue[victim_num] << endl;
                break;

            default:
                throw invalid_argument("Invalid Move");
        }
    }
}
