/**
    CraZ CoderZ RPS
    Maeve Panel Defintion
*/

#include "MaevePanel.h"

MaevePanel::MaevePanel(wxPanel * mainPanel) : RpsPanel(mainPanel)
{
    Init(mainPanel);
}

void MaevePanel::Init(wxPanel * mainPanel)
{
    panelSizer = new wxBoxSizer(wxVERTICAL);

    maeveTitleText = new wxStaticText(this, wxID_ANY, "Maeve:");
    wxFont font = maeveTitleText->GetFont();
    font.SetPointSize(14);
    font.SetWeight(wxFONTWEIGHT_BOLD);
    maeveTitleText->SetFont(font);
    panelSizer->Add(maeveTitleText, 0, 0, 0);

    maeveGridSizer = new wxGridSizer(2, 0, 10);

    maevePredictedText = new wxStaticText(this, wxID_ANY, "Predicted:");
    maeveGridSizer->Add(maevePredictedText);

    maevePredictedScoreText = new wxStaticText(this, wxID_ANY, "Nothing");
    maeveGridSizer->Add(maevePredictedScoreText);

    maeveSelectText = new wxStaticText(this, wxID_ANY, "Selected:");
    maeveGridSizer->Add(maeveSelectText);

    maeveSelectScoreText = new wxStaticText(this, wxID_ANY, "Nothing");
    maeveGridSizer->Add(maeveSelectScoreText);

    panelSizer->Add(maeveGridSizer, 0, 0, 0);
    panelSizer->SetSizeHints(mainPanel);
    this->SetSizer(panelSizer);
}
