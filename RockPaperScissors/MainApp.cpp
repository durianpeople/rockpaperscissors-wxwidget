#include "MainApp.h"
#include "SplashActivity.h"
#include "MainFrame.h"
#include <iostream>
#include <fstream>

#ifdef _DEBUG
#pragma comment(lib, "wxbase31ud.lib")
#else
#pragma comment(lib, "wxbase31u.lib")
#endif

bool MainApp::OnInit() {
	wxDisableAsserts();
	wxInitAllImageHandlers();
	mainFrame = new MainFrame(this);
	mainFrame->Center();
	mainFrame->SetBackgroundColour(wxColor("black"));
	mainFrame->Show();

	(new SplashActivity(mainFrame))->Show();
	mainFrame->Refresh();

	//Load highscore
	std::ifstream file ("..\res\file.txt");
	if (file && file.peek() != std::ifstream::traits_type::eof()) {
		file >> this->highscore;
	}
	else {
		this->highscore = 0;
	}

	return true;
}

void MainApp::setHighScore(int score)
{
	this->highscore = score;
	std::ofstream file;
	file.open("..\res\file.txt");
	file << this->highscore;
	file.close();
}

int MainApp::getHighScore()
{
	return this->highscore;
}

wxIMPLEMENT_APP(MainApp);
