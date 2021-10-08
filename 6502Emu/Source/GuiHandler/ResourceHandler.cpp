#include "ResourceHandler.h"
#include <wx/filedlg.h>
#include <wx/wfstream.h>
#include "GuiHandler.h"
#include "Common/Utils.h"
#include <string>

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
	GuiData::Function::OpenFile(fileDlg.GetPath().ToStdString());
	m_Memory->SetColLabelValue(0, Utils::hexString(GuiData::Function::GetPC()));
}


void AboutPage::OnOK(wxCommandEvent& event)
{
	Close(true);
}
