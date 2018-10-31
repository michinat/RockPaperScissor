/**
	Craz CoderZ RPS
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

	void OnRockSelection(wxCommandEvent& event);
	void OnScissorSelection(wxCommandEvent& event);
	void OnPaperSelection(wxCommandEvent& event);
private:
	wxSizer * rpsButtonSizer;
	wxStaticText * playerSelectText;

	wxButton * rockButton;
	wxButton * scissorButton;
	wxButton * paperButton;
};
