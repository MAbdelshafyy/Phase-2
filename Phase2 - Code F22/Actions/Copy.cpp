#include"Copy.h"
#include"ApplicationManager.h"
#include"SelectAction.h"

Copy::Copy(ApplicationManager* pApp) :Action(pApp) {}

void Copy::ReadActionParameters() {}

void Copy::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();

	for (int i = 0; i < pManager->GetSelectedFigCount(); i++)
	{
		CFigure* SelectFig = pManager->GetSelectedFigList(0);//bye2ra el ragel medakhal eh

		if (pManager->GetSelectedFigCount() == 0) { //beyshof hwa fe selected figure wala la

			pOut->PrintMessage("No figure is selected to copy");
		}

		else if (pManager->GetSelectedFigCount() > 1) {
			pOut->PrintMessage("Select one figure only");
		}

		else
		{
			pManager->UnselectFig(SelectFig);
			SelectFig->SetSelected(false);


			for (int i = 0; i < pManager->GetSelectedFigCount(); i++)
			{
				CFigure* SelectFig = pManager->GetSelectedFigList(i);

				pManager->setClipboard(SelectFig);

				pOut->PrintMessage("SeleActed figure is copied");

				pManager->GetFigList(i)->SetSelected(false);
				SelectFig->SetSelected(false);
				pManager->UnselectFig(SelectFig);

				SelectAction* SelectedFigCount = 0;
				pOut->PrintMessage("All figures unselected");
			}
		}

	}
}
