#pragma once
#include "Object.h"
class FallingObject : public Object
{
public:
	FallingObject(wxPanel* parent, wxString file, wxBitmapType format, const wxPoint& position, const wxSize &size, float scale = 1);
	void move();
};

