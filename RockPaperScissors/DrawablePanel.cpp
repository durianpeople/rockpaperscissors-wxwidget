#include "DrawablePanel.h"
#ifdef _DEBUG
#pragma comment(lib, "wxbase31ud.lib")
#else
#pragma comment(lib, "wxbase31u.lib")
#endif

BEGIN_EVENT_TABLE(DrawablePanel, wxPanel)
EVT_PAINT(DrawablePanel::paintEvent)
END_EVENT_TABLE()

DrawablePanel::DrawablePanel(wxWindow* parentFrame, wxWindowID windowID, wxPoint &pos, wxSize &size) :
	wxPanel(parentFrame, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
	SetBackgroundColour(wxColour("green"));
}

void DrawablePanel::render(wxDC & dc)
{
	//gambar disini pake variabel dc
}

DrawablePanel::~DrawablePanel()
{
}

void DrawablePanel::paintEvent(wxPaintEvent & evt)
{
	wxPaintDC dc(this);
	render(dc);
}

void DrawablePanel::paintNow()
{
	wxClientDC dc(this);
	render(dc);
}
