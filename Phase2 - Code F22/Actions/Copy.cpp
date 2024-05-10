#include"Copy.h"
#include"ApplicationManager.h"
#include"SelectAction.h"

Copy::Copy(ApplicationManager* pApp) :Action(pApp) {}

void Copy::ReadActionParameters() {}

void Copy::Execute()
{
	Output* pOut = pManager->GetOutput();
	for (int i = 0; i < pManager->GetFigCount(); i++)
	{
		CFigure* SelectFig = pManager->GetSelectedFigList(i);//bye2ra el ragel medakhal eh

		if (SelectFig == NULL) //beyshof hwa fe selected figure wala la

			pOut->PrintMessage("No figure is selected to copy");

		else
		{
			for (int i = 0; i < pManager->GetFigCount(); i++)
			{
				CFigure* SelectFig = pManager->GetSelectedFigList(i);

				pManager->setClipboard(SelectFig);

				pOut->PrintMessage("SeleActed figure is copied");

				pManager->GetFigList(i)->SetSelected(false);

				SelectAction* SelectedFigCount = 0;
				pOut->PrintMessage("All figures unselected");
			}
		}

	}
}
