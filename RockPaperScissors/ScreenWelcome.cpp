#include "ScreenWelcome.h"

ScreenWelcome::ScreenWelcome(MainApp* app)
{
	wxPanel* panel = app->newPanel();
	panel->SetBackgroundColour(wxColor("BLUE"));
	app->r();
}
