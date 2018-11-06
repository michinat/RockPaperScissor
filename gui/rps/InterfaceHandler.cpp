/**
    CraZ CoderZ RPS
    Interface Handler definition
*/

#include "InterfaceHandler.h"

InterfaceHandler::InterfaceHandler(wxStaticText * t, wxStaticText * t2, wxStaticText * t3, wxStaticText * t4, wxStaticText * t5, wxStaticText * t6, wxStaticText * t7, wxStaticText * t8) :
    roundScoreText(t), playerSelectionText(t2), maevePredictedScoreText(t3), maeveSelectScoreText(t4), winnerNameText(t5), playerScoreText(t6), maeveScoreText(t7), drawScoreText(t8) {
    cpu = new CPU(CPU::SIMPLEML);
    // set default round 1
    updateRoundScore();
}

    InterfaceHandler::~InterfaceHandler()
    {
        delete cpu;
    }

void InterfaceHandler::humanMadeSelection(selection_t selection) {
    updatePlayerScore(rpsToString(selection));
    referee.notifySelection(cpu);
    updateMaeveSelectScore(rpsToString(cpu->getRPS()));

    winner_t winner = referee.compareRPS(selection, cpu->getRPS());

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
            if (!referee.endGame()) updateRoundScore();
            break;
        case PLAYER2_WIN:
            // cpu won
            updateWinnerNameText("Maeve");
            maeveWins();

            // increment round
            incrementRoundScore();
            // update gui round score
            if (!referee.endGame()) updateRoundScore();
            break;
        default:
            break;
    }

    // store entries in vector
    rps.push_back(convertRPStoChar(selection));

    // keep storing last 5 entries to rps frequency log
    if (rps.size() >= 5) {
        // show predicted score
        updateMaevePredictedScore(rpsToString(getPredictedChoice()));
        // keep storing last 5 entries to rps frequency log
        pushRPSLog();
    }
    rps.push_back(convertRPStoChar(cpu->getRPS()));

    if (referee.endGame()) {
        displayWinner();
    }
}

void InterfaceHandler::incrementRoundScore() {
    referee.incrementRound();
}

void InterfaceHandler::updateRoundScore() {
    roundScoreText->SetLabel(std::to_string(referee.getCurrentRound()));
}

void InterfaceHandler::updatePlayerScore(std::string s)
{
    playerSelectionText->SetLabel(s);
}

void InterfaceHandler::updateMaevePredictedScore(std::string s)
{
    maevePredictedScoreText->SetLabel(s);
}

void InterfaceHandler::updateMaeveSelectScore(std::string s) {
    maeveSelectScoreText->SetLabel(s);
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

void InterfaceHandler::newGame(bool resetRounds)
{
    if (resetRounds) referee = Referee(); 
    else referee = Referee(referee.getMaxRounds());

    // clear rps vector tracking
    if (rps.size() > 0) rps.clear();
    updatePlayerScore("");
    updateMaevePredictedScore("Nothing");
    updateMaeveSelectScore("Nothing");
    updateWinnerNameText("Nobody");
    updateRoundScore();
    playerWins();
    maeveWins();
    playersDraw();
}

void InterfaceHandler::setMaxRounds(int rounds)
{
    referee.setMaxRound(rounds);
}

long InterfaceHandler::getMaxRounds()
{
    return referee.getMaxRounds();
}

void InterfaceHandler::displayWinner()
{
    std::string s;
    if (referee.getPlayer1Score() == referee.getPlayer2Score()) {
        s = "No one has won, you got a draw with Maeve with " + std::to_string(referee.getPlayer1Score()) + " points each!";
    }
    else {
        std::string winnerName = "";
        std::string score = "";
        if (referee.getPlayer1Score() > referee.getPlayer2Score()) {
            winnerName = "You have";
            score = std::to_string(referee.getPlayer1Score());
        }
        else {
            winnerName = "Maeve has";
            score = std::to_string(referee.getPlayer2Score());
        }
        s = winnerName + " won with " + score + " points! Play again if you'd like!";
    }

    newGame(false);

    wxString winnerText(s);
    wxMessageBox(winnerText);
}
