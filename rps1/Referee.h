/*
 * Referee.h
 *
 *  Created on: Sep 25, 2018
 *      Author: michellenatasha
 */

#ifndef REFEREE_H_
#define REFEREE_H_
#include "Player.h"
#include <iostream>

class Referee {
private:
	selection_t CPU, Human;
	int currentRound, MAX_GAME, CPUScore, HumanScore;
public:
	Referee();
	virtual ~Referee();
	void compareRPS(selection_t human, selection_t cpu);
	void displayRoundWinner();
	void newRound(Player *human, Player *cpu);
	void endRound();
	void NotifySelection(Player * player);
};

#endif /* REFEREE_H_ */
