#pragma once
#include"Actions/Action.h"

class ClearAll : public Action
{
public:
	ClearAll(ApplicationManager* pApp);
	virtual void ReadActionParameters(); //virtual 3ashan ne implement berahetna fel classes el tanya
	virtual void Execute();
};
