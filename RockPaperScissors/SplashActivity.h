#pragma once
#include "template_wxheader.h"
#include "Object.h"

class SplashActivity :
	public wxPanel
{
	wxWindow* parent;
	wxTimer *timer1, *animation;
	Object* bg;
	
	float scale = 0;
public:
	SplashActivity(wxWindow* parent);

	//Timer function
	void nextActivity(wxTimerEvent& event);
	void anicall(wxTimerEvent& event);

DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(SplashActivity, wxPanel)
	EVT_TIMER(12, SplashActivity::nextActivity)
	EVT_TIMER(11, SplashActivity::anicall)
END_EVENT_TABLE()