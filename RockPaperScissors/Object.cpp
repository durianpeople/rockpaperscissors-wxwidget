#include "Object.h"
#include <cmath>

// some useful events
/*
 void Object::mouseMoved(wxMouseEvent& event) {}
 void Object::mouseDown(wxMouseEvent& event) {}
 void Object::mouseWheelMoved(wxMouseEvent& event) {}
 void Object::mouseReleased(wxMouseEvent& event) {}
 void Object::rightClick(wxMouseEvent& event) {}
 void Object::mouseLeftWindow(wxMouseEvent& event) {}
 void Object::keyPressed(wxKeyEvent& event) {}
 void Object::keyReleased(wxKeyEvent& event) {}
 */

Object::Object(wxPanel* parent, wxString file, wxBitmapType format, const wxPoint& position, const wxSize &size, float s) :
	wxPanel(parent, wxID_ANY, position, size)
{
	// load the file... ideally add a check to see if loading was successful
	image.LoadFile(file, format);
	w = -1;
	h = -1;
	if (s != 1) {
		this->scalenum = s;
		scalef = true;
	}
}

Object::Object(wxPanel * parent, wxBitmap bmpImage, const wxPoint & position, const wxSize & size, float s) :
	wxPanel(parent, wxID_ANY, position, size)
{
	this->bmpImage = bmpImage;
	bmpSet = 1;
	w = -1;
	h = -1;
	if (s != 1) {
		this->scalenum = s;
		scalef = true;
	}
}

/*
 * Called by the system of by wxWidgets when the panel needs
 * to be redrawn. You can also trigger this call by
 * calling Refresh()/Update().
 */

void Object::paintEvent(wxPaintEvent & evt)
{
	// depending on your system you may need to look at double-buffered dcs
	wxPaintDC dc(this);
	render(dc);
}

/*
 * Alternatively, you can use a clientDC to paint on the panel
 * at any time. Using this generally does not free you from
 * catching paint events, since it is possible that e.g. the window
 * manager throws away your drawing when the window comes to the
 * background, and expects you will redraw it when the window comes
 * back (by sending a paint event).
 */
void Object::paintNow()
{
	// depending on your system you may need to look at double-buffered dcs
	wxClientDC dc(this);
	render(dc);
}



/*
 * Here we do the actual rendering. I put it in a separate
 * method so that it can work no matter what type of DC
 * (e.g. wxPaintDC or wxClientDC) is used.
 */
void Object::render(wxDC&  dc)
{
	int neww, newh;
	dc.GetSize(&neww, &newh);

	if (neww != w || newh != h || scalef)
	{
		if (!bmpSet) resized = wxBitmap(image.Scale(neww * scalenum, newh * scalenum /*, wxIMAGE_QUALITY_HIGH*/));
		else resized = this->bmpImage;
		w = neww;
		h = newh;
		if (scalef) {
			dc.DrawBitmap(resized, neww / 2 - (neww * scalenum / 2), newh / 2 - (newh * scalenum / 2), false);
		}
		else {
			dc.DrawBitmap(resized, 0, 0, false);
		}
	}
	else {
		dc.DrawBitmap(resized, 0, 0, false);
	}
}

void Object::scale(float s, bool drawNow)
{
	this->scalenum = s;
	scalef = true;
	if (drawNow) paintNow();
}

void Object::move(wxPoint pt)
{
	this->SetPosition({ pt.x + this->GetPosition().x, pt.y + this->GetPosition().y });
}

bool Object::collideWith(Object * obj)
{
	auto thisp = this->GetPosition();
	auto objp = obj->GetPosition();
	auto thiss = this->GetSize();
	auto objs = obj->GetPosition();

	return (abs(thisp.x - objp.x) * 2 < (thiss.x + objs.x)) &&
		(abs(thisp.y - objp.y) * 2 < (thiss.y + objs.y));
}

/*
 * Here we call refresh to tell the panel to draw itself again.
 * So when the user resizes the image panel the image should be resized too.
 */
void Object::OnSize(wxSizeEvent& event) {
	Refresh();
	//skip the event.
	event.Skip();
}