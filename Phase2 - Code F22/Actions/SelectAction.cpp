#include "SelectAction.h"
#include "..\Figures\CRectangle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "CFigure.h"

SelectAction::SelectAction(ApplicationManager* pApp) :Action(pApp)
{
}


void SelectAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Select Figure: Click on shape");
	pIn->GetPointClicked(P.x, P.y);
	pOut->ClearStatusBar();
}

void SelectAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();

	CFigure* Fig = pManager->GetFigure(P);

	if (Fig != NULL) {
		if (Fig->IsSelected() == true) {
			pManager->UnselectFig(Fig);
			pOut->PrintMessage("Figure unselected");
		}
		else if (pManager->GetSelectedFigCount() >= 10)
			pOut->PrintMessage("Maximum figures selected (10)");
		else {
			pManager->SelectFig(Fig);
			string s = to_string(pManager->GetSelectedFigCount()) + " figures selected";
			pOut->PrintMessage(s);
		}
	}
	else if (pManager->GetSelectedFigCount() == 0)
		pOut->PrintMessage("No figure is selected");
	else {
		pManager->UnselectAll();
		pOut->PrintMessage("All figures unselected");
	}

	if (pManager->GetSelectedFigCount() == 1)
		pManager->GetSelectedFigs(0)->PrintInfo(pOut);
}