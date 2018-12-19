#include "MainFrame.h"
#include "template_wxbody.h"

MainFrame::MainFrame(wxApp * parent) :
	wxFrame(NULL, wxID_ANY, L"Rock Paper Scissors", wxDefaultPosition, { 450,800 }, wxCLOSE_BOX | wxCAPTION | wxCLIP_CHILDREN)
{
	this->parent = parent;
}

