#pragma once
#include "Actions/Action.h"
class Paste: public Action
{
private:
	Point pClicked;
public:
	Paste(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

