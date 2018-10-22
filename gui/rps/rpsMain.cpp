/**
	Craz CoderZ RPS 0.1
*/

#include "rpsMain.h"

// Create a new application object: this macro will allow wxWidgets to create
// the application object during program execution (it's better than using a
// static object for many reasons) and also implements the accessor function
// wxGetApp() which will return the reference of the right type (i.e. RpsApp and
// not wxApp)
IMPLEMENT_APP(RpsApp);

// ----------------------------------------------------------------------------
// the application class
// ----------------------------------------------------------------------------

// 'Main program' equivalent: the program execution "starts" here
bool RpsApp::OnInit()
{
	RpsFrame *frame = new RpsFrame("RPS", wxPoint(500, 200), wxSize(900, 680));
	frame->Show(true);
	return true;
}

// ----------------------------------------------------------------------------
// main frame
// ----------------------------------------------------------------------------

RpsFrame::RpsFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, title, pos, size)
{
	wxMenu * menuFile = new wxMenu;
	menuFile->Append(ID_Hello, "&Hello...\tCtrl-H", 
		"Help string shown in status bar for this menu item");
	menuFile->AppendSeparator();
	menuFile->Append(RPS_Exit);

	wxMenu * menuHelp = new wxMenu;
	menuHelp->Append(RPS_About);

	wxMenuBar * menuBar = new wxMenuBar;
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuHelp, "&Help");
	SetMenuBar(menuBar);
	CreateStatusBar();
	SetStatusText("Welcome to wxWidgets!");

	// RPS buttons
	wxButton * rockButton = new wxButton(this, BUTTON_Rock, "Rock", 
		wxPoint(160, 450), wxDefaultSize, 0);
	wxButton * scissorButton = new wxButton(this, BUTTON_Scissor, "Scissor",
		wxPoint(360, 450), wxDefaultSize, 0);
	wxButton * paperButton = new wxButton(this, BUTTON_Paper, "Paper",
		wxPoint(560, 450), wxDefaultSize, 0);
}

// ----------------------------------------------------------------------------
// event tables and other macros for wxWidgets
// ----------------------------------------------------------------------------

// the event tables connect the wxWidgets events with the functions (event
// handlers) which process them. It can be also done at run-time, but for the
// simple menu events like this the static method is much simpler.
BEGIN_EVENT_TABLE(RpsFrame, wxFrame)
	EVT_MENU(ID_Hello, RpsFrame::OnHello)
	EVT_MENU(RPS_Exit, RpsFrame::OnExit)
	EVT_MENU(RPS_About, RpsFrame::OnAbout)
	EVT_BUTTON(BUTTON_Rock, RpsFrame::OnRockSelection)
	EVT_BUTTON(BUTTON_Paper, RpsFrame::OnPaperSelection)
	EVT_BUTTON(BUTTON_Scissor, RpsFrame::OnScissorSelection)
END_EVENT_TABLE()

// ----------------------------------------------------------------------------
// main frame implementation
// ----------------------------------------------------------------------------

void RpsFrame::OnExit(wxCommandEvent& event)
{
	Close(true);
}

void RpsFrame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox("This is a wxWidgets' Hello world sample",
		"About Hello World", wxOK | wxICON_INFORMATION);
}

void RpsFrame::OnHello(wxCommandEvent& event)
{
	wxLogMessage("Hello world from wxWidgets!");
}

void RpsFrame::OnRockSelection(wxCommandEvent& event)
{
	wxLogMessage("Rock selected!");
}

void RpsFrame::OnScissorSelection(wxCommandEvent& event)
{
	wxLogMessage("Scissor selected!");
}

void RpsFrame::OnPaperSelection(wxCommandEvent& event)
{
	wxLogMessage("Paper selected!");
}
