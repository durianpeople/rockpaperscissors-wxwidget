#include "PaperObject.h"

PaperObject::PaperObject(wxPanel * parent, int lane) :
	FallingObject(parent, wxT("..\\res\\paper.png"), wxBITMAP_TYPE_PNG, lane)
{
}

bool PaperObject::compete()
{
	int i = this->getLane();
	switch (i) {
	case 0:
		return true;
	case 1:
		return false;
	case 2:
		return false;
	}
}
