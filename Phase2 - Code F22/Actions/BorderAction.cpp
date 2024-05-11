#include "BorderAction.h"
#include "..\Figures\CRectangle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "CFigure.h"

BorderAction::BorderAction(ApplicationManager* pApp) :Action(pApp) , c(BLACK)
{
}

void BorderAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ActionType Act;

	CFigure* fig = pManager->GetSelectedFigs(0);
	c = fig->GetDrawClr();
	
	pOut->PrintMessage("Ready to change border, Select a color");
	Act = pIn->GetUserAction();
	switch (Act) {
	case CLR_BLCK:
		c = BLACK;
		break;
	case CLR_YLLW:
		c = YELLOW;
		break;
	case CLR_ORNG:
		c = ORANGE;
		break;
	case CLR_RED:
		c = RED;
		break;
	case CLR_GRN:
		c = DARKGREEN;
		break;
	case CLR_BLUE:
		c = BLUE;
		break;
		
	default: 
		pOut->PrintMessage("Default color is automatically selected (black)");
		break;
	}

	pOut->ClearStatusBar();
}

void BorderAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();
	CFigure* fig = pManager->GetSelectedFigs(0);

	if (pManager->GetSelectedFigCount() == 0)
		pOut->PrintMessage("Select a figure first");
	else if (pManager->GetSelectedFigCount() > 1)
		pOut->PrintMessage("Select one figure only");
	else {
		pManager->UnselectFig(fig);
		fig->SetSelected(false);
		fig->ChngDrawClr(c);
		UI.DrawColor = c;
		pOut->PrintMessage("Border color updated");
	}

}
