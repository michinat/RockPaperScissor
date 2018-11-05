/**
 * CraZ CoderZ RPS
 * Referee base class
 */

#ifndef REFEREE_H_
#define REFEREE_H_

#include "Player.h"

typedef enum {
    PLAYER1_WIN,
    PLAYER2_WIN,
    PLAYERS_DRAW
} winner_t;

class Referee {
private:
    selection_t player1Selection, player2Selection;
    int currentRound, MAX_GAME, player1Score, player2Score, drawScore;

public:
    Referee();
    ~Referee() = default;

    int getPlayer1Score() { return player1Score; }
    int getPlayer2Score() { return player2Score; }
    int getDrawScore() { return drawScore; }

    void incrementRound() { currentRound++; }
    int getCurrentRound() { return currentRound; }

    winner_t compareRPS(selection_t player1, selection_t player2);

    void displayRoundWinner(Player * player1, Player * player2);
    void newRound(Player * player1, Player * player2);
    bool endGame();

    void notifySelection(Player * player);
};

#endif /* REFEREE_H_ */
