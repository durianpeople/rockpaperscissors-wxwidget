#pragma once
#include "template_wxheader.h"
#include "Object.h"
#include <vector>

class GamePlayActivity :
	public wxPanel
{
	wxWindow* parent;
	
	wxPanel *scorebar;
	wxTimer *slide_in_ani, *gamestart, *real_time_game;
	Object *bg, *pad1, *pad2, *pad3, *rock, *paper, *scissors;
	std::vector<Object*> objects;

	int x_pos = 450, gspap = 0, bmgap = 250;
	void drawGameSet();
	Object* putObject(Object* o);
public:
	GamePlayActivity(wxWindow* parent);

	void slide_in_func(wxTimerEvent & event);
	void gamestart_func(wxTimerEvent & event);
	void real_time_game_func(wxTimerEvent & event);

	void keydown_func(wxKeyEvent& event);
	void keyup_func(wxKeyEvent& event);

DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(GamePlayActivity, wxPanel)
	EVT_TIMER(31, GamePlayActivity::slide_in_func)
	EVT_TIMER(32, GamePlayActivity::gamestart_func)
	EVT_TIMER(33, GamePlayActivity::real_time_game_func)
END_EVENT_TABLE()
