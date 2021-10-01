#include <wx/wxprec.h>
#include <wx/xml/xml.h>
#include <wx/xrc/xmlres.h>
#include "App.h"
#include "resource.h"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	MainWindow* frame = new MainWindow(NULL);
	frame->Show(true);

	return true;
}
