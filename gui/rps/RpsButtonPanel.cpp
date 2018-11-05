/**
    CraZ CoderZ RPS
    Rps Button Panel Definition
*/

#include "RpsButtonPanel.h"

RpsButtonPanel::RpsButtonPanel(wxPanel * mainPanel) : RpsPanel(mainPanel)
{
    Init(mainPanel);
}

void RpsButtonPanel::Init(wxPanel * mainPanel)
{
    panelSizer = new wxBoxSizer(wxVERTICAL);

    playerSelectText = new wxStaticText(this, wxID_ANY, "Player Selects:");
    wxFont font = playerSelectText->GetFont();
    font.SetPointSize(14);
    font.SetWeight(wxFONTWEIGHT_BOLD);
    playerSelectText->SetFont(font);

    panelSizer->Add(playerSelectText, 0, 0, 0);

    rockButton = new wxButton(this, BUTTON_Rock, "Rock");
    scissorButton = new wxButton(this, BUTTON_Scissor, "Scissor");
    paperButton = new wxButton(this, BUTTON_Paper, "Paper");

    rpsButtonSizer = new wxBoxSizer(wxHORIZONTAL);
    rpsButtonSizer->Add(rockButton, 0, wxRIGHT, 30);
    rpsButtonSizer->Add(scissorButton, 0, wxRIGHT, 30);
    rpsButtonSizer->Add(paperButton, 0, 0, 0);

    panelSizer->Add(rpsButtonSizer, 0, wxTOP, 30);

    panelSizer->SetSizeHints(mainPanel);
    this->SetSizer(panelSizer);
}

void RpsButtonPanel::onRockSelection()
{
    interfaceHandler->humanMadeSelection(selection_t::ROCK);
}

void RpsButtonPanel::onScissorSelection()
{
    interfaceHandler->humanMadeSelection(selection_t::SCISSOR);
}

void RpsButtonPanel::onPaperSelection()
{
    interfaceHandler->humanMadeSelection(selection_t::PAPER);
}
