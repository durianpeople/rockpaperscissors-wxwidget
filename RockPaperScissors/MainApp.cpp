#include "MainApp.h"
#include "ScreenSplash.h"

#ifdef _DEBUG
#pragma comment(lib, "wxbase31ud.lib")
#else
#pragma comment(lib, "wxbase31u.lib")
#endif

MainApp::MainApp()
{
}

bool MainApp::OnInit() {
	mainFrame = new wxFrame(NULL, wxID_ANY, L"Rock Paper Scissors", wxDefaultPosition, {450,800}, wxCLOSE_BOX | wxCAPTION | wxCLIP_CHILDREN);
	mainFrame->Center();
	mainFrame->SetBackgroundColour(wxColor("black"));
	mainFrame->Show(true);

	ScreenSplash splash(this);
	splash.Init(this);
	splash.StartOnce(1000);

	return true;
}

wxPanel* MainApp::newPanel()
{
	wxPanel* old = nullptr;
	if (currentPanel != nullptr) {
		mainFrame->RemoveChild(currentPanel);
		old = currentPanel;
	}
	currentPanel = new wxPanel(mainFrame, wxID_ANY, wxDefaultPosition, {450,800});
	currentPanel->Show(true);
	mainFrame->Refresh();
	if(old != nullptr) delete old;
	return currentPanel;
}

void MainApp::r() {
	mainFrame->Refresh();
}

wxIMPLEMENT_APP(MainApp);
