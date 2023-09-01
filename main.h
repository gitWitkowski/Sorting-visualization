#pragma once
#include <wx/wxprec.h>

class MyApp : public wxApp {

public:

	virtual bool OnInit();
	virtual int OnExit() { return 0; }

};

wxDECLARE_APP(MyApp);