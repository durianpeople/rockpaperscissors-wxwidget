#include "RockObject.h"

RockObject::RockObject(wxPanel * parent, int lane) :
	FallingObject(parent, wxT("..\\res\\rock.png"), wxBITMAP_TYPE_PNG, lane)
{
}

bool RockObject::compete()
{
	int i = this->getLane();
	switch (i) {
	case 0:
		return false;
	case 1:
		return false;
	case 2:
		return true;
	}
}
