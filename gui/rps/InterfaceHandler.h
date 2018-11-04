/**
	CraZ CoderZ RPS
	Facade class that integrates RPS source files into UI
*/

#pragma once

// Rps Source files
#include "../../src/Referee.h"
#include "../../src/CPU.h"

#include <wx/stattext.h>

class InterfaceHandler {
private:
	// rps logic applied
	Referee referee;
	CPU * cpu;

	// dynamic UI elements
	wxStaticText * roundScoreText;
	wxStaticText * maeveSelectionText;
	wxStaticText * winnerNameText;
	wxStaticText * playerScoreText;
	wxStaticText * maeveScoreText;
	wxStaticText * drawScoreText;

	void incrementRoundScore();
	void updateRoundScore();
	void updateMaeveScore();
	void updateWinnerNameText(std::string s);
	void playerWins();
	void maeveWins();
	void playersDraw();

public:
	InterfaceHandler(wxStaticText * t, wxStaticText * t2, wxStaticText * t3, wxStaticText * t4, wxStaticText * t5, wxStaticText * t6);

	void humanMadeSelection(selection_t selection);
};
