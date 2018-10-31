/**
	Craz CoderZ RPS
*/

#pragma once

#include "RpsPanel.h"
#include <wx/stattext.h>

class RoundPanel : public RpsPanel {
public:
	RoundPanel(wxPanel * mainPanel);

	void Init(wxPanel * mainPanel) override;
private:
	wxSizer * headerGridSizer;

	wxStaticText * roundText;
	wxStaticText * roundScoreText;
};
