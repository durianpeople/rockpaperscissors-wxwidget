#pragma once
#include <wx\wxprec.h>
#include "DrawablePanel.h"

class GamePanel : public DrawablePanel
{
public:
	GamePanel(wxWindow * parentFrame, wxWindowID windowID, wxPoint & pos, wxSize & size);
	~GamePanel();
	void render(wxDC& dc);
};

