/**
    CraZ CoderZ RPS
    Rps Button Panel subclass
*/

#pragma once

#include "RpsPanel.h"
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/log.h>
#include "resource_id.h"

class RpsButtonPanel : public RpsPanel {
public:
    RpsButtonPanel(wxPanel * mainPanel);

    void Init(wxPanel * mainPanel) override;

    wxStaticText * getPlayerSelectionText() { return playerSelectionText; }

private:
    wxSizer * rpsButtonSizer;
    wxStaticText * playerSelectText;
    wxStaticText * playerSelectionText;

    wxButton * rockButton;
    wxButton * scissorButton;
    wxButton * paperButton;
};
