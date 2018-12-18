#include "DrawablePanel.h"

DrawablePanel::DrawablePanel(wxWindow * parent, wxWindowID id, const wxPoint & pos, const wxSize & size) :
	wxPanel(parent, id, pos, size)
{
	this->size = size;
	timer = new wxTimer(this, 1000);
	timer->Start(1000);
}

void DrawablePanel::onPaint(wxPaintEvent & event)
{
	wxBufferedPaintDC pdc(this);
	pdc.SetBackground(wxBrush(wxColour("black")));
	pdc.DrawRectangle(wxPoint(0, 0), this->size);
	for (auto it : objects) {
		it->draw(pdc);
	}
}

void DrawablePanel::onTimer(wxTimerEvent & event)
{
	for (auto it : objects) {
		it->move();
	}
	Refresh(0);
}

void DrawablePanel::registerObject(MovableObject * object)
{
	objects.push_back(object);
}


BEGIN_EVENT_TABLE(DrawablePanel, wxPanel)
EVT_TIMER(1000, DrawablePanel::onTimer)
EVT_PAINT(DrawablePanel::onPaint)
END_EVENT_TABLE()