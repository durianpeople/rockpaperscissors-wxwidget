#pragma once
#include "FallingObject.h"
class RockObject :
	public FallingObject
{
public:
	RockObject(wxPanel* parent, int lane);
	bool compete();
};

