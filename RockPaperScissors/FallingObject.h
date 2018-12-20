#pragma once
#include "Object.h"
class FallingObject :
	public Object
{
	int lane;
	int moveDist = 1;
public:
	FallingObject(wxPanel* parent, wxString file, wxBitmapType format, int lane);
	virtual void move();
	void setMoveDist(int moveDist);
};

