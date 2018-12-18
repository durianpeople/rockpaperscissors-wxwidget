#pragma once
#include "MainApp.h"

class ScreenSplash : public wxTimer
{
private:
	MainApp* mainapp;
	wxPanel* panel;
public:
	ScreenSplash(MainApp* main);
	void Notify();
};

