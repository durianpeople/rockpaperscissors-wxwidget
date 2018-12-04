#include "DrawablePanel.h"
#include "template_wxbody.h"

BEGIN_EVENT_TABLE(DrawablePanel, wxPanel)
EVT_PAINT(DrawablePanel::paintEvent)
END_EVENT_TABLE()

DrawablePanel::DrawablePanel(wxWindow* parent, wxWindowID winid, const wxPoint &pos, const wxSize &size) :
	wxPanel(parent, winid, pos, size)
{
	
}

DrawablePanel::~DrawablePanel()
{
}

void DrawablePanel::render(wxDC & dc)
{
	//gambar disini pake variabel dc
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
