/**
    CraZ CoderZ RPS
    Maeve Panel subclass
*/

#pragma once

#include "RpsPanel.h"
#include <wx/stattext.h>

class MaevePanel : public RpsPanel {
public:
    MaevePanel(wxPanel * mainPanel);
    void Init(wxPanel * mainPanel) override;

    wxStaticText * getMaevePredictedScoreText() { return maevePredictedScoreText; }
    wxStaticText * getMaeveSelectScoreText() { return maeveSelectScoreText; }

private:
    wxSizer * maeveGridSizer;

    wxStaticText * maeveTitleText;
    wxStaticText * maevePredictedText;
    wxStaticText * maevePredictedScoreText;
    wxStaticText * maeveSelectText;
    wxStaticText * maeveSelectScoreText;
};
