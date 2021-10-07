#include <wx/wxprec.h>
#include <wx/xml/xml.h>
#include <wx/xrc/xmlres.h>
#include <wx/grid.h>
#include "App.h"
#include "resource.h"

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
#include "ResourceHandler.h"


wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	MainWindow * mainWindow = new MainWindow(NULL);
	mainWindow->Show(true);
	return true;
}
