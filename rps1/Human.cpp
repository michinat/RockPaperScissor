/*
 * Human.cpp
 *
 *  Created on: Sep 25, 2018
 *      Author: michellenatasha
 */

#include "Human.h"

Human::Human() {
    setName("Human");
}

Human::~Human() {
	delete this;
}

void Human::makeRPSChoice() {
    selection_t hold;
	std::cout << "Enter your selection: Rock, Paper, or Scissor\n";
	std::cin >> hold;

	setRPS(hold);
}
