/**
	CraZ CoderZ RPS
	RPS main driver file which inits wxWidgets
*/

#include "RpsMain.h"

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
    wxPuts(wxT("Initiated wxWidgets console application!"));
	frame->Show(true);
	return true;
}

// ----------------------------------------------------------------------------
// main frame
// ----------------------------------------------------------------------------

RpsFrame::RpsFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, title, pos, size)
{
	// MENU BAR
	wxMenu * menuFile = new wxMenu;
	menuFile->Append(ID_Hello, "&Hello...\tCtrl-H", 
		"Help string shown in status bar for this menu item");
	menuFile->AppendSeparator();
	menuFile->Append(RPS_Exit);

	wxMenu * menuSetting = new wxMenu;
	menuSetting->Append(ID_SETTING, "&Set Rounds",
		"Default rounds is 20");

	wxMenu * menuHelp = new wxMenu;
	menuHelp->Append(RPS_About);

	wxMenuBar * menuBar = new wxMenuBar;
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuSetting, "&Setting");
	menuBar->Append(menuHelp, "&Help");
	SetMenuBar(menuBar);
	CreateStatusBar();
	SetStatusText("Welcome to wxWidgets!");

	// MAIN PANEL
	wxPanel * mainPanel = new wxPanel(this, wxID_ANY);
	wxBoxSizer * mainSizer = new wxBoxSizer(wxVERTICAL);
	mainSizer->SetSizeHints(mainPanel);
	mainPanel->SetSizer(mainSizer);
	wxColour col1;
	col1.Set(wxT("#c2d4dd"));
	mainPanel->SetBackgroundColour(col1);

    // ROUNDS
	roundPanel = new RoundPanel(mainPanel);
	mainSizer->Add(roundPanel, 0, wxALIGN_CENTER | wxTOP, 25);

	// RPS buttons
	rpsButtonPanel = new RpsButtonPanel(mainPanel);
	mainSizer->Add(rpsButtonPanel, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 30);

    // MAEVE'S SELECTION
	maevePanel = new MaevePanel(mainPanel);
	mainSizer->Add(maevePanel, 0, wxALIGN_CENTER, 0);
	
    // ROUND'S WINNER
	roundWinnerPanel = new RoundWinnerPanel(mainPanel);
	mainSizer->Add(roundWinnerPanel, 0, wxALIGN_CENTER | wxTOP, 10);

    // SCORE BOARD 
	scoreBoardPanel = new ScoreBoardPanel(mainPanel);
	mainSizer->Add(scoreBoardPanel, 0, wxALIGN_CENTER | wxTOP, 10);


	rpsButtonPanel->setInterfaceHandler(
		roundPanel->getRoundScoreText(), maevePanel->getMaeveSelectionText(), roundWinnerPanel->getWinnerNameText(),
		scoreBoardPanel->getPlayerScoreText(), scoreBoardPanel->getMaeveScoreText(), scoreBoardPanel->getDrawScoreText());

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
	EVT_MENU(ID_SETTING, RpsFrame::OnSettings)
	EVT_MENU(RPS_About, RpsFrame::OnAbout)
	EVT_BUTTON(BUTTON_Rock, RpsFrame::OnRockPressed)
	EVT_BUTTON(BUTTON_Paper, RpsFrame::OnPaperPressed)
	EVT_BUTTON(BUTTON_Scissor, RpsFrame::OnScissorPressed)
END_EVENT_TABLE()

// ----------------------------------------------------------------------------
// main frame implementation
// ----------------------------------------------------------------------------

void RpsFrame::OnHello(wxCommandEvent& event)
{
	wxLogMessage("Hello world from wxWidgets!");
}

void RpsFrame::OnExit(wxCommandEvent & event)
{
	Close(true);
}

void RpsFrame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox("This is a wxWidgets' Hello world sample",
		"About Hello World", wxOK | wxICON_INFORMATION);
}

void RpsFrame::OnSettings(wxCommandEvent& event)
{
	wxLogMessage("Settings!");
}

void RpsFrame::OnRockPressed(wxCommandEvent& event)
{
	rpsButtonPanel->onRockSelection();
}

void RpsFrame::OnScissorPressed(wxCommandEvent& event)
{
	rpsButtonPanel->onScissorSelection();
}

void RpsFrame::OnPaperPressed(wxCommandEvent& event)
{
	rpsButtonPanel->onPaperSelection();
}

