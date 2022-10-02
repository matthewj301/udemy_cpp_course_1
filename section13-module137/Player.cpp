//
// Created by Matthew Johnson on 10/1/22.
//
#include "Player.h"

#include <utility>

void Player::set_name(std::string &local_name) {
    Player::name = local_name;
}

std::string Player::get_name() const {
    return Player::name;
}

int Player::attack() const {
    std::cout << Player::name << " attacks with " << Player::attack_str << " strength!" << std::endl;
    return Player::attack_str;
}

void Player::defend(int attack_strength) {
    Player::health -= attack_strength;
    std::cout << Player::name << " takes " << attack_strength << " worth of damage. " << std::endl;
    Player::print_health();
    Player::is_player_defeated();
}

int Player::get_health() const {
    return Player::health;
}

void Player::print_health() const {
    std::cout << Player::name << " has " << Player::get_health() << " health left!" << std::endl;
}

bool Player::is_player_defeated() const {
    if (Player::get_health() <= 0) {
        return true;
    }
    return false;
}
// Constructor initialization lists - more efficient by assigning vals on init, not after init
// Also, constructor delegation (before defaults)! Can only do this is initalization list, not body.

Player::Player(std::string name_val, int health_val, int xp)
        : name{std::move(name_val)}, health{health_val}, xp{xp}, attack_str{xp * 12} {
}

// Copier
Player::Player(const Player &source)
: name{source.name}, health{source.health}, xp{source.xp}, attack_str{source.attack_str}
{}

Player::~Player() = default;

