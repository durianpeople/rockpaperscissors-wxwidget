#pragma once
#include "MainApp.h"

class ScreenSplash
{
private:
	MainApp* mainapp;
	wxPanel* panel;
	wxTimer* timer;
public:
	const int TIMERID = 1;
	ScreenSplash(MainApp* main);
	void Notify();
};

