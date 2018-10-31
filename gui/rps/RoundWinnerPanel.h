/**
	Craz CoderZ RPS
*/

#pragma once

#include "RpsPanel.h"
#include <wx/button.h>
#include <wx/stattext.h>

class RoundWinnerPanel : public RpsPanel {
public:
	RoundWinnerPanel(wxPanel * mainPanel);

	void Init(wxPanel * mainPanel) override;
private:
	wxSizer * winnerGridSizer;

	wxStaticText * winnerText;
	wxStaticText * winnerNameText;
};
