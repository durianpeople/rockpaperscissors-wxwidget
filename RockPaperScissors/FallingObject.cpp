#include "FallingObject.h"
#include <cstdlib>

FallingObject::FallingObject(wxPanel * parent, wxString file, wxBitmapType format, int lane) :
	Object(parent, file, format, wxPoint(lane*150, -30), wxSize(150, 150), 1)
{	
	this->lane = lane;
}

void FallingObject::move()
{
	Object::move(wxPoint(0,moveDist));
}

void FallingObject::setMoveDist(int moveDist)
{
	this->moveDist = moveDist;
}
