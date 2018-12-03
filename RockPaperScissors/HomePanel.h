#pragma once
#include <wx\wxprec.h>
class HomePanel : public wxPanel
{
public:
	HomePanel(wxWindow* parentFrame);
	~HomePanel();
	void paintEvent(wxPaintEvent & evt);
	void paintNow();
	void render(wxDC& dc);

private:
	DECLARE_EVENT_TABLE()
};

