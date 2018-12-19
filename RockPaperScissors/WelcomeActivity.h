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
	void highscore(wxCommandEvent& event);

DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(WelcomeActivity, wxPanel)
	EVT_BUTTON(21, WelcomeActivity::playnow)
	EVT_BUTTON(22, WelcomeActivity::highscore)
END_EVENT_TABLE()
