#include "WelcomeActivity.h"
#include "GamePlayActivity.h"
#include "HighScoreActivity.h"
#include "Object.h"

#include "template_wxbody.h"

WelcomeActivity::WelcomeActivity(wxWindow * parent) :
	wxPanel(parent, wxID_ANY, { 0,0 }, { 450,800 })
{
	this->parent = parent;

	new wxBitmapButton(this, 21, wxBitmap(wxT("..\\res\\startbtn.png"), wxBITMAP_TYPE_PNG), { 109,558 }, { 230,70 });
	new wxBitmapButton(this, 22, wxBitmap(wxT("..\\res\\highscbtn.png"), wxBITMAP_TYPE_PNG), { 107,659 }, { 230,70 });

	new Object(this, wxT("..\\res\\welcome.png"), wxBITMAP_TYPE_PNG, { 0,0 }, { 450,800 });
}

void WelcomeActivity::playnow(wxCommandEvent& event)
{
	new GamePlayActivity(parent);
	this->Destroy();
}

void WelcomeActivity::highscore(wxCommandEvent & event)
{
	new HighScoreActivity(parent);
	this->Destroy();
}
