#pragma once
#include "FallingObject.h"
class PaperObject :
	public FallingObject
{
public:
	PaperObject(wxPanel* parent, int lane);
	bool compete();
};

