#include "HighScoreActivity.h"
#include "WelcomeActivity.h"
#include "template_wxbody.h"
#include "Object.h"
#include <iostream>
#include <fstream>

HighScoreActivity::HighScoreActivity(wxWindow * parent) :
	wxPanel(parent, wxID_ANY, { 0,0 }, { 450,800 })
{
	this->parent = parent;
	this->SetBackgroundColour(wxColor("green"));

	//buttons
	new wxButton(this, 31, wxString(wxString::Format("%d",this->getHighScore())), wxDefaultPosition, wxDefaultSize);
	this->SetFocus();
	this->highscore = 0;

	wxMemoryDC dc;
	dc.SetBackgroundMode(wxSOLID);
	dc.SetPen(wxPen(wxColor("black")));
	dc.DrawText("Test",wxPoint(0,0));
	wxBitmap text = dc.GetAsBitmap();
	new Object(this, text, wxPoint(50, 50), wxSize(100,100));

	//wxMemoryDC dc;
	//wxString score = wxString::Format("%d", parent->parent->highscore);
}

void HighScoreActivity::back(wxCommandEvent & event)
{
	this->setHighScore(this->getHighScore()+1);
	new WelcomeActivity(parent);
	this->Destroy();
}

void HighScoreActivity::setHighScore(int score)
{
	this->highscore = score;
	std::ofstream file;
	file.open("..\\res\\file.txt");
	file << this->highscore;
	file.close();
}

int HighScoreActivity::getHighScore()
{
	std::ifstream file("..\\res\\file.txt");
	if (file && file.peek() != std::ifstream::traits_type::eof()) {
		file >> this->highscore;
	}
	else {
		this->highscore = 0;
	}
	return this->highscore;
}