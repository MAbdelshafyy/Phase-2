#pragma once
#include "Actions/Action.h"
#include"ApplicationManager.h"

class Delete :public Action
{
public:
	Delete(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
