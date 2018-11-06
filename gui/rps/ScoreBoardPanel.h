/**
    CraZ CoderZ RPS
    Scoreboard Panel subclass
*/

#pragma once

#include "RpsPanel.h"
#include <wx/stattext.h>
#include <wx/textctrl.h>

class ScoreBoardPanel : public RpsPanel {
public:
    ScoreBoardPanel(wxPanel * mainPanel);

    void Init(wxPanel * mainPanel) override;

    wxStaticText * getPlayerScoreText() { return playerScoreText; }
    wxStaticText * getMaeveScoreText() { return maeveScoreText; }
    wxStaticText * getDrawScoreText() { return drawScoreText; }
private:
    wxSizer * scoreSizer;
    wxSizer * scoreBoardHeaderSizer;

    wxStaticText * scoreBoardText;
    wxStaticText * playerText;
    wxStaticText * playerScoreText;
    wxStaticText * maeveText;
    wxStaticText * maeveScoreText;
    wxStaticText * drawText;
    wxStaticText * drawScoreText;
};
