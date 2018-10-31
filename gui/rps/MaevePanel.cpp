/**
	Craz CoderZ RPS
*/

#include "MaevePanel.h"

MaevePanel::MaevePanel(wxPanel * mainPanel) : RpsPanel(mainPanel)
{
	Init(mainPanel);
}

void MaevePanel::Init(wxPanel * mainPanel)
{
	panelSizer = new wxBoxSizer(wxVERTICAL);

	maeveGridSizer = new wxGridSizer(1, 0, 10);

	maeveSelectText = new wxStaticText(this, wxID_ANY, "Maeve Selects:");
	wxFont font = maeveSelectText->GetFont();
	font.SetPointSize(14);
	font.SetWeight(wxFONTWEIGHT_BOLD);
	maeveSelectText->SetFont(font);
	maeveGridSizer->Add(maeveSelectText, 0, 0, 0);

	maeveScoreText = new wxStaticText(this, wxID_ANY, "Nothing");
	maeveScoreText->SetFont(font);
	maeveGridSizer->Add(maeveScoreText, 0, wxLEFT, 42);

	panelSizer->Add(maeveGridSizer, 0, 0, 0);
	panelSizer->SetSizeHints(mainPanel);
	this->SetSizer(panelSizer);
}
