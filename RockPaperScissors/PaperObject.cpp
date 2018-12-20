#include "PaperObject.h"

PaperObject::PaperObject(wxPanel * parent, int lane) :
	FallingObject(parent, wxT("..\\res\\paper.png"), wxBITMAP_TYPE_PNG, lane)
{
}
