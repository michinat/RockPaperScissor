/**
    CraZ CoderZ RPS
    Round Winner Panel Definition
*/

#include "RoundWinnerPanel.h"

RoundWinnerPanel::RoundWinnerPanel(wxPanel * mainPanel) : RpsPanel(mainPanel)
{
    Init(mainPanel);
}

void RoundWinnerPanel::Init(wxPanel * mainPanel)
{
    panelSizer = new wxBoxSizer(wxVERTICAL);

    winnerGridSizer = new wxGridSizer(1, 0, 0);
    winnerText = new wxStaticText(this, wxID_ANY, "Winner:");
    wxFont font = winnerText->GetFont();
    font.SetPointSize(14);
    font.SetWeight(wxFONTWEIGHT_BOLD);
    winnerText->SetFont(font);

    winnerGridSizer->Add(winnerText, 0, 0, 0);

    winnerNameText = new wxStaticText(this, wxID_ANY, "Nobody");
    winnerNameText->SetFont(font);
    
    winnerGridSizer->Add(winnerNameText, 0, 0, 0);
    
    panelSizer->Add(winnerGridSizer);
    panelSizer->SetSizeHints(mainPanel);
    this->SetSizer(panelSizer);
}
