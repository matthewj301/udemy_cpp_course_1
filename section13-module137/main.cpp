#include <iostream>
#include <vector>
#include "Player.h"
using namespace std;

// classes! Which turned into making a little game
void print_players(std::vector<Player> &);

int main() {
    string p1 {"Katie"};
    string p2 {"Roomba"};
    Player matthew {&p1};
    Player enemy {&p2};

    vector<Player> all_players{matthew, enemy};
    if (all_players.size() < 2) {
        cout << "This game is restricted to 2 players for now..." << endl;
        exit(1);
    }

    print_players(all_players);

    cout << "The battle between " << matthew.get_name() << " and " << enemy.get_name() << " begins..." << endl;
    enemy.defend(matthew.attack());


    while (!all_players.at(0).is_player_defeated() && !all_players.at(1).is_player_defeated()) {
        int random_attacker = rand() % all_players.size();
        int defender{1};
        if (random_attacker == all_players.size()) {
            defender = 0;
        }
        all_players.at(defender).defend(all_players.at(random_attacker).attack());
    }
    Player defeated_player;

    if (all_players.at(0).is_player_defeated()) {
        defeated_player = all_players.at(0);
    } else {
        defeated_player = all_players.at(1);
    }

    string defeat_msg = "And it looks like " + defeated_player.get_name() + " has been defeated";
    if (defeated_player.get_health() < 0) {
        defeat_msg += " With overkill!!";
    } else {
        defeat_msg += "!";
    }
    std::cout << defeat_msg << std::endl;


    return 0;
}

void print_players(vector<Player> &all_players) {
    cout << "The current players are... " << endl;
    for (auto const &player: all_players) {
        cout << "-" << player.get_name() << endl;
    }
    cout << endl;
}