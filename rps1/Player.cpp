#include <utility>

/*
 * Player.cpp
 *
 *  Created on: Sep 25, 2018
 *      Author: michellenatasha
 */

#include "Player.h"

Player::Player() {
}

Player::~Player() {
    delete this;
}

selection_t Player::getRPS(){
	return RPS;
}

void Player::setRPS(selection_t type){
	RPS = type;
}

std::string Player::getName() {
    return name;
}

void Player::setName(std::string in) {
    name = std::move(in);
}