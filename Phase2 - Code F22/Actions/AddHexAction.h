#ifndef ADD_HEX_ACTION_H
#define ADD_HEX_ACTION_H
#include "Action.h"

//Add hexagon action claxs
class AddHexAction : public Action
{
private:
	Point P1;
	GfxInfo HexGfxInfo; ///points & gfxinfo
public:
	AddHexAction(ApplicationManager * pApp);

	///read hexagon parameters
	virtual void ReadActionParameters(); 

	///Add Hexagon to the ApplicationManager
	virtual void Execute();
};
#endif