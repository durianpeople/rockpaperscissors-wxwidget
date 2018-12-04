#include <wx/wxprec.h>
#include "MainApp.h"
#include "MainFrame.h"
#include "DrawablePanel.h"

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
	wxPanel* panel = new DrawablePanel(mainFrame, wxID_ANY, wxDefaultPosition, wxDefaultSize);
	panel->SetBackgroundColour(wxColor("green"));
	
	mainFrame->Show(true);
	
	return true;
}

wxIMPLEMENT_APP(MainApp);
