///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.0-4761b0c)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/grid.h>
#include <wx/sizer.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/hyperlink.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MainWindowVirt
///////////////////////////////////////////////////////////////////////////////
class MainWindowVirt : public wxFrame
{
	private:

	protected:
		enum
		{
			ID_MAIN = 1000
		};

		wxMenuBar* m_menu;
		wxMenu* m_file;
		wxMenu* m_help;

		// Virtual event handlers, override them in your derived class
		virtual void OnOpen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ) { event.Skip(); }


	public:
		wxGrid* m_Memory;

		MainWindowVirt( wxWindow* parent, wxWindowID id = ID_MAIN, const wxString& title = wxT("Emu6502"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 867,593 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MainWindowVirt();

};

///////////////////////////////////////////////////////////////////////////////
/// Class AboutPageVirt
///////////////////////////////////////////////////////////////////////////////
class AboutPageVirt : public wxDialog
{
	private:

	protected:
		wxStaticText* m_titleText;
		wxStaticText* m_Author;
		wxHyperlinkCtrl* m_link;
		wxButton* m_ok;

		// Virtual event handlers, override them in your derived class
		virtual void OnOK( wxCommandEvent& event ) { event.Skip(); }


	public:

		AboutPageVirt( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("About"), const wxPoint& pos = wxPoint( -1,-1 ), const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_DIALOG_STYLE );

		~AboutPageVirt();

};

