#include "ScissorsObject.h"

ScissorsObject::ScissorsObject(wxPanel * parent, int lane) :
	FallingObject(parent, wxT("..\\res\\scissors.png"), wxBITMAP_TYPE_PNG, lane)
{
}

bool ScissorsObject::compete()
{
	int i = this->getLane();
	switch (i) {
	case 0:
		return false;
	case 1:
		return true;
	case 2:
		return false;
	}
}
