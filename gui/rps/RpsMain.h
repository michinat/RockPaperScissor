/**
	CraZ CoderZ RPS
	RPS main file; initiates wxWidgets and contains main frame/sizer
*/

#pragma once

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <wx/chartype.h>
#include <wx/statline.h>

// RpsPanel child classes
#include "RoundPanel.h"
#include "RpsButtonPanel.h"
#include "MaevePanel.h"
#include "RoundWinnerPanel.h"
#include "ScoreBoardPanel.h"

// interface handler facade object
#include "InterfaceHandler.h"

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWidgets headers)
#ifndef WX_PRECOMP
	#include "wx/wx.h"
#endif

// ----------------------------------------------------------------------------
// resources
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// private classes
// ----------------------------------------------------------------------------

// Define a new application type, each program should derive a class from wxApp
class RpsApp : public wxApp
{
public:
	// override OnInit() function
	virtual bool OnInit();
};

// Define a new frame type: this is going to be our main frame
class RpsFrame : public wxFrame
{
public:
	RpsFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

private:
	RoundPanel * roundPanel;
	RpsButtonPanel * rpsButtonPanel;
	MaevePanel * maevePanel;
	RoundWinnerPanel * roundWinnerPanel;
	ScoreBoardPanel * scoreBoardPanel;

	// event handlers (these functions should _not_ be virtual)
	void OnHello(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnSettings(wxCommandEvent& event);

	void OnRockPressed(wxCommandEvent& event);
	void OnPaperPressed(wxCommandEvent& event);
	void OnScissorPressed(wxCommandEvent& event);
	// any class wishing to process wxWidgets events must use this macro
	DECLARE_EVENT_TABLE();
};
