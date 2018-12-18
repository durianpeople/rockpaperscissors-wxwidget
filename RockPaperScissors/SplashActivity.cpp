#include "SplashActivity.h"
#include "WelcomeActivity.h"

#ifdef _DEBUG
#pragma comment(lib, "wxbase31ud.lib")
#else
#pragma comment(lib, "wxbase31u.lib")
#endif

SplashActivity::SplashActivity(wxWindow * parent) : 
	wxPanel(parent, wxID_ANY, { 0,0 }, { 450,800 })
{
	this->parent = parent;
	this->SetBackgroundColour(wxColor("black"));
	bg = new Object(this, wxT("..\\res\\splash.png"), wxBITMAP_TYPE_PNG, { 0,0 }, { 450,800 }, 0);

	animation = new wxTimer(this, 11);
	animation->Start(5);

	timer1 = new wxTimer(this,12);
	timer1->StartOnce(2000);
}

void SplashActivity::nextActivity(wxTimerEvent& event)
{
	(new WelcomeActivity(parent))->Show();
	parent->Refresh();
	this->Destroy();
}

void SplashActivity::anicall(wxTimerEvent & event)
{
	if (scale < 1) {
		scale += 0.04F;
		bg->scale(scale);
	}
	else {
		animation->Stop();
	}
}
