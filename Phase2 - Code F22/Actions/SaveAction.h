#ifndef SAVE_ACTION_H
#define SAVE_ACTION_H
#include "Action.h"
#include "Figures\CFigure.h"
#include <fstream>

class SaveAction : public Action
{
private:
	ofstream OutFile;
	string FileName;
	string GetColorType(color type) const;
public:
	SaveAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif