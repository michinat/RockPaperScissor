/**
	Craz CoderZ RPS
*/

#include "ScoreBoardPanel.h"

ScoreBoardPanel::ScoreBoardPanel(wxPanel * mainPanel) : RpsPanel(mainPanel)
{
	Init(mainPanel);
}

void ScoreBoardPanel::Init(wxPanel * mainPanel)
{
    panelSizer = new wxBoxSizer(wxVERTICAL);

	scoreBoardHeaderSizer = new wxBoxSizer(wxHORIZONTAL);
	scoreBoardText = new wxStaticText(this, wxID_ANY, "Score Board");
	wxFont font = scoreBoardText->GetFont();
	font.SetPointSize(14);
	font.SetWeight(wxFONTWEIGHT_BOLD);
	scoreBoardText->SetFont(font);

	scoreBoardHeaderSizer->Add(scoreBoardText, 0, 0, 0);
	panelSizer->Add(scoreBoardHeaderSizer);

	scoreSizer = new wxGridSizer(2, 0, 20);

	playerText = new wxStaticText(this, wxID_ANY, "Player:");
	scoreSizer->Add(playerText);

	playerScoreText = new wxStaticText(this, wxID_ANY, "0");
	scoreSizer->Add(playerScoreText);
	maeveText = new wxStaticText(this, wxID_ANY, "Maeve:");
	scoreSizer->Add(maeveText);
	maeveScoreText = new wxStaticText(this, wxID_ANY, "0");
	scoreSizer->Add(maeveScoreText);
	drawText = new wxStaticText(this, wxID_ANY, "Draw:");
	scoreSizer->Add(drawText);
	drawScoreText = new wxStaticText(this, wxID_ANY, "0");
	scoreSizer->Add(drawScoreText);

	panelSizer->Add(scoreSizer, 0, wxLEFT, 35);

	panelSizer->SetSizeHints(mainPanel);
	this->SetSizer(panelSizer);
}
