/*
 * Player.cpp
 *
 *  Created on: Sep 25, 2018
 *      Author: michellenatasha
 */

#include "Player.h"

Player::Player() {
	// TODO Auto-generated constructor stub

}

Player::~Player() {
	// TODO Auto-generated destructor stub
}

selection_t Player::getRPS(){
	return RPS;
}

void Player::setRPS(selection_t type){
	RPS = type;
}
