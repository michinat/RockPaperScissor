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
	wxMenu * menuFile = new wxMenu;
	menuFile->Append(ID_Hello, "&Hello...\tCtrl-H", 
		"Help string shown in status bar for this menu item");
	menuFile->AppendSeparator();
	menuFile->Append(RPS_Exit);

	wxMenu * menuHelp = new wxMenu;
	menuHelp->Append(RPS_About);

	// MENU BAR 
	wxMenuBar * menuBar = new wxMenuBar;
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuHelp, "&Help");
	SetMenuBar(menuBar);
	CreateStatusBar();
	SetStatusText("Welcome to wxWidgets!");

	// MAIN PANEL
	wxPanel * mainPanel = new wxPanel(this, wxID_ANY);
	wxBoxSizer * mainSizer = new wxBoxSizer(wxVERTICAL);
	mainSizer->SetSizeHints(mainPanel);
	mainPanel->SetSizer(mainSizer);
	// set main panel color
	wxColour col1;
	col1.Set(wxT("#c2d4dd"));
	mainPanel->SetBackgroundColour(col1);

    // INPUT BOX 
    // wxPanel* panel = new wxPanel(this, -1);
    // wxTextCtrl* text = new wxTextCtrl(panel, 1, "");

    // wxBoxSizer* panelSizer = new wxBoxSizer(wxVERTICAL);
    // panelSizer->Add(text, wxSizerFlags().Center());
    // panel->SetSizer(panelSizer);

    // wxBoxSizer* frameSizer = new wxBoxSizer(wxVERTICAL);
    // frameSizer->Add(panel, wxSizerFlags().Expand());
    // SetSizer(frameSizer);  

    //wxSize title = new wxSize(5, 5); 

    // ROUNDS 
	wxPanel * headerPanel = new wxPanel(mainPanel, wxID_ANY);
	wxBoxSizer * headerSizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText * str9 = new wxStaticText(headerPanel, wxID_ANY, "Round Number:");
    wxFont font = str9->GetFont();
    font.SetPointSize(16);
    font.SetWeight(wxFONTWEIGHT_BOLD);
    str9->SetFont(font);

	headerSizer->Add(str9, 0, 0, 0);
	headerSizer->SetSizeHints(mainPanel);
	headerPanel->SetSizer(headerSizer);
	mainSizer->Add(headerPanel, 0, wxALIGN_CENTER, 0);

	// RPS buttons
	wxPanel * rpsPanel = new wxPanel(mainPanel, wxID_ANY);
	wxBoxSizer * rpsPanelSizer = new wxBoxSizer(wxVERTICAL);

	wxStaticText * str1 = new wxStaticText(rpsPanel, wxID_ANY, "Player Selects:");
	wxFont font1 = str1->GetFont();
	font1.SetPointSize(14);
	font1.SetWeight(wxFONTWEIGHT_BOLD);
	str1->SetFont(font1);

	rpsPanelSizer->Add(str1);

	wxButton * rockButton = new wxButton(rpsPanel, BUTTON_Rock, "Rock");
	wxButton * scissorButton = new wxButton(rpsPanel, BUTTON_Scissor, "Scissor");
	wxButton * paperButton = new wxButton(rpsPanel, BUTTON_Paper, "Paper");

	wxBoxSizer * rpsButtonSizer = new wxBoxSizer(wxHORIZONTAL);
	rpsButtonSizer->Add(rockButton, 0, wxRIGHT, 30);
	rpsButtonSizer->Add(scissorButton, 0, wxRIGHT, 30);
	rpsButtonSizer->Add(paperButton, 0, 0, 0);

	rpsPanelSizer->Add(rpsButtonSizer, 0, wxTOP, 30);

	rpsPanelSizer->SetSizeHints(mainPanel);
	rpsPanel->SetSizer(rpsPanelSizer);
	mainSizer->Add(rpsPanel, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 30);

    // ADD IMAGE
    // wxPNGHandler *handler = new wxPNGHandler;
    // wxImage::AddHandler(handler);
    // wxStaticBitmap *image;
    // image = new wxStaticBitmap(this, wxID_ANY, wxBitmap("Windows_7_logo.png", wxBITMAP_TYPE_PNG), 
    //     wxPoint(50,100), wxSize(100, 500));

    // MAEVE'S SELECTION
	wxPanel * maevePanel = new wxPanel(mainPanel, wxID_ANY);
	wxBoxSizer * maevePanelSizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer * maeveHeaderSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText * str2 = new wxStaticText(maevePanel, wxID_ANY, "Maeve Selects:");
    wxFont font2 = str2->GetFont();
    font2.SetPointSize(14);
    font2.SetWeight(wxFONTWEIGHT_BOLD);
    str2->SetFont(font2); 

	maeveHeaderSizer->Add(str2, 0, 0, 0);
	maevePanelSizer->Add(maeveHeaderSizer, 0, 0, 0);

	maevePanelSizer->SetSizeHints(mainPanel);
	maevePanel->SetSizer(maevePanelSizer);
	mainSizer->Add(maevePanel, 0, wxALIGN_CENTER | wxRIGHT, 245);

    // LINE 
    // wxStaticLine *sl1 = new wxStaticLine(this, wxID_ANY, wxPoint(60, 185), 
    // wxSize(340,1));
	
    // ROUND'S WINNER
	wxPanel * roundWinnerPanel = new wxPanel(mainPanel, wxID_ANY);
	wxBoxSizer * roundWinnerPanelSizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer * winnerHeaderSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText * str4 = new wxStaticText(roundWinnerPanel, wxID_ANY, "Winner:");
    wxFont font4 = str4->GetFont();
    font4.SetPointSize(14);
    font4.SetWeight(wxFONTWEIGHT_BOLD);
    str4->SetFont(font4);

	winnerHeaderSizer->Add(str4, 0, wxRIGHT, 330);
	roundWinnerPanelSizer->Add(winnerHeaderSizer);

	roundWinnerPanelSizer->SetSizeHints(mainPanel);
	roundWinnerPanel->SetSizer(roundWinnerPanelSizer);
	mainSizer->Add(roundWinnerPanel, 0, wxALIGN_CENTER | wxTOP, 30);

    // SCORE BOARD 
	wxPanel * scoreBoardPanel = new wxPanel(mainPanel, wxID_ANY);
	wxBoxSizer * scoreBoardSizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer * scoreBoardHeaderSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText * str5 = new wxStaticText(scoreBoardPanel, wxID_ANY, "Score Board");
    wxFont font5 = str5->GetFont();
    font5.SetPointSize(14);
    font5.SetWeight(wxFONTWEIGHT_BOLD);
    str5->SetFont(font5);

	scoreBoardHeaderSizer->Add(str5, 0, wxRIGHT, 275);
	scoreBoardSizer->Add(scoreBoardHeaderSizer);

	wxBoxSizer * scoreSizer = new wxBoxSizer(wxVERTICAL);
    wxStaticText * str6 = new wxStaticText(scoreBoardPanel, wxID_ANY, "Player's Score:");
	scoreSizer->Add(str6);
    wxStaticText * str7 = new wxStaticText(scoreBoardPanel, wxID_ANY, "Maeve's Score:");
	scoreSizer->Add(str7);
    wxStaticText * str8 = new wxStaticText(scoreBoardPanel, wxID_ANY, "Draws:");
	scoreSizer->Add(str8);
	scoreBoardSizer->Add(scoreSizer);

	scoreBoardSizer->SetSizeHints(mainPanel);
	scoreBoardPanel->SetSizer(scoreBoardSizer);
	mainSizer->Add(scoreBoardPanel, 0, wxALIGN_CENTER | wxTOP, 30);
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
