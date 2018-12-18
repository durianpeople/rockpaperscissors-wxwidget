#include "ScreenSplash.h"
#include "ScreenWelcome.h"

#include "wxImagePanel.h"

ScreenSplash::ScreenSplash(MainApp* main)
{
	panel = main->newPanel();
	panel->SetBackgroundColour(wxColor("BLUE"));
	wxPanel* f = new wxPanel(panel, wxID_ANY, wxDefaultPosition, { 200,200 });
	f->SetBackgroundColour(wxColor("GREEN"));
	f->Show();
	main->r();
	mainapp = main;
	wxImagePanel* drawPane = new wxImagePanel(panel, wxT("E:\\VisualStudio\\RPS\\Debug\\logo_big.png"), wxBITMAP_TYPE_PNG, { 0,0 },{200,200});
	main->r();
}


void ScreenSplash::Notify()
{
	//new ScreenWelcome(mainapp);
}

