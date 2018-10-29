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
    RpsFrame *frame = new RpsFrame("RPS", wxPoint(500, 200), wxSize(400, 680));
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


    // INPUT BOX 
    wxPanel* panel = new wxPanel(this, -1);
    // wxTextCtrl* text = new wxTextCtrl(panel, 1, "");

    // wxBoxSizer* panelSizer = new wxBoxSizer(wxVERTICAL);
    // panelSizer->Add(text, wxSizerFlags().Center());
    // panel->SetSizer(panelSizer);

    // wxBoxSizer* frameSizer = new wxBoxSizer(wxVERTICAL);
    // frameSizer->Add(panel, wxSizerFlags().Expand());
    // SetSizer(frameSizer);  


	// MENU BAR 
	wxMenuBar * menuBar = new wxMenuBar;
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuHelp, "&Help");
	SetMenuBar(menuBar);
	CreateStatusBar();
	SetStatusText("Welcome to wxWidgets!");


    //wxSize title = new wxSize(5, 5); 
    // ROUNDS 
    wxStaticText * str9 = new wxStaticText(panel, wxID_ANY, "Round Number:", 
    wxPoint(130, 20), wxDefaultSize, wxALIGN_CENTER);

    // BACKGROUND 
    wxColour col1;
    col1.Set(wxT("#c2d4dd"));
    panel->SetBackgroundColour(col1);


	// RPS buttons
    wxStaticText * str1 = new wxStaticText(panel, wxID_ANY, "Player Selects:", 
        wxPoint(60, 80), wxDefaultSize, wxALIGN_LEFT); 
    wxButton * rockButton = new wxButton(this, BUTTON_Rock, "Rock", 
        wxPoint(60, 110), wxDefaultSize, 0); // Default Size = (-1, -1)
    wxButton * scissorButton = new wxButton(this, BUTTON_Scissor, "Scissor",
        wxPoint(160, 110), wxDefaultSize, 0);
    wxButton * paperButton = new wxButton(this, BUTTON_Paper, "Paper",
        wxPoint(260, 110), wxDefaultSize, 0);

    // ADD IMAGE
    // wxPNGHandler *handler = new wxPNGHandler;
    // wxImage::AddHandler(handler);
    // wxStaticBitmap *image;
    // image = new wxStaticBitmap(this, wxID_ANY, wxBitmap("Windows_7_logo.png", wxBITMAP_TYPE_PNG), 
    //     wxPoint(50,100), wxSize(100, 500));


    // MAEVE'S SELECTION
    wxStaticText * str2 = new wxStaticText(panel, wxID_ANY, "Maeve Selects:", 
    wxPoint(60, 160), wxDefaultSize, wxALIGN_LEFT);

    // LINE 
    // wxStaticLine *sl1 = new wxStaticLine(this, wxID_ANY, wxPoint(60, 185), 
    // wxSize(340,1));

    // ROUND'S WINNER
    wxStaticText * str4 = new wxStaticText(panel, wxID_ANY, "Winner:", 
    wxPoint(60, 240), wxDefaultSize, wxALIGN_LEFT);

    // SCORE BOARD 
    wxStaticText * str5 = new wxStaticText(panel, wxID_ANY, "Score Board", 
    wxPoint(60, 290), wxDefaultSize, wxALIGN_LEFT);

    wxStaticText * str6 = new wxStaticText(panel, wxID_ANY, "Player's Score:", 
    wxPoint(60, 310), wxDefaultSize, wxALIGN_LEFT);
    wxStaticText * str7 = new wxStaticText(panel, wxID_ANY, "Maeve's Score:", 
    wxPoint(60, 330), wxDefaultSize, wxALIGN_LEFT);
    wxStaticText * str8 = new wxStaticText(panel, wxID_ANY, "Draws:", 
    wxPoint(60, 350), wxDefaultSize, wxALIGN_LEFT);
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
