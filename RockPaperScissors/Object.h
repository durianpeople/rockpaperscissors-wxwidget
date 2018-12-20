#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <wx/wx.h>
#include <wx/sizer.h>

class Object : public wxPanel
{
	wxImage image;
	wxBitmap resized, bmpImage;
	int w, h, bmpSet = 0;
	float scalenum = 1;
	bool scalef = false;

public:
	Object(wxPanel* parent, wxString file, wxBitmapType format, const wxPoint& position, const wxSize &size, float scale = 1);
	Object(wxPanel* parent, wxBitmap bmpImage, const wxPoint& position, const wxSize &size, float scale = 1);

	void paintEvent(wxPaintEvent & evt);
	void paintNow();
	void OnSize(wxSizeEvent& event);
	void render(wxDC& dc);
	virtual void scale(float scale, bool drawnow = true);
	virtual void move(wxPoint pt);
	bool collideWith(Object* obj);

	// some useful events
	/*
	 void mouseMoved(wxMouseEvent& event);
	 void mouseDown(wxMouseEvent& event);
	 void mouseWheelMoved(wxMouseEvent& event);
	 void mouseReleased(wxMouseEvent& event);
	 void rightClick(wxMouseEvent& event);
	 void mouseLeftWindow(wxMouseEvent& event);
	 void keyPressed(wxKeyEvent& event);
	 void keyReleased(wxKeyEvent& event);
	 */

	DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(Object, wxPanel)
// some useful events
/*
 EVT_MOTION(Object::mouseMoved)
 EVT_LEFT_DOWN(Object::mouseDown)
 EVT_LEFT_UP(Object::mouseReleased)
 EVT_RIGHT_DOWN(Object::rightClick)
 EVT_LEAVE_WINDOW(Object::mouseLeftWindow)
 EVT_KEY_DOWN(Object::keyPressed)
 EVT_KEY_UP(Object::keyReleased)
 EVT_MOUSEWHEEL(Object::mouseWheelMoved)
 */

 // catch paint events
	EVT_PAINT(Object::paintEvent)
	//Size event
	EVT_SIZE(Object::OnSize)
	END_EVENT_TABLE()

#endif
