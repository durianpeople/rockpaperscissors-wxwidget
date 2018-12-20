#include "GamePlayActivity.h"
#include "RockObject.h"
#include "PaperObject.h"
#include "ScissorsObject.h"
#include <iostream>
#include <iostream>
#include <fstream>
#include <cstdlib>

#ifdef _DEBUG
#pragma comment(lib, "wxbase31ud.lib")
#else
#pragma comment(lib, "wxbase31u.lib")
#endif

void GamePlayActivity::moveDown()
{
	for (FallingObject* it : fallings) {
		it->move();
	}
}

void GamePlayActivity::drawFalling()
{
	for (FallingObject* it : fallings) {
		it->paintNow();
	}
}



void GamePlayActivity::drawGameSet()
{
	bg = putObject(new Object(playview, wxT("..\\res\\bg_gameplay.png"), wxBITMAP_TYPE_PNG, { 0,0 }, { 450,800 }));
	pad1 = putObject(new Object(playview, wxT("..\\res\\pad.png"), wxBITMAP_TYPE_PNG, { -5,570 }, { 160,160 }, .8F));
	pad2 = putObject(new Object(playview, wxT("..\\res\\pad.png"), wxBITMAP_TYPE_PNG, { 140,570 }, { 160,160 }, .8F));
	pad3 = putObject(new Object(playview, wxT("..\\res\\pad.png"), wxBITMAP_TYPE_PNG, { 290,570 }, { 160,160 }, .8F));
	
	rock = putObject(new Object(playview, wxT("..\\res\\rock.png"), wxBITMAP_TYPE_PNG, { -5,570 }, { 150,150 }));
	paper = putObject(new Object(playview, wxT("..\\res\\paper.png"), wxBITMAP_TYPE_PNG, { 145,570 }, { 150,150 }));
	scissors = putObject(new Object(playview, wxT("..\\res\\scissors.png"), wxBITMAP_TYPE_PNG, { 290,570 }, { 150,150 }));
}

Object * GamePlayActivity::putObject(Object * o)
{
	objects.push_back(o);
	return o;
}

FallingObject * GamePlayActivity::putFalling(FallingObject * o) {
	fallings.push_back(o);
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
	scorebar = new wxPanel(this, wxID_ANY, { 0,0 }, { 450,50 });
	playview = new wxPanel(this, wxID_ANY, { 0,50 }, { 450,750 });

	drawGameSet();

	slide_in_ani = new wxTimer(this, 31);
	gamestart = new wxTimer(this, 32);
	real_time_game = new wxTimer(this, 33);
	keyboard_poll = new wxTimer(this, 34);
	generate_random = new wxTimer(this, 35);

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
			generate();
			real_time_game->Start(50);
			generate_random->Start(1000);
			keyboard_poll->Start(30);
		}
		break;
	}
	redraw();
	gspap += gspap >= 2 ? -2 : 1;
}

void GamePlayActivity::real_time_game_func(wxTimerEvent & event)
{
	moveDown();
	auto a = fallings.front();
	if (a->GetPosition().y >= 440) {
		switch (a->getLane()) {
		case 0:
			if (a->collideWith(pad1)) {
				redraw();
				drawFalling();
			}
			break;
		case 1:
			if (a->collideWith(pad2)) {
				redraw();
				drawFalling();
			}
			break;
		case 2:
			if (a->collideWith(pad3)) {
				redraw();
				drawFalling();
			}
			break;
		}
		if (a->GetPosition().y >= 590) {
			a->Destroy();
			fallings.pop_front();
		}
	}
}

void GamePlayActivity::generate_random_func(wxTimerEvent & event)
{
	generate();
}

void GamePlayActivity::keyboard_poll_func(wxTimerEvent & event)
{
	keyboard_poll->Stop();
	if (!usingKeyboard) {
		if (wxGetKeyState(wxKeyCode('A'))) {
			pad1->scale(1,false);
			usingKeyboard = 1;
			redraw();
			drawFalling();
		}
		else if (wxGetKeyState(wxKeyCode('S'))) {
			pad2->scale(1, false);
			usingKeyboard = 2;
			redraw();
			drawFalling();
		}
		else if (wxGetKeyState(wxKeyCode('D'))) {
			pad3->scale(1, false);
			usingKeyboard = 3;
			redraw();
			drawFalling();
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
			drawFalling();
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

void GamePlayActivity::generate()
{
	if (!fallings.empty()) {
		auto a = fallings.back();
		if (a->GetPosition().y < 150) return;
	}
	int type = rand() % 3;
	int lane = rand() % 3;
	switch (type) {
	case 0:
		putFalling(new RockObject(playview, lane));
		break;
	case 1:
		putFalling(new PaperObject(playview, lane));
		break;
	case 2:
		putFalling(new ScissorsObject(playview, lane));
		break;
	}
}
