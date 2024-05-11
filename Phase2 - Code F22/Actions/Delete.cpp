#include "Delete.h"
#include "SelectAction.h"
#include "ApplicationManager.h"



Delete::Delete(ApplicationManager* pApp) :Action(pApp) {}

void Delete::ReadActionParameters() {}

void Delete::Execute()
{
	Output* pOut = pManager->GetOutput();
	int c = 0;
	if (pManager->GetSelectedFigCount() == 0)
		pOut->PrintMessage("No figure is selected to delete");
	else {
		for (int i = 0; i < pManager->GetSelectedFigCount(); i++)
		{
			CFigure* SelectFig = pManager->GetSelectedFigs(i);//bye2ra el ragel medakhal eh


			pManager->dltfig(SelectFig);//bey delete el fig
			pManager->UnselectFig(SelectFig);
			delete SelectFig;
			c++;
		}
		string s = to_string(c) + "Figure(s) deleted";
		pOut->PrintMessage(s);
	}
}
