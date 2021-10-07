///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.0-4761b0c)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "resource.h"

///////////////////////////////////////////////////////////////////////////

MainWindowVirt::MainWindowVirt( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	m_menu = new wxMenuBar( 0 );
	m_file = new wxMenu();
	wxMenuItem* m_open;
	m_open = new wxMenuItem( m_file, wxID_ANY, wxString( wxT("Open") ) , wxEmptyString, wxITEM_NORMAL );
	m_file->Append( m_open );

	wxMenuItem* m_exit;
	m_exit = new wxMenuItem( m_file, wxID_ANY, wxString( wxT("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	m_file->Append( m_exit );

	m_menu->Append( m_file, wxT("File") );

	m_help = new wxMenu();
	wxMenuItem* m_about;
	m_about = new wxMenuItem( m_help, wxID_ANY, wxString( wxT("About") ) , wxEmptyString, wxITEM_NORMAL );
	m_help->Append( m_about );

	m_menu->Append( m_help, wxT("Help") );

	this->SetMenuBar( m_menu );

	wxBoxSizer* memoryHolder;
	memoryHolder = new wxBoxSizer( wxVERTICAL );

	m_Memory = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_Memory->CreateGrid( 50, 50 );
	m_Memory->EnableEditing( false );
	m_Memory->EnableGridLines( true );
	m_Memory->EnableDragGridSize( false );
	m_Memory->SetMargins( 0, 0 );

	// Columns
	m_Memory->EnableDragColMove( false );
	m_Memory->EnableDragColSize( true );
	m_Memory->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_Memory->EnableDragRowSize( true );
	m_Memory->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_Memory->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	memoryHolder->Add( m_Memory, 0, wxALL, 5 );


	this->SetSizer( memoryHolder );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_file->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindowVirt::OnOpen ), this, m_open->GetId());
	m_file->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindowVirt::OnExit ), this, m_exit->GetId());
	m_help->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindowVirt::OnAbout ), this, m_about->GetId());
}

MainWindowVirt::~MainWindowVirt()
{
	// Disconnect Events

}

AboutPageVirt::AboutPageVirt( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	m_titleText = new wxStaticText( this, wxID_ANY, wxT("Emu6502"), wxPoint( -1,-1 ), wxDefaultSize, 0 );
	m_titleText->Wrap( -1 );
	m_titleText->SetFont( wxFont( 24, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_HEAVY, false, wxT("Arial Black") ) );

	bSizer3->Add( m_titleText, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	m_Author = new wxStaticText( this, wxID_ANY, wxT("By Eli Moore"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Author->Wrap( -1 );
	m_Author->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer3->Add( m_Author, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	m_link = new wxHyperlinkCtrl( this, wxID_ANY, wxT("Github"), wxT("https://github.com/EliMooreVT/6502Emu"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	bSizer3->Add( m_link, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_ok = new wxButton( this, wxID_ANY, wxT("Ok"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_ok, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer3 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AboutPageVirt::OnOK ), NULL, this );
}

AboutPageVirt::~AboutPageVirt()
{
	// Disconnect Events
	m_ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AboutPageVirt::OnOK ), NULL, this );

}
