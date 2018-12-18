#pragma once
#include "template_wxheader.h"

class MainApp : public wxApp
{
private:
	wxPanel* currentPanel;
	wxFrame* mainFrame;
public:
	MainApp();
	virtual bool OnInit() override;
	wxPanel* newPanel();
	void r();
};
