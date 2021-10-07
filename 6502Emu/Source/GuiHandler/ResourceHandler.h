#pragma once
#include "resource.h"

class AboutPage : public AboutPageVirt
{
	using AboutPageVirt::AboutPageVirt;
public:

protected:
	virtual void OnOK(wxCommandEvent& event);
};

class MainWindow : public MainWindowVirt
{
	using MainWindowVirt::MainWindowVirt;
public:
	void SetupMemory();


protected:
	virtual void OnExit(wxCommandEvent& event);
	virtual void OnAbout(wxCommandEvent& event);
	virtual void OnOpen(wxCommandEvent& event);

	AboutPage * m_about;
};

