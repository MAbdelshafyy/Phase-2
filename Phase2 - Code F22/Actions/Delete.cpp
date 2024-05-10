#include "Delete.h"
#include "SelectAction.h"
#include "ApplicationManager.h"



Delete::Delete(ApplicationManager* pApp) :Action(pApp) {}

void Delete::ReadActionParameters() {}

void Delete::Execute()
{
	Output* pOut = pManager->GetOutput();
	for (int i = 0; i < pManager->GetFigCount(); i++)
	{
		CFigure* SelectFig = pManager->GetSelectedFigList(i);//bye2ra el ragel medakhal eh

		if (SelectFig == NULL) //beyshof hwa fe selected figure wala la
		{
			pOut->PrintMessage("No figs selected, please select a fig");

		}

		else
		{
			pManager->dltfig(SelectFig);//bey delete el fig 
			pManager->SelectFig(NULL);//bey unselect
			pOut->PrintMessage("figure is deleted");

			SelectFig->SetSelected(false); //bey unselect 
			delete SelectFig;
		}

	}
}
