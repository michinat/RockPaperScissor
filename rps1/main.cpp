/**
 * RPS main driver
 */

#include "Referee.h"
#include "Human.h"
#include "CPU.h"

int main() {
    // players RPS methods are subject to change
    Player * player1 = new Human(Human::COMMAND_LINE);
    Player * player2 = new CPU(CPU::SMART);
    Referee * referee = new Referee();

    while (!referee->endGame()) {
        referee->newRound(player1, player2);
    }

    referee->displayRoundWinner(player1, player2);

    delete referee;
    delete player1;
    delete player2;
}
