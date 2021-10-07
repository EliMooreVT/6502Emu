#include "ResourceHandler.h"
#include <wx/filedlg.h>
#include <wx/wfstream.h>

void MainWindow::SetupMemory()
{
	
}

void MainWindow::OnExit(wxCommandEvent& event)
{
	Close(true);
}

void MainWindow::OnAbout(wxCommandEvent& event)
{
	m_about = new AboutPage(this);
	m_about->Show(true);
}

void MainWindow::OnOpen(wxCommandEvent& event)
{
	wxFileDialog fileDlg(this, _("Open ASM file"), "", "");
	if (fileDlg.ShowModal() == wxID_CANCEL)
		return;

	wxFileInputStream input_stream(fileDlg.GetPath());
	if (!input_stream.IsOk())
	{
		return;
	}
}


void AboutPage::OnOK(wxCommandEvent& event)
{
	Close(true);
}
