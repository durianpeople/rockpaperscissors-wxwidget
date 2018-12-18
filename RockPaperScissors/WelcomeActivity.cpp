#include "WelcomeActivity.h"
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
	this->SetBackgroundColour(wxColor("green"));
	new Object(this, wxT("..\\res\\welcome.png"), wxBITMAP_TYPE_PNG, { 0,0 }, { 450,800 });

}

void WelcomeActivity::close(wxTimerEvent & event)
{
	
}
