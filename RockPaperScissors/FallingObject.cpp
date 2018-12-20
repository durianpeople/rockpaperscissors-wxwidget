#include "FallingObject.h"

FallingObject::FallingObject(wxPanel * parent, wxString file, wxBitmapType format, int lane) :
	Object(parent, file, format, wxPoint(lane*150, 0), wxSize(150, 150), 1)
{
}

void FallingObject::move()
{
	Object::move(wxPoint(0,30));
}

void FallingObject::setMoveDist(int moveDist)
{
	this->moveDist = moveDist;
}
