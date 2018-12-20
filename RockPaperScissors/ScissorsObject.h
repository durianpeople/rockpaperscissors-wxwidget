#pragma once
#include "FallingObject.h"
class ScissorsObject :
	public FallingObject
{
public:
	ScissorsObject(wxPanel* parent, int lane);
	bool compete();
};

