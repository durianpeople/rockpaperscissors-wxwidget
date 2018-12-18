#include "FallingMovable.h"

FallingMovable::FallingMovable(wxPoint position, wxSize size) :
	MovableObject(position, size)
{
}

void FallingMovable::move()
{
	this->setPosition(wxPoint(this->getPosition().x, this->getPosition().y + 2 ));
}

void FallingMovable::draw(wxBufferedPaintDC &pdc)
{
	pdc.SetBrush(wxBrush(wxColor("green")));
	pdc.SetPen(wxPen(wxColor("green")));
	pdc.DrawRectangle(this->position, this->size);
}
