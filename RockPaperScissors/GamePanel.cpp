#include "GamePanel.h"
#include "DrawablePanel.h"
#include "template_wxbody.h"


GamePanel::GamePanel(wxWindow * parent, wxWindowID winid, const wxPoint & pos, const wxSize & size) :
	DrawablePanel(parent, winid, pos, size)
{
}

GamePanel::~GamePanel()
{
}

void GamePanel::render(wxDC & dc)
{
	
}
