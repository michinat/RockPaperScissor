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
#include "InterfaceHandler.h"

class RpsButtonPanel : public RpsPanel {
public:
	RpsButtonPanel(wxPanel * mainPanel);

	void Init(wxPanel * mainPanel) override;

    void onRockSelection();
	void onScissorSelection();
	void onPaperSelection();

	void setInterfaceHandler(wxStaticText * t, wxStaticText * t2, wxStaticText * t3,
		wxStaticText * t4, wxStaticText * t5, wxStaticText * t6) { interfaceHandler = new InterfaceHandler(t, t2, t3, t4, t5, t6); }

private:
	wxSizer * rpsButtonSizer;
	wxStaticText * playerSelectText;

	wxButton * rockButton;
	wxButton * scissorButton;
	wxButton * paperButton;
	InterfaceHandler * interfaceHandler;
};
