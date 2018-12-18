#pragma once
#include "MainApp.h"

class ScreenSplash : public wxTimer
{
private:
	MainApp* mainapp;
	wxPanel* panel;
public:
	const int TIMERID = 1;
	ScreenSplash(MainApp* main);
	void Notify();
};

