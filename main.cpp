#include "main.h"
#include "GUIMyFrame1.h"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	SetProcessDPIAware();
	wxFrame* mainFrame = new GUIMyFrame1(NULL);
	mainFrame->Show(true);
	SetTopWindow(mainFrame);

	return true;
}