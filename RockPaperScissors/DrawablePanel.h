#pragma once
#include <wx\wxprec.h>
class DrawablePanel : public wxPanel
{
public:
	DrawablePanel(wxWindow* parentFrame, wxWindowID windowID, wxPoint &pos, wxSize &size);
	~DrawablePanel();
	void paintEvent(wxPaintEvent & evt);
	void paintNow();
	virtual void render(wxDC& dc);
	DECLARE_EVENT_TABLE()
};

