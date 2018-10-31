/**
	Craz CoderZ RPS
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
	RpsPanel * roundPanel = new RoundPanel(mainPanel);
	mainSizer->Add(roundPanel, 0, wxALIGN_CENTER | wxTOP, 25);

	// RPS buttons
	RpsPanel * rpsButtonPanel = new RpsButtonPanel(mainPanel);
	mainSizer->Add(rpsButtonPanel, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 30);

    // MAEVE'S SELECTION
	RpsPanel * maevePanel = new MaevePanel(mainPanel);
	mainSizer->Add(maevePanel, 0, wxALIGN_CENTER, 0);
	
    // ROUND'S WINNER
	RpsPanel * roundWinnerPanel = new RoundWinnerPanel(mainPanel);
	mainSizer->Add(roundWinnerPanel, 0, wxALIGN_CENTER | wxTOP, 10);

    // SCORE BOARD 
	RpsPanel * scoreBoardPanel = new ScoreBoardPanel(mainPanel);
	mainSizer->Add(scoreBoardPanel, 0, wxALIGN_CENTER | wxTOP, 10);

	// INPUT BOX 
	// wxPanel* panel = new wxPanel(this, -1);
	// wxTextCtrl* text = new wxTextCtrl(panel, 1, "");

	// wxBoxSizer* panelSizer = new wxBoxSizer(wxVERTICAL);
	// panelSizer->Add(text, wxSizerFlags().Center());
	// panel->SetSizer(panelSizer);

	// wxBoxSizer* frameSizer = new wxBoxSizer(wxVERTICAL);
	// frameSizer->Add(panel, wxSizerFlags().Expand());
	// SetSizer(frameSizer);  

	// wxSize title = new wxSize(5, 5); 

	// ADD IMAGE
	// wxPNGHandler *handler = new wxPNGHandler;
	// wxImage::AddHandler(handler);
	// wxStaticBitmap *image;
	// image = new wxStaticBitmap(this, wxID_ANY, wxBitmap("Windows_7_logo.png", wxBITMAP_TYPE_PNG), 
	//     wxPoint(50,100), wxSize(100, 500));

	// LINE 
	// wxStaticLine *sl1 = new wxStaticLine(this, wxID_ANY, wxPoint(60, 185), 
	// wxSize(340,1));

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
	EVT_BUTTON(BUTTON_Rock, RpsButtonPanel::OnRockSelection)
	EVT_BUTTON(BUTTON_Paper, RpsButtonPanel::OnPaperSelection)
	EVT_BUTTON(BUTTON_Scissor, RpsButtonPanel::OnScissorSelection)
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

void RpsFrame::OnSettings(wxCommandEvent& event)
{
	wxLogMessage("Settings!");
}
