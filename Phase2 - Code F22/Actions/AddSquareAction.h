#ifndef ADD_SQUARE_ACTION_H
#define ADD_SQUARE_ACTION_H
#include "Action.h"

//Add Square Action class
class AddSquareAction : public Action
{
private:
	Point Center1; //Square Center
	GfxInfo SquareGfxInfo;
public:
	AddSquareAction(ApplicationManager* pApp);

	//Reads square parameters
	virtual void ReadActionParameters();

	//Add Square to the ApplicationManager
	virtual void Execute();

};

#endif