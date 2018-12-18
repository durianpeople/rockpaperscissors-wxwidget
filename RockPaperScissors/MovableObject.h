#pragma once
#include "wx\wx.h"
#include "wx\dcbuffer.h"
#include <vector>
#include <cstdlib>

class MovableObject
{
protected:
	wxPoint position;
	wxSize size;
public:
	MovableObject(wxPoint position, wxSize size);
	virtual void draw(wxBufferedPaintDC &pdc) = 0;
	virtual void move() = 0;
	void setPosition(wxPoint position);
	wxPoint getPosition();
	wxSize getSize();
	bool collideWith(MovableObject* object);
};

