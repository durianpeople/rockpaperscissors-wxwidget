#include "MainApp.h"
#include "DrawablePanel.h"
#include "FallingMovable.h"

#ifdef _DEBUG
#pragma comment(lib, "wxbase31ud.lib")
#else
#pragma comment(lib, "wxbase31u.lib")
#endif

MainApp::MainApp()
{
}

bool MainApp::OnInit() {
	wxInitAllImageHandlers();
	mainFrame = new wxFrame(NULL, wxID_ANY, L"Rock Paper Scissors", wxDefaultPosition, {450,800}, wxCLOSE_BOX | wxCAPTION | wxCLIP_CHILDREN);
	mainFrame->Center();
	mainFrame->SetBackgroundColour(wxColor("black"));

	DrawablePanel* drawable = new DrawablePanel(mainFrame, wxID_ANY, wxDefaultPosition, { 450,800 });
	MovableObject* fallingGreen = new FallingMovable(wxDefaultPosition, { 10,10 });
	drawable->registerObject(fallingGreen);

	mainFrame->Show();
	return true;
}

wxIMPLEMENT_APP(MainApp);
