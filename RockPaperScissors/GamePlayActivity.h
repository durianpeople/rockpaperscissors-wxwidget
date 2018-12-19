#pragma once
#include "template_wxheader.h"
#include "Object.h"

class GamePlayActivity :
	public wxPanel
{
	wxWindow* parent;
	
	wxPanel *scorebar;
	wxTimer *slide_in_ani, *gamestart;
	Object *bg, *pad1, *pad2, *pad3, *rock, *paper, *scissors;

	int x_pos = 450, gspap = 0, bmgap = 250;
	void drawGameSet();
public:
	GamePlayActivity(wxWindow* parent);

	void slide_in_func(wxTimerEvent & event);
	void gamestart_func(wxTimerEvent & event);

DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(GamePlayActivity, wxPanel)
	EVT_TIMER(31, GamePlayActivity::slide_in_func)
	EVT_TIMER(32, GamePlayActivity::gamestart_func)
END_EVENT_TABLE()
