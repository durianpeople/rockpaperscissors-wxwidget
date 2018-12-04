#include "GamePanel.h"
#include "DrawablePanel.h"
#ifdef _DEBUG
#pragma comment(lib, "wxbase31ud.lib")
#else
#pragma comment(lib, "wxbase31u.lib")
#endif


GamePanel::GamePanel(wxWindow * parentFrame, wxWindowID windowID, wxPoint & pos, wxSize & size) :
	DrawablePanel(parentFrame, windowID, pos, size)
{

}


GamePanel::~GamePanel()
{
}

void GamePanel::render(wxDC & dc)
{
	dc.DrawText(wxT("Hello"), wxDefaultPosition);
}
