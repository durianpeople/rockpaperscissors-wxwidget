#include "ScreenSplash.h"
#include "ScreenWelcome.h"

ScreenSplash::ScreenSplash(MainApp* main)
{
	panel = main->newPanel();
	panel->SetBackgroundColour(wxColor("GREEN"));
	main->r();
	mainapp = main;
}


void ScreenSplash::Notify()
{
	new ScreenWelcome(mainapp);
}

