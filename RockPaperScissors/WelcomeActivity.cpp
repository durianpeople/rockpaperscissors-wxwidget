#include "WelcomeActivity.h"
#include "GamePlayActivity.h"
#include "Object.h"

#ifdef _DEBUG
#pragma comment(lib, "wxbase31ud.lib")
#else
#pragma comment(lib, "wxbase31u.lib")
#endif

WelcomeActivity::WelcomeActivity(wxWindow * parent) :
	wxPanel(parent, wxID_ANY, { 0,0 }, { 450,800 })
{
	this->parent = parent;

	startbtn = new wxBitmapButton(this, 21, wxBitmap(wxT("..\\res\\startbtn.png"), wxBITMAP_TYPE_PNG), { 109,558 }, { 230,70 });
	highsbtn = new wxBitmapButton(this, 22, wxBitmap(wxT("..\\res\\highscbtn.png"), wxBITMAP_TYPE_PNG), { 107,659 }, { 230,70 });

	Object* bg = new Object(this, wxT("..\\res\\welcome.png"), wxBITMAP_TYPE_PNG, { 0,0 }, { 450,800 });
}

void WelcomeActivity::playnow(wxCommandEvent& event)
{
	new GamePlayActivity(parent);
	Destroy();
}