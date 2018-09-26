//
// Created by drnuc on 9/26/2018.
//
#include "Referee.h"
#include "Human.h"
#include "CPU.h"

int main() {
    // players are subject to change
    Player * player1 = new Human();
    Player * player2 = new CPU();
    Referee * referee = new Referee();

    while (!referee->endGame()) {
        referee->newRound(player1, player2);
    }

    referee->displayRoundWinner(player1, player2);

    delete referee;
    delete player1;
    delete player2;
}