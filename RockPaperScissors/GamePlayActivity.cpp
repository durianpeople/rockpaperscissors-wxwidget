#include "GamePlayActivity.h"
#include <iostream>
#include <iostream>
#include <fstream>

#ifdef _DEBUG
#pragma comment(lib, "wxbase31ud.lib")
#else
#pragma comment(lib, "wxbase31u.lib")
#endif

void GamePlayActivity::drawGameSet()
{
	bg = putObject(new Object(this, wxT("..\\res\\bg_gameplay.png"), wxBITMAP_TYPE_PNG, { 0,0 }, { 450,800 }));
	pad1 = putObject(new Object(this, wxT("..\\res\\pad.png"), wxBITMAP_TYPE_PNG, { -5,620 }, { 160,160 }, .8F));
	pad2 = putObject(new Object(this, wxT("..\\res\\pad.png"), wxBITMAP_TYPE_PNG, { 140,620 }, { 160,160 }, .8F));
	pad3 = putObject(new Object(this, wxT("..\\res\\pad.png"), wxBITMAP_TYPE_PNG, { 290,620 }, { 160,160 }, .8F));
	
	rock = putObject(new Object(this, wxT("..\\res\\rock.png"), wxBITMAP_TYPE_PNG, { -5,620 }, { 150,150 }));
	paper = putObject(new Object(this, wxT("..\\res\\paper.png"), wxBITMAP_TYPE_PNG, { 145,620 }, { 150,150 }));
	scissors = putObject(new Object(this, wxT("..\\res\\scissors.png"), wxBITMAP_TYPE_PNG, { 290,620 }, { 150,150 }));
}

Object * GamePlayActivity::putObject(Object * o)
{
	objects.push_back(o);
	return o;
}

void GamePlayActivity::redraw()
{
	for (Object* it : objects) {
		it->paintNow();
	}
}

GamePlayActivity::GamePlayActivity(wxWindow* parent) :
	wxPanel(parent, wxID_ANY, { 450,0 }, { 450,800 })
{
	this->parent = parent;
	drawGameSet();

	slide_in_ani = new wxTimer(this, 31);
	gamestart = new wxTimer(this, 32);
	real_time_game = new wxTimer(this, 33);
	keyboard_poll = new wxTimer(this, 34);

	this->GetPosition(&x_pos, NULL);
	slide_in_ani->Start(2);
}

void GamePlayActivity::slide_in_func(wxTimerEvent & event)
{
	this->Move({ x_pos - 25 ,0 });
	this->GetPosition(&x_pos, NULL);
	if (x_pos <= 0) {
		slide_in_ani->Stop();
		gamestart->Start(bmgap);
	}
}

void GamePlayActivity::gamestart_func(wxTimerEvent & event)
{
	switch (gspap) {
	case 0:
		pad1->scale(1,false);
		pad2->scale(.8F, false);
		pad3->scale(.8F, false);
		break;
	case 1:
		pad1->scale(.8F, false);
		pad2->scale(1, false);
		pad3->scale(.8F, false);
		break;
	case 2:
		pad1->scale(.8F, false);
		pad2->scale(.8F, false);
		pad3->scale(1, false);
		bmgap-=bmgap/4;
		gamestart->Stop();
		if (bmgap > 50) {
			gamestart->Start(bmgap);
		}
		else {
			pad1->scale(.8F, false);
			pad2->scale(.8F, false);
			pad3->scale(.8F, false);
			//real_time_game->Start(1);
			keyboard_poll->Start(30);
		}
		break;
	}
	redraw();
	gspap += gspap >= 2 ? -2 : 1;
}

void GamePlayActivity::real_time_game_func(wxTimerEvent & event)
{
	
}

void GamePlayActivity::keyboard_poll_func(wxTimerEvent & event)
{
	keyboard_poll->Stop();
	if (!usingKeyboard) {
		if (wxGetKeyState(wxKeyCode('A'))) {
			pad1->scale(1,false);
			usingKeyboard = 1;
			redraw();
		}
		else if (wxGetKeyState(wxKeyCode('S'))) {
			pad2->scale(1, false);
			usingKeyboard = 2;
			redraw();
		}
		else if (wxGetKeyState(wxKeyCode('D'))) {
			pad3->scale(1, false);
			usingKeyboard = 3;
			redraw();
		}
	}
	else {
		if (!(wxGetKeyState(wxKeyCode('A')) || wxGetKeyState(wxKeyCode('S')) || wxGetKeyState(wxKeyCode('D')))) {
			if (usingKeyboard == 1) {
				pad1->scale(.8F, false);
			}
			else if (usingKeyboard == 2) {
				pad2->scale(.8F, false);
			}
			else if (usingKeyboard == 3) {
				pad3->scale(.8F, false);
			}
			redraw();
			usingKeyboard = NULL;
		}
	}
	keyboard_poll->Start(30);
}

void GamePlayActivity::setHighScore(int score)
{
	highscore = score;
	std::ofstream file;
	file.open("..\\res\\file.txt");
	file << highscore;
	file.close();
}