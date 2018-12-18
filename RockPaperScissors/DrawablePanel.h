#pragma once
#include "template_wxheader.h"
#include "MovableObject.h"
#include "wx\dcbuffer.h"
#include <vector>
class DrawablePanel : public wxPanel
{
public:
	DrawablePanel(wxWindow *parent, wxWindowID id = wxID_ANY, const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize);
	void onPaint(wxPaintEvent &event);
	void onTimer(wxTimerEvent &event);
	void registerObject(MovableObject* object);
private:
	wxSize size;
	wxTimer* timer;
	std::vector<MovableObject*> objects;
	DECLARE_EVENT_TABLE()
};

