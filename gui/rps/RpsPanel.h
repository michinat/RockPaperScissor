/**
	Craz CoderZ RPS
	Abstract panel class
*/

#pragma once

#include <wx/panel.h>
#include <wx/sizer.h>

class RpsPanel : public wxPanel {
public:
	RpsPanel(wxPanel * mainPanel) : wxPanel(mainPanel, wxID_ANY) {}
	virtual ~RpsPanel() = default;

	// Init is pure virtual function
	// to be redefined in subclasses
	virtual void Init(wxPanel * mainPanel) = 0;
protected:
	wxSizer * panelSizer;
};
