#pragma once
#include "template_wxheader.h"
#include "Object.h"
#include "FallingObject.h"
#include <list>

class GamePlayActivity :
	public wxPanel
{
	wxWindow* parent;
	
	wxPanel *scorebar, *playview;
	wxTimer *slide_in_ani, *gamestart, *real_time_game, *keyboard_poll, *generate_random;
	Object *bg, *pad1, *pad2, *pad3, *rock, *paper, *scissors;
	std::list<Object*> objects;
	std::list<FallingObject*> fallings;
	int gspap = 0, bmgap = 250, highscore = 0, x_pos, usingKeyboard = NULL, random_interval = 3000, score = 0;

	Object* putObject(Object* o);
	FallingObject* putFalling(FallingObject * o);

	void moveDown();
	void drawFalling();
	void drawGameSet();
	void redraw();
	void setHighScore(int score);
	void generate();
public:
	GamePlayActivity(wxWindow* parent);

	void slide_in_func(wxTimerEvent & event);
	void gamestart_func(wxTimerEvent & event);
	void real_time_game_func(wxTimerEvent & event);
	void generate_random_func(wxTimerEvent & event);

	void keyboard_poll_func(wxTimerEvent & event);

DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(GamePlayActivity, wxPanel)
	EVT_TIMER(31, GamePlayActivity::slide_in_func)
	EVT_TIMER(32, GamePlayActivity::gamestart_func)
	EVT_TIMER(33, GamePlayActivity::real_time_game_func)
	EVT_TIMER(34, GamePlayActivity::keyboard_poll_func)
	EVT_TIMER(35, GamePlayActivity::generate_random_func)
END_EVENT_TABLE()
