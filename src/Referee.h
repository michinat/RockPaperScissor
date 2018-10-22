/**
 * Referee base class
 *
 */

#ifndef REFEREE_H_
#define REFEREE_H_

#include "Player.h"

class Referee {
private:
    selection_t player1Selection, player2Selection;
    int currentRound, MAX_GAME, player1Score, player2Score;

public:
    Referee();
    ~Referee() = default;

    void compareRPS(selection_t player1, selection_t player2);

    void displayRoundWinner(Player * player1, Player * player2);
    void newRound(Player * player1, Player * player2);
    bool endGame();

    void notifySelection(Player * player);
};

#endif /* REFEREE_H_ */
