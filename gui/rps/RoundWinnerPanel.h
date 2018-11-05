/**
    CraZ CoderZ RPS
    Round Winnner Panel subclass
*/

#pragma once

#include "RpsPanel.h"
#include <wx/button.h>
#include <wx/stattext.h>

class RoundWinnerPanel : public RpsPanel {
public:
    RoundWinnerPanel(wxPanel * mainPanel);

    void Init(wxPanel * mainPanel) override;
    wxStaticText * getWinnerNameText() { return winnerNameText; }
private:
    wxSizer * winnerGridSizer;

    wxStaticText * winnerText;
    wxStaticText * winnerNameText;
};
