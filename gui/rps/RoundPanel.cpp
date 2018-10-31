/**
	Craz CoderZ RPS
*/

#include "RoundPanel.h"

RoundPanel::RoundPanel(wxPanel * mainPanel) : RpsPanel(mainPanel)
{
	Init(mainPanel);
}

void RoundPanel::Init(wxPanel * mainPanel)
{
    panelSizer = new wxBoxSizer(wxHORIZONTAL);
	headerGridSizer = new wxGridSizer(2, 0, 20);

	roundText = new wxStaticText(this, wxID_ANY, "Round Number:");
	wxFont font = roundText->GetFont();
	font.SetPointSize(16);
	font.SetWeight(wxFONTWEIGHT_BOLD);
	roundText->SetFont(font);

	headerGridSizer->Add(roundText, 0, 0, 0);
	roundScoreText = new wxStaticText(this, wxID_ANY, "0");
	roundScoreText->SetFont(font);
	headerGridSizer->Add(roundScoreText, 0, 0, 0);

	panelSizer->Add(headerGridSizer, 0, wxLEFT, 200);
	panelSizer->SetSizeHints(mainPanel);
	this->SetSizer(panelSizer);
}
