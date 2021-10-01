///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.0-4761b0c)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "Resource.h"
#include "Common/Utils.h"

///////////////////////////////////////////////////////////////////////////

MainWindow::MainWindow( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	m_menu = new wxMenuBar( 0 );
	m_file = new wxMenu();
	wxMenuItem* m_open;
	m_open = new wxMenuItem( m_file, wxID_OPEN, wxString( wxT("Open") ) , wxEmptyString, wxITEM_NORMAL );
	m_file->Append(m_open);

	wxMenuItem* m_exit;
	m_exit = new wxMenuItem( m_file, wxID_EXIT, wxString( wxT("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	m_file->Append( m_exit );

	m_menu->Append( m_file, wxT("File") );

	m_help = new wxMenu();
	wxMenuItem* m_about;
	m_about = new wxMenuItem( m_help, wxID_ABOUT, wxString( wxT("About") ) , wxEmptyString, wxITEM_NORMAL );
	m_help->Append( m_about );

	m_menu->Append( m_help, wxT("Help") );

	this->SetMenuBar( m_menu );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 0, 2, 0, 0 );

	Memory = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );

	// Grid
	Memory->CreateGrid( 50, 50 );
	Memory->EnableEditing( false );
	Memory->EnableGridLines( true );
	Memory->EnableDragGridSize( false );
	Memory->SetMargins( 0, 0 );

	// Columns
	for (int i = 0; i < 50; i++)
	{
		Memory->SetColSize( 0, 20 );
	}
	Memory->EnableDragColMove( false );
	Memory->EnableDragColSize( true );
	Memory->SetColLabelSize( 0 );
	Memory->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	Memory->SetRowSize( 0, 20 );
	Memory->EnableDragRowSize( true );
	for (int i = 0; i < 2500; i += 50)
	{
		Memory->SetRowLabelValue( i/50, wxT("", Utils::hexString(i)));
	}
	Memory->SetRowLabelSize( 40 );
	Memory->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	Memory->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	gSizer1->Add( Memory, 0, 0, 5 );


	bSizer1->Add( gSizer1, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	Bind(wxEVT_MENU, &MainWindow::OnOpen, this, wxID_OPEN);
	Bind(wxEVT_MENU, &MainWindow::OnExit, this, wxID_EXIT);
	Bind(wxEVT_MENU, &MainWindow::OnAbout, this, wxID_ABOUT);
	

}

MainWindow::~MainWindow()
{
}

void MainWindow::OnOpen(wxCommandEvent& event)
{
}

void MainWindow::OnExit(wxCommandEvent& event)
{
	Close(true);
}

void MainWindow::OnAbout(wxCommandEvent& event)
{
	AboutPage * about = new AboutPage(this);
	about->ShowModal();
}

AboutPage::AboutPage( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	m_titleText = new wxStaticText( this, wxID_ANY, wxT("6502Emu"), wxPoint( -1,-1 ), wxDefaultSize, 0 );
	m_titleText->Wrap( -1 );
	m_titleText->SetFont( wxFont( 24, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_HEAVY, false, wxT("Arial Black") ) );

	bSizer3->Add( m_titleText, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	m_Author = new wxStaticText( this, wxID_ANY, wxT("By Eli Moore"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Author->Wrap( -1 );
	m_Author->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer3->Add( m_Author, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	m_link = new wxHyperlinkCtrl( this, wxID_ANY, wxT("Github"), wxT("https://github.com/EliMooreVT/6502Emu"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	bSizer3->Add( m_link, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_ok = new wxButton( this, wxID_OK, wxT("Ok"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_ok, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer3 );
	this->Layout();

	this->Centre( wxBOTH );

	Bind(wxEVT_MENU, &AboutPage::OnOK, this, wxID_OK);
}

AboutPage::~AboutPage()
{
}

void AboutPage::OnOK(wxCommandEvent& event)
{
	Close(true);
}
