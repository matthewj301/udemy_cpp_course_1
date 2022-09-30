#include <iostream>
#include <vector>
#include <string>
using namespace std;

// classes! Which turned into making a little game

bool someone_is_defeated = false;

class Player {
public:
    // methods
    void set_name(string &);
    string get_name() const;
    int attack() const;
    void defend(int attack_strength);
    int get_health() const;
    bool is_player_defeated() const;
    void print_health() const;

private:
    // attrs
    string name;
    int health {100};
    int xp {1};
    int attack_str {xp*12};
};

void Player::set_name(string &local_name) {
    Player::name = local_name;
}

string Player::get_name() const {
    return Player::name;
}

int Player::attack() const {
    cout << Player::name << " attacks with " << Player::attack_str << " strength!" << endl;
    return Player::attack_str;
}

void Player::defend(int attack_strength) {
    Player::health -= attack_strength;
    cout << Player::name << " takes " << attack_strength << " worth of damage. " << endl;
    Player::print_health();
    Player::is_player_defeated();
}

int Player::get_health() const {
    return Player::health;
}

void Player::print_health() const {
    cout << Player::name << " has " << Player::get_health() << " health left!" << endl;
}

bool Player::is_player_defeated() const {
    if (Player::get_health() <= 0) {
        string defeat_msg = "And it looks like " + Player::name + " has been defeated";
        someone_is_defeated = true;
        if (Player::get_health() < 0) {
            defeat_msg += " With overkill!!";
        } else {
            defeat_msg += "!";
        }
        cout << defeat_msg << endl;
        return true;
    }
    return false;
}

void print_players(vector<Player> &);

int main() {
    Player matthew;
    Player enemy;
    string p1 {"Katie"};
    string p2 {"Roomba"};

    matthew.set_name(p1);
    enemy.set_name(p2);

    vector<Player> all_players{matthew, enemy};
    if (all_players.size() < 2) {
        cout << "This game is restricted to 2 players for now..." << endl;
        exit(1);
    }

    print_players(all_players);

    cout << "The battle between " << matthew.get_name() << " and " << enemy.get_name() << " begins..." << endl;
    enemy.defend(matthew.attack());

    while (!someone_is_defeated) {
        int random_attacker = rand() % all_players.size();
        int defender{1};
        if (random_attacker == all_players.size()) {
            defender = 0;
        }
        all_players.at(defender).defend(all_players.at(random_attacker).attack());
    }

    return 0;
}

void print_players(vector<Player> &all_players) {
    cout << "The current players are... " << endl;
    for (auto const &player: all_players) {
        cout << "-" << player.get_name() << endl;
    }
    cout << endl;
}