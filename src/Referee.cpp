/**
 * CraZ CoderZ RPS
 * Referee implementation
 */

#include "Referee.h"

Referee::Referee() {
    player1Score = 0;
    player2Score = 0;
	drawScore = 0;
    currentRound = 1;
    MAX_GAME = 21;
    player1Selection = selection_t::INVALID;
    player2Selection = selection_t::INVALID;
}

winner_t Referee::compareRPS(selection_t player1, selection_t player2){
    player1Selection = player1;
    player2Selection = player2;

	winner_t winner;

    /** print debug choices by overloading operator<<
     *  IMPORTANT: COMMENT OUT WHEN DONE DEBUGGING
     *
     */
    //std::cout << "player1: " << player1 << std::endl << "player2: " << player2 << std::endl;

    // TODO make case for invalid choices
    if (player1Selection == selection_t::INVALID ||
        player2Selection == selection_t::INVALID) {
		drawScore++;
		winner = PLAYERS_DRAW;
    }
    // if draw, add 1 to both scores - subject to change
    else if (player1Selection == player2Selection) {
		drawScore++;
		winner = PLAYERS_DRAW;
    }
    // player 1 selects rock
    else if (player1Selection == selection_t::ROCK) {
        if (player2Selection == selection_t::SCISSOR) {
            player1Score++;
			winner = PLAYER1_WIN;
        }
        else if (player2Selection == selection_t::PAPER) {
            player2Score++;
			winner = PLAYER2_WIN;
        }
    }
    // player 1 selects paper
    else if (player1Selection == selection_t::PAPER) {
        if (player2Selection == selection_t::ROCK){
            player1Score++;
			winner = PLAYER1_WIN;
        }
        else if (player2Selection == selection_t::SCISSOR) {
            player2Score++;
			winner = PLAYER2_WIN;
        }
    }
    // player 1 selects scissor
    else if (player1Selection == selection_t::SCISSOR) {
        if (player2Selection == selection_t::PAPER){
            player1Score++;
			winner = PLAYER1_WIN;
        }
        else if (player2Selection == selection_t::ROCK) {
            player2Score++;
			winner = PLAYER2_WIN;
        }
    }

	return winner;
}

void Referee::displayRoundWinner(Player * player1, Player * player2) {
    std::cout << (player1Score > player2Score ? player1->getName() : player2->getName()) << " wins\n";
}

void Referee::newRound(Player * player1, Player * player2) {
    // display scores at beginning of round
    std::cout << "---- Score ----\n"
              << "Round: " << currentRound << "/20\n"
              << player1->getName() << ": " << player1Score << std::endl
              << player2->getName() << ": " << player2Score << std::endl;

    // notify player selections
    notifySelection(player1);
    notifySelection(player2);
    // compare player selections
    compareRPS(player1->getRPS(), player2->getRPS());

    // store entries in vector
    rps.push_back(convertRPStoChar(player1->getRPS()));

    // keep storing last 5 entries to rps frequency log
    if (rps.size() >= 5) {
        pushRPSLog();
    }
    rps.push_back(convertRPStoChar(player2->getRPS()));

    // increment round
    currentRound++;
}

bool Referee::endGame() {
    return currentRound == MAX_GAME;
}

void Referee::notifySelection(Player * player) {
    player->makeRPSChoice();
}
