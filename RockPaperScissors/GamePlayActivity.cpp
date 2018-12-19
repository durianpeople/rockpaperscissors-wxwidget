#include "GamePlayActivity.h"

#ifdef _DEBUG
#pragma comment(lib, "wxbase31ud.lib")
#else
#pragma comment(lib, "wxbase31u.lib")
#endif

void GamePlayActivity::drawGameSet()
{
	bg = new Object(this, wxT("..\\res\\bg_gameplay.png"), wxBITMAP_TYPE_PNG, { 0,0 }, { 450,800 });
	pad1 = new Object(this, wxT("..\\res\\pad.png"), wxBITMAP_TYPE_PNG, { -5,620 }, { 160,160 }, .8F);
	pad2 = new Object(this, wxT("..\\res\\pad.png"), wxBITMAP_TYPE_PNG, { 140,620 }, { 160,160 }, .8F);
	pad3 = new Object(this, wxT("..\\res\\pad.png"), wxBITMAP_TYPE_PNG, { 290,620 }, { 160,160 }, .8F);
	
	rock = new Object(this, wxT("..\\res\\rock.png"), wxBITMAP_TYPE_PNG, { -5,620 }, { 150,150 });
	paper = new Object(this, wxT("..\\res\\paper.png"), wxBITMAP_TYPE_PNG, { 145,620 }, { 150,150 });
	scissors = new Object(this, wxT("..\\res\\scissors.png"), wxBITMAP_TYPE_PNG, { 290,620 }, { 150,150 });
}

GamePlayActivity::GamePlayActivity(wxWindow* parent) :
	wxPanel(parent, wxID_ANY, { x_pos,0 }, { 450,800 })
{
	this->parent = parent;

	//add event listener for parent
	//this->Bind(wxEVT_CHAR_HOOK, &GamePlayActivity::OnKeyDown, this);
	this->Bind(wxEVT_KEY_DOWN, &GamePlayActivity::keydown_func, this);
	//this->Bind(wxEVT_KEY_UP, &GamePlayActivity::keyup_func, this);
	this->SetFocus();
	
	drawGameSet();

	slide_in_ani = new wxTimer(this, 31);
	gamestart = new wxTimer(this, 32);

	slide_in_ani->Start(2);
}

void GamePlayActivity::slide_in_func(wxTimerEvent & event)
{
	x_pos-=25;
	this->SetPosition({ x_pos,0 });
	if (x_pos <= 0) {
		slide_in_ani->Stop();
		gamestart->Start(bmgap);
	}
}

void GamePlayActivity::gamestart_func(wxTimerEvent & event)
{
	bg->paintNow();
	switch (gspap) {
	case 0:
		pad1->scale(1);
		pad2->scale(.8F);
		pad3->scale(.8F);
		break;
	case 1:
		pad1->scale(.8F);
		pad2->scale(1);
		pad3->scale(.8F);
		break;
	case 2:
		pad1->scale(.8F);
		pad2->scale(.8F);
		pad3->scale(1);
		bmgap-=bmgap/4;
		gamestart->Stop();
		if (bmgap > 50) {
			gamestart->Start(bmgap);
		}
		else {
			pad1->scale(1);
			pad2->scale(1);
			pad3->scale(1);
		}
		break;
	}
	rock->scale(1);
	paper->scale(1);
	scissors->scale(1);
	gspap += gspap >= 2 ? -2 : 1;
}

void GamePlayActivity::OnKeyDown(wxKeyEvent & event)
{
	int i = 1;
}

void GamePlayActivity::keydown_func(wxKeyEvent & event)
{
	switch (event.GetKeyCode()) {
	case WXK_LEFT:
		this->pad1->scale(1);
		break;
	case WXK_DOWN:
		this->pad2->scale(1);
		break;
	case WXK_RIGHT:
		this->pad3->scale(1);
		break;
	default:
		break;
	}
}

void GamePlayActivity::keyup_func(wxKeyEvent & event)
{
	switch (event.GetKeyCode()) {
	case WXK_LEFT:
		this->pad1->scale(.8F);
		break;
	case WXK_DOWN:
		this->pad2->scale(.8F);
		break;
	case WXK_RIGHT:
		this->pad3->scale(.8F);
		break;
	default:
		break;
	}
}
