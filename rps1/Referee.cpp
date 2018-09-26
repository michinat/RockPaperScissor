/*
 * Referee.cpp
 *
 *  Created on: Sep 25, 2018
 *      Author: michellenatasha
 */

#include "Referee.h"


Referee::Referee() {
	// TODO Auto-generated constructor stub
	CPUScore = 0;
	HumanScore = 0;

}

Referee::~Referee() {
	// TODO Auto-generated destructor stub
}

void Referee::compareRPS(selection_t human, selection_t cpu){
	Human = human;
	CPU = cpu;

	if (Human == selection_t::ROCK) {
		// if draw, add 1 to cpuScore and humanScore
		if (CPU == selection_t::ROCK){
			CPUScore++;
			HumanScore++;
		}
		else if (CPU == selection_t::PAPER){
			CPUScore++;
		}
		else
		{
			HumanScore++;
		}
	}
	else if (Human == selection_t::PAPER){
		if (CPU == selection_t::ROCK){
			HumanScore++;
		}
		else if (CPU == selection_t::PAPER){
			CPUScore++;
			HumanScore++;
		}
		else{
			CPUScore++;
		}
	}
	else{
		if(CPUScore == selection_t::PAPER){
			HumanScore++;
		}
		else if (CPUScore == selection_t::ROCK){
			CPUScore++;
		}
		else
		{
			CPUScore++;
			HumanScore++;
		}
	}

}

void Referee::displayRoundWinner(){
	if(CPUScore > HumanScore)
		std::cout << "Computer wins\n";
	else
		std::cout << "Human wins\n";
}

void Referee::newRound(Player * human, Player * cpu){
	std::cout << "Score\n Human: " << HumanScore;
	std::cout << " CPU: " << CPUScore << std::endl;
	NotifySelection(human);
	NotifySelection(cpu);

	compareRPS(human->getRPS(), cpu->getRPS());
}

void Referee::endRound(){
	if (currentRound == MAX_GAME)
	{
		displayRoundWinner();
	}
}

void Referee::NotifySelection(Player * player){
	player->setRPS()
}
