#pragma once
#include "template_wxheader.h"
class MainFrame : public wxFrame
{
public:
	MainFrame(wxApp* parent);
	wxApp* parent;
};

