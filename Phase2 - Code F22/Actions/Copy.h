#pragma once
#include"Actions/Action.h"

class Copy : public Action
{
public:
	Copy(ApplicationManager* pApp);
	virtual void ReadActionParameters(); //virtual 3ashan ne implement berahetna fel classes el tanya
	virtual void Execute();
};
