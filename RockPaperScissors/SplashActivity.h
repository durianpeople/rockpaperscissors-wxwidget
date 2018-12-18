#pragma once
#include "template_wxheader.h"
#include "Object.h"

class SplashActivity :
	public wxPanel
{
	wxWindow* parent;
	wxTimer* timer1;

	float scale = 0;
	wxTimer* animation;
	Object* bg;
public:
	SplashActivity(wxWindow* parent);
	void nextActivity(wxTimerEvent& event);
	void anicall(wxTimerEvent& event);

DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(SplashActivity, wxPanel)
	EVT_TIMER(12, SplashActivity::nextActivity)
	EVT_TIMER(11, SplashActivity::anicall)
END_EVENT_TABLE()