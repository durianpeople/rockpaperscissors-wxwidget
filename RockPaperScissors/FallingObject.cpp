#include "FallingObject.h"

FallingObject::FallingObject(wxPanel * parent, wxString file, wxBitmapType format, const wxPoint & position, const wxSize & size, float scale) :
	Object(parent, file, format, position, size, scale)
{

}

void FallingObject::move()
{
	Object::move(wxPoint(0,1));
}
