/**
	Craz CoderZ RPS
*/

#pragma once

#include "RpsPanel.h"
#include <wx/stattext.h>

class MaevePanel : public RpsPanel {
public:
	MaevePanel(wxPanel * mainPanel);
	void Init(wxPanel * mainPanel) override;
private:
	wxSizer * maeveGridSizer;

	wxStaticText * maeveSelectText;
	wxStaticText * maeveScoreText;
};
