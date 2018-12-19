#include "HighScoreActivity.h"
#include "WelcomeActivity.h"
#include "MainFrame.h"
#include "template_wxbody.h"

HighScoreActivity::HighScoreActivity(wxWindow * parent) :
	wxPanel(parent, wxID_ANY, { 0,0 }, { 450,800 })
{
	this->parent = parent;
	this->SetBackgroundColour(wxColor("green"));

	//buttons
	new wxButton(this, 31, L"Back", wxDefaultPosition, wxDefaultSize);
	this->SetFocus();

	//wxMemoryDC dc;
	//wxString score = wxString::Format("%d", parent->parent->highscore);
}

void HighScoreActivity::back(wxCommandEvent & event)
{
	new WelcomeActivity(parent);
	this->Destroy();
}
