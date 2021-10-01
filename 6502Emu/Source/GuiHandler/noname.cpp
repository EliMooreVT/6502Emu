///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.0-4761b0c)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "noname.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	m_menubar1 = new wxMenuBar( 0 );
	m_file = new wxMenu();
	wxMenuItem* m_open;
	m_open = new wxMenuItem( m_file, wxID_ANY, wxString( wxT("Open") ) , wxEmptyString, wxITEM_NORMAL );
	m_file->Append( m_open );

	wxMenuItem* m_exit;
	m_exit = new wxMenuItem( m_file, wxID_ANY, wxString( wxT("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	m_file->Append( m_exit );

	m_menubar1->Append( m_file, wxT("File") );

	m_help = new wxMenu();
	wxMenuItem* m_about;
	m_about = new wxMenuItem( m_help, wxID_ANY, wxString( wxT("About") ) , wxEmptyString, wxITEM_NORMAL );
	m_help->Append( m_about );

	m_menubar1->Append( m_help, wxT("Help") );

	this->SetMenuBar( m_menubar1 );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 0, 2, 0, 0 );

	Memory = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );

	// Grid
	Memory->CreateGrid( 100, 100 );
	Memory->EnableEditing( false );
	Memory->EnableGridLines( true );
	Memory->EnableDragGridSize( false );
	Memory->SetMargins( 0, 0 );

	// Columns
	Memory->SetColSize( 0, 20 );
	Memory->EnableDragColMove( false );
	Memory->EnableDragColSize( true );
	Memory->SetColLabelSize( 0 );
	Memory->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	Memory->SetRowSize( 0, 20 );
	Memory->EnableDragRowSize( true );
	Memory->SetRowLabelValue( 0, wxT("0x") );
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
}

MyFrame1::~MyFrame1()
{
}

m_aboutPage::m_aboutPage( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
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

	m_hyperlink1 = new wxHyperlinkCtrl( this, wxID_ANY, wxT("Github"), wxT("https://github.com/EliMooreVT/6502Emu"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	bSizer3->Add( m_hyperlink1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_button1 = new wxButton( this, wxID_ANY, wxT("Ok"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer3 );
	this->Layout();

	this->Centre( wxBOTH );
}

m_aboutPage::~m_aboutPage()
{
}
