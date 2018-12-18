#pragma once
#include "MovableObject.h"
class FallingMovable : public MovableObject
{
public:
	FallingMovable(wxPoint position, wxSize size);
	void move();
	void draw(wxBufferedPaintDC &pdc);
};

