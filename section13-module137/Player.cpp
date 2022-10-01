//
// Created by Matthew Johnson on 10/1/22.
//
#include "Player.h"


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

Player::Player() {
    std::cout << "default settings" << std::endl;
}

Player::Player(std::string *name) {
    Player::set_name(*name);
}

Player::~Player() = default;

