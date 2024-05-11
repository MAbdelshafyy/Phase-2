#ifndef FILLING_ACTION_H
#define FILLING_ACTION_H

#include "Action.h"

class FillingAction : public Action
{
private:
	color c;

public:
	FillingAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif