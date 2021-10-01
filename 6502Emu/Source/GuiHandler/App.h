#pragma once
#include <wx/wxprec.h>

class App : public wxApp
{
public:
	virtual bool OnInit();
};

wxDECLARE_APP(App);
