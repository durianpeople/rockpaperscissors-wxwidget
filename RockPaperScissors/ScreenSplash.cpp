#include "ScreenSplash.h"
#include "ScreenWelcome.h"

#include "wxImagePanel.h"

float scale = 0;
int left = 0;
int millis = 0;
wxImagePanel* drawPane;

ScreenSplash::ScreenSplash(MainApp* main)
{
	panel = main->newPanel();
	panel->SetBackgroundColour(wxColor("black"));
	main->r();
	mainapp = main;
	drawPane = new wxImagePanel(
		panel, 
		wxT("E:\\VisualStudio\\RPS\\Debug\\splash.png"), 
		wxBITMAP_TYPE_PNG, 
		{ -10,0 },
		{450,800},
		scale
	);
	main->r();
	Start(1);
}


void ScreenSplash::Notify()
{
	millis++;
	if(millis > 50 && scale < 1){
		scale += .033F;
		left += 10;
		drawPane->scale(scale);
	}else if(millis > 150) {
		new ScreenWelcome(mainapp);
		Stop();
	}
}

