#pragma once
#include "template_wxheader.h"
#include "DrawablePanel.h"

class GamePanel : public DrawablePanel
{
public:
	GamePanel(wxWindow* parent, wxWindowID winid, const wxPoint &pos, const wxSize &size);
	~GamePanel();
	void render(wxDC& dc);
};