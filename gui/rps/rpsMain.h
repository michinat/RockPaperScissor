/**
	Craz CoderZ RPS 0.1
*/

#pragma once

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

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
	// event handlers (these functions should _not_ be virtual)
	void OnHello(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnRockSelection(wxCommandEvent& event);
	void OnScissorSelection(wxCommandEvent& event);
	void OnPaperSelection(wxCommandEvent& event);
	// any class wishing to process wxWidgets events must use this macro
	DECLARE_EVENT_TABLE();
};

// ----------------------------------------------------------------------------
// constants
// ----------------------------------------------------------------------------

enum
{
	RPS_About = wxID_ABOUT,
	RPS_Exit = wxID_EXIT,

	ID_Hello = 1,
	BUTTON_Rock,
	BUTTON_Paper,
	BUTTON_Scissor
};
