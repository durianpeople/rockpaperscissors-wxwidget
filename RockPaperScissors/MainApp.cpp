#include <wx/wxprec.h>
#include "MainApp.h"

#ifdef _DEBUG
#pragma comment(lib, "wxbase31ud.lib")
#else
#pragma comment(lib, "wxbase31u.lib")
#endif

MainApp::MainApp()
{
}


MainApp::~MainApp()
{
}

bool MainApp::OnInit() {
	wxFrame* mainFrame = new wxFrame(nullptr, wxID_ANY, wxT("Awesome Rock Paper Scissors"), wxDefaultPosition, wxSize(450, 800));
	mainFrame->Center();
	mainFrame->Show(true);
	return true;
}

wxIMPLEMENT_APP(MainApp);
