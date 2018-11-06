/**
    CraZ CoderZ RPS
    Facade class that integrates RPS source files into UI
*/

#pragma once

// Rps Source files
#include "../../src/Referee.h"
#include "../../src/CPU.h"

#include <wx/stattext.h>
#include <wx/msgdlg.h>
#include <wx/string.h>

class InterfaceHandler {
private:
    // rps logic applied
    Referee referee;
    Player * cpu;

    // dynamic UI elements
    wxStaticText * playerSelectionText;
    wxStaticText * roundScoreText;
    wxStaticText * maevePredictedScoreText;
    wxStaticText * maeveSelectScoreText;
    wxStaticText * winnerNameText;
    wxStaticText * playerScoreText;
    wxStaticText * maeveScoreText;
    wxStaticText * drawScoreText;

    void incrementRoundScore();
    void updateRoundScore();
    void updatePlayerScore(std::string s);
    void updateMaevePredictedScore(std::string s);
    void updateMaeveSelectScore(std::string s);
    void updateWinnerNameText(std::string s);
    void playerWins();
    void maeveWins();
    void playersDraw();

public:
    InterfaceHandler(wxStaticText * t, wxStaticText * t2, wxStaticText * t3, wxStaticText * t4, wxStaticText * t5, wxStaticText * t6, wxStaticText * t7, wxStaticText * t8);
    ~InterfaceHandler();

    // invoked in respective UI callback functions
    void humanMadeSelection(selection_t selection);
    void newGame(bool resetRounds = true);
    void setMaxRounds(int rounds);
    long getMaxRounds();
    void displayWinner();
};
