#pragma once
class MainApp : public wxApp
{
public:
	MainApp();
	virtual ~MainApp();
	virtual bool OnInit() override;
};
