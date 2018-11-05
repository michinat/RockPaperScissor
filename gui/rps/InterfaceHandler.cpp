/**
    CraZ CoderZ RPS
    Interface Handler definition
*/

#include "InterfaceHandler.h"

InterfaceHandler::InterfaceHandler(wxStaticText * t, wxStaticText * t2, wxStaticText * t3, wxStaticText * t4, wxStaticText * t5, wxStaticText * t6) :
    roundScoreText(t), maeveSelectionText(t2), winnerNameText(t3), playerScoreText(t4), maeveScoreText(t5), drawScoreText(t6) {
    //referee = new Referee();
    cpu = new CPU(CPU::SIMPLEML);
    // set default round 1
    updateRoundScore();
}

void InterfaceHandler::humanMadeSelection(selection_t selection) {
    referee.notifySelection(cpu);
    updateMaeveScore();

    winner_t winner = referee.compareRPS(selection, cpu->getRPS());

    // draw, or invalid entries

    switch (winner) {
        case PLAYERS_DRAW:
            updateWinnerNameText("Nobody");
            playersDraw();
            break;
        case PLAYER1_WIN:
            // human won
            updateWinnerNameText("Human");
            playerWins();

            // increment round
            incrementRoundScore();
            // update gui round score
            updateRoundScore();
            break;
        case PLAYER2_WIN:
            // cpu won
            updateWinnerNameText("Maeve");
            maeveWins();

            // increment round
            incrementRoundScore();
            // update gui round score
            updateRoundScore();
            break;
        default:
            break;
    }

    // store entries in vector
    rps.push_back(convertRPStoChar(selection));

    // keep storing last 5 entries to rps frequency log
    if (rps.size() >= 5) 
        pushRPSLog();
    rps.push_back(convertRPStoChar(cpu->getRPS()));
}

void InterfaceHandler::incrementRoundScore() {
    referee.incrementRound();
}

void InterfaceHandler::updateRoundScore() {
    roundScoreText->SetLabel(std::to_string(referee.getCurrentRound()));
}

void InterfaceHandler::updateMaeveScore() {
    maeveSelectionText->SetLabel(rpsToString(cpu->getRPS()));
}

void InterfaceHandler::updateWinnerNameText(std::string s) {
    winnerNameText->SetLabel(s);
}

void InterfaceHandler::playerWins() {
    playerScoreText->SetLabel(std::to_string(referee.getPlayer1Score()));
}

void InterfaceHandler::maeveWins() {
    maeveScoreText->SetLabel(std::to_string(referee.getPlayer2Score()));
}

void InterfaceHandler::playersDraw() {
    drawScoreText->SetLabel(std::to_string(referee.getDrawScore()));
}