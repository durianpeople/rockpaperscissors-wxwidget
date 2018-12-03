#include <wx/wxprec.h>
#include "MainApp.h"
#include "MainFrame.h"
#include "HomePanel.h"

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
	wxFrame* mainFrame = new MainFrame();
	
	wxPanel* mainPanel = new HomePanel(mainFrame);
	
	mainFrame->Show(true);
	
	return true;
}

wxIMPLEMENT_APP(MainApp);
