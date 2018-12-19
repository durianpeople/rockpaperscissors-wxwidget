#pragma once
#include "template_wxheader.h"

class HighScoreActivity : public wxPanel
{
public:
	wxWindow *parent;
public:
	HighScoreActivity(wxWindow* parent);

	//Button Function
	void back(wxCommandEvent& event);
	DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(HighScoreActivity, wxPanel)
EVT_BUTTON(31, HighScoreActivity::back)
END_EVENT_TABLE()
