#pragma once
#include <wx/wxprec.h>

class App : public wxApp
{
public:
	virtual bool OnInit();
};
enum
{
	ID_MEMORY = 1
};

wxDECLARE_APP(App);
