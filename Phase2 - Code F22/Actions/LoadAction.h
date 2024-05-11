#pragma once
#ifndef LOAD_ACTION_H
#define LOAD_ACTION_H
#include "Action.h"
#include <fstream>
#include <string>
#include "colors.h"

class LoadAction :public Action
{
private:
	fstream InFile;
	string FileName;
	color GetColorObj(string)const;
public:
	LoadAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();


};
#endif
