#include "MainFrame.h"

#ifdef _DEBUG
#pragma comment(lib, "wxbase31ud.lib")
#else
#pragma comment(lib, "wxbase31u.lib")
#endif

MainFrame::MainFrame() :
	wxFrame(nullptr, wxID_ANY, wxT("Awesome Rock Paper Scissors"), wxDefaultPosition, wxSize(450, 800))
{
	Center();
}


MainFrame::~MainFrame()
{
}
