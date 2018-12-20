#include "RockObject.h"

RockObject::RockObject(wxPanel * parent, int lane) :
	FallingObject(parent, wxT("..\\res\\rock.png"), wxBITMAP_TYPE_PNG, lane)
{
}
