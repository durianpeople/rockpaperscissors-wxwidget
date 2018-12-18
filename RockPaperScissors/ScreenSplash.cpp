#include "ScreenSplash.h"
#include "ScreenWelcome.h"

#include "wxImagePanel.h"

ScreenSplash::ScreenSplash(MainApp* main)
{
	panel = main->newPanel();
	panel->SetBackgroundColour(wxColor("GREEN"));
	main->r();
	mainapp = main;
	wxImagePanel* drawPane = new wxImagePanel(
		panel, 
		wxT("E:\\VisualStudio\\RPS\\Debug\\logo_big.png"), 
		wxBITMAP_TYPE_PNG, 
		{ 0,0 },
		{450,800}
	);
	main->r();
}


void ScreenSplash::Notify()
{
	new ScreenWelcome(mainapp);
}

