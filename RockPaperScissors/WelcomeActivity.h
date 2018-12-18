#pragma once
#include "template_wxheader.h"

class WelcomeActivity :
	public wxPanel
{
	wxWindow* parent;
	wxTimer* closet;
public:
	WelcomeActivity(wxWindow* parent);
	void close(wxTimerEvent& event);
};

