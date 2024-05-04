#ifndef ADD_TRI_ACTION_H
#define ADD_TRI_ACTION_H
#include "Action.h"


///  Add Triangle Action Class
class AddTriAction :public Action
{

private:
	Point P1, P2, P3;
	GfxInfo TriGfxInfo; ////Declare points & Gfx Info
public:
	AddTriAction(ApplicationManager* pApp);

	// Read Triangle Parameters
	virtual void ReadActionParameters();    

	///Add Triangle to the ApplicationManager
	virtual void Execute(); ///Execute

};
#endif