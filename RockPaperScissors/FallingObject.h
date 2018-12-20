#pragma once
#include "Object.h"
class FallingObject :
	public Object
{
	int lane;
	int moveDist = 10;
protected:
public:
	FallingObject(wxPanel* parent, wxString file, wxBitmapType format, int lane);
	int getLane() { return lane; }
	void move();
	virtual bool compete() = 0;
	void setMoveDist(int moveDist);
};

