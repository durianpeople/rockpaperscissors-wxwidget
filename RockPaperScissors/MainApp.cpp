#include "MainApp.h"
#include "SplashActivity.h"

#ifdef _DEBUG
#pragma comment(lib, "wxbase31ud.lib")
#else
#pragma comment(lib, "wxbase31u.lib")
#endif

bool MainApp::OnInit() {
	wxDisableAsserts();
	wxInitAllImageHandlers();
	mainFrame = new wxFrame(NULL, wxID_ANY, L"Rock Paper Scissors", wxDefaultPosition, {450,800}, wxCLOSE_BOX | wxCAPTION | wxCLIP_CHILDREN);
	mainFrame->Center();
	mainFrame->SetBackgroundColour(wxColor("black"));

	(new SplashActivity(mainFrame))->Show();
	mainFrame->Refresh();

	return true;
}

wxIMPLEMENT_APP(MainApp);
