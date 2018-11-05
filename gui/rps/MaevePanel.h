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

    wxStaticText * getMaeveSelectionText() { return maeveSelectionText; }

private:
    wxSizer * maeveGridSizer;

    wxStaticText * maeveSelectText;
    wxStaticText * maeveSelectionText;
};
