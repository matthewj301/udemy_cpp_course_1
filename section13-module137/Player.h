//
// Created by Matthew Johnson on 9/30/22.
//
#ifndef UDEMY_CPP_COURSE_1_PLAYER_H
#define UDEMY_CPP_COURSE_1_PLAYER_H
#include <string>
#include <vector>
#include <iostream>

class Player {
public:
    // Constructor with default params
    Player(std::string name_val = "None", int health_val = 100 , int xp_val = 1);
    // destructor
    ~Player();
    // copiers
    Player(const Player &source);
    // methods
    void set_name(std::string &);
    std::string get_name() const;
    int attack() const;
    void defend(int attack_strength);
    int get_health() const;
    bool is_player_defeated() const;
    void print_health() const;

private:
    // attrs
    std::string name;
    int health;
    int xp;
    int attack_str;
};

#endif //UDEMY_CPP_COURSE_1_PLAYER_H
