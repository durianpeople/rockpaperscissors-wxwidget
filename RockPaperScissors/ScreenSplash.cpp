#include "ScreenSplash.h"
#include "ScreenWelcome.h"

ScreenSplash::ScreenSplash(MainApp* main)
{
	panel = main->newPanel();
	panel->SetBackgroundColour(wxColor("GREEN"));
	main->r();
	mainapp = main;
	new ScreenWelcome(mainapp);
}


void ScreenSplash::Notify()
{
	int i = 0;
}

