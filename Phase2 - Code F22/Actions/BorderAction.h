#ifndef BORDER_ACTION_H
#define BORDER_ACTION_H

#include "Action.h"

class BorderAction : public Action
{
private:
	color c;

public:
	BorderAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif