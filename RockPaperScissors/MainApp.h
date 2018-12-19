#pragma once
#include "template_wxheader.h"

class MainApp : public wxApp
{
	wxFrame* mainFrame;
	int highscore;
public:
	virtual bool OnInit() override;
	void setHighScore(int score);
	int getHighScore();
};