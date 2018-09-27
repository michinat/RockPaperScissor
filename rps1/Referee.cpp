/**
 * Referee.cpp
 *
 */

#include "Referee.h"

Referee::Referee() {
    player1Score = 0;
	player2Score = 0;
	currentRound = 0;
	MAX_GAME = 20;
	player1Selection = selection_t::INVALID;
    player2Selection = selection_t::INVALID;
}

Referee::~Referee() {
    delete this;
}

void Referee::compareRPS(selection_t player1, selection_t player2){

    player1Selection = player1;
    player2Selection = player2;

	/** print debug choices; 0 = rock, 1 = paper, scissor = 2
	 *  IMPORTANT: COMMENT OUT WHEN DONE DEBUGGING
	 */
	std::cout << "player1: " << (int)player1 << std::endl
	          << "player2: " << (int)player2 << std::endl;

    // TODO make case for invalid choices
    if (player1Selection == selection_t::INVALID ||
        player2Selection == selection_t::INVALID) {
    }
    // if draw, add 1 to both scores - subject to change
    else if (player1Selection == player2Selection){
        player2Score++;
        player1Score++;
    }
    // player 1 selects rock
    else if (player1Selection == selection_t::ROCK) {
    	if (player2Selection == selection_t::SCISSOR) {
		    player1Score++;
	    } else if (player2Selection == selection_t::PAPER) {
    		player2Score++;
    	}
    }
	// player 1 selects paper
	else if (player1Selection == selection_t::PAPER) {
	    if (player2Selection == selection_t::ROCK){
	        player1Score++;
	    }
	    else if (player2Selection == selection_t::SCISSOR) {
	        player2Score++;
	    }
	}
	// player 1 selects scissor
	else if (player1Selection == selection_t::SCISSOR) {
		if (player2Selection == selection_t::PAPER){
			player1Score++;
		}
		else if (player2Selection == selection_t::ROCK) {
			player2Score++;
		}
	}
}

void Referee::displayRoundWinner(Player * player1, Player * player2) {
	std::cout << (player1Score > player2Score ? player1->getName() : player2->getName()) << " wins\n";
}

void Referee::newRound(Player * player1, Player * player2) {
    // display scores at beginning of round
    std::cout << "---- Score ----\n"
              << player1->getName() << ": " << player1Score << std::endl
              << player2->getName() << ": " << player2Score << std::endl;

    // notify player selections
    notifySelection(player1);
	notifySelection(player2);

	compareRPS(player1->getRPS(), player2->getRPS());

	// increment round
	currentRound++;
}

bool Referee::endGame(){
    return currentRound == MAX_GAME;
}

void Referee::notifySelection(Player * player) {
    player->makeRPSChoice();
}
