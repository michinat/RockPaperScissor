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
    RpsFrame * frame = new RpsFrame("RPS", wxPoint(500, 200), wxSize(900, 680));
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
    menuFile->Append(MENU_NewGame, "&Start a New Game\tCtrl-N", 
        "Go back to round 1 and face Maeve!");
    menuFile->AppendSeparator();
    menuFile->Append(MENU_Exit);
    
    wxMenu * menuSetting = new wxMenu;
    menuSetting->Append(MENU_SetRound, "&Set Max Rounds",
        "Default max rounds is 20");

    wxMenu * menuHelp = new wxMenu;
    menuHelp->Append(MENU_About, "&About",
        ":)");

    wxMenuBar * menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuSetting, "&Settings");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);
    CreateStatusBar();

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

    // interface facade updates dynamic UI elements of subpanels
    interfaceHandler = new InterfaceHandler(
        roundPanel->getRoundScoreText(), rpsButtonPanel->getPlayerSelectionText(), maevePanel->getMaevePredictedScoreText(), maevePanel->getMaeveSelectScoreText(), 
        roundWinnerPanel->getWinnerNameText(), scoreBoardPanel->getPlayerScoreText(), scoreBoardPanel->getMaeveScoreText(), scoreBoardPanel->getDrawScoreText());
}

// ----------------------------------------------------------------------------
// event tables and other macros for wxWidgets
// ----------------------------------------------------------------------------

// the event tables connect the wxWidgets events with the functions (event
// handlers) which process them. It can be also done at run-time, but for the
// simple menu events like this the static method is much simpler.
BEGIN_EVENT_TABLE(RpsFrame, wxFrame)
    EVT_MENU(MENU_NewGame, RpsFrame::OnNewGame)
    EVT_MENU(MENU_Exit, RpsFrame::OnExit)
    EVT_MENU(MENU_SetRound, RpsFrame::OnSetRounds)
    EVT_MENU(MENU_About, RpsFrame::OnAbout)
    EVT_CLOSE(RpsFrame::OnClose)
    EVT_BUTTON(BUTTON_Rock, RpsFrame::OnRockPressed)
    EVT_BUTTON(BUTTON_Paper, RpsFrame::OnPaperPressed)
    EVT_BUTTON(BUTTON_Scissor, RpsFrame::OnScissorPressed)
END_EVENT_TABLE()

// ----------------------------------------------------------------------------
// main frame implementation
// ----------------------------------------------------------------------------

void RpsFrame::OnNewGame(wxCommandEvent& event)
{
    interfaceHandler->newGame();
}

void RpsFrame::OnExit(wxCommandEvent & event)
{
    wxDELETE(interfaceHandler);
    Close(true);
}

void RpsFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This application was built on Fall 2018 for our CMPE 135 class. Thank you for using our RPS application - CraZ CoderZ\n\nDanny Nuch\nLinda Nguyen\nPreyrna Yadav\nMichelle Nguyen",
        "About", 0);
}

void RpsFrame::OnSetRounds(wxCommandEvent& event)
{
    static long rounds_input = interfaceHandler->getMaxRounds();

    wxString rounds;
    rounds.Printf(wxT("%ld"), rounds_input);

    rounds = wxGetTextFromUser(wxT("How many rounds do you want per game?"),
        wxT("Set max rounds per game"),
        rounds,
        this);

    if (!rounds)
        return; // cancelled button pressed

    wxSscanf(rounds, wxT("%ld"), &rounds_input);
    interfaceHandler->setMaxRounds(rounds_input);
}

void RpsFrame::OnRockPressed(wxCommandEvent& event)
{
    interfaceHandler->humanMadeSelection(selection_t::ROCK);
}

void RpsFrame::OnScissorPressed(wxCommandEvent& event)
{
    interfaceHandler->humanMadeSelection(selection_t::SCISSOR);
}

void RpsFrame::OnPaperPressed(wxCommandEvent& event)
{
    interfaceHandler->humanMadeSelection(selection_t::PAPER);
}

void RpsFrame::OnClose(wxCloseEvent & event)
{
    wxDELETE(interfaceHandler);
    event.Skip();
}
