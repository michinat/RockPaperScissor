/**
    CraZ CoderZ RPS
    Round Panel subclass
*/

#pragma once

#include "RpsPanel.h"
#include <wx/stattext.h>

class RoundPanel : public RpsPanel {
public:
    RoundPanel(wxPanel * mainPanel);

    void Init(wxPanel * mainPanel) override;

    wxStaticText * getRoundScoreText() { return roundScoreText; };
private:
    wxSizer * headerGridSizer;

    wxStaticText * roundText;
    wxStaticText * roundScoreText;
};
