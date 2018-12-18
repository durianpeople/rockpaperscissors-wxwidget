#pragma once
#include "template_wxheader.h"

class MainApp : public wxApp
{
	wxFrame* mainFrame;
public:
	virtual bool OnInit() override;
};
