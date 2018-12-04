#pragma once
#include "template_wxheader.h"
class DrawablePanel : public wxPanel
{
public:
	DrawablePanel(wxWindow* parent, wxWindowID winid, const wxPoint &pos, const wxSize &size);
	~DrawablePanel();
	void paintEvent(wxPaintEvent & evt);
	void paintNow();
	virtual void render(wxDC& dc);

	DECLARE_EVENT_TABLE()
};

