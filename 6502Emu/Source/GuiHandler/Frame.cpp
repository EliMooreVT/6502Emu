#include "frame.h"
#include <wx/xrc/xmlres.h>
#include <wx/xml/xml.h>

Frame::Frame() : wxFrame(NULL, 0, "Hello")
{
	
	wxXmlResource::Get()->InitAllHandlers();
	wxXmlResource::Get()->Load("Resource.rc");
}

