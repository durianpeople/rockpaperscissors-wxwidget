#include "HomePanel.h"
#ifdef _DEBUG
#pragma comment(lib, "wxbase31ud.lib")
#else
#pragma comment(lib, "wxbase31u.lib")
#endif

BEGIN_EVENT_TABLE(HomePanel, wxPanel)
EVT_PAINT(HomePanel::paintEvent)
END_EVENT_TABLE()

HomePanel::HomePanel(wxWindow* parentFrame) :
	wxPanel(parentFrame, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
	SetBackgroundColour(wxColour("green"));
}


HomePanel::~HomePanel()
{
}

void HomePanel::paintEvent(wxPaintEvent & evt)
{
	wxPaintDC dc(this);
	render(dc);
}

void HomePanel::paintNow()
{
	wxClientDC dc(this);
	render(dc);
}

void HomePanel::render(wxDC & dc)
{
	dc.DrawText(wxT("Amazing Rock Paper Scissors"), wxDefaultPosition);
}