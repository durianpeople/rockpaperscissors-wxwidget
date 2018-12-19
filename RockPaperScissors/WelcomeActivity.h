#pragma once
#include "template_wxheader.h"

class WelcomeActivity :
	public wxPanel
{
	wxWindow *parent;
public:
	WelcomeActivity(wxWindow* parent);

	//Button Function
	void playnow(wxCommandEvent& event);

DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(WelcomeActivity, wxPanel)
	EVT_BUTTON(21, WelcomeActivity::playnow)
END_EVENT_TABLE()
