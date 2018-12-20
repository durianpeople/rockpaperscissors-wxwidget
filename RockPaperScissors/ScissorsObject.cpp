#include "ScissorsObject.h"

ScissorsObject::ScissorsObject(wxPanel * parent, int lane) :
	FallingObject(parent, wxT("..\\res\\paper.png"), wxBITMAP_TYPE_PNG, lane)
{
}
