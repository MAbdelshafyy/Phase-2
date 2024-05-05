#include "Delete.h"
#include"Figures/CFigure.h"


Delete::Delete(ApplicationManager* pApp) :Action(pApp) {}

void Delete::ReadActionParameters() {}

void Delete::Execute()
{
	Output* pOut = pManager->GetOutput();
	CFigure* selectedFig = pManager->getSelectedFig(selectedFig);//bye2ra el ragel medakhal eh

	if(selectedFig == NULL)
	{
		pOut->PrintMessage("No figs selected, please select a fig");

	}

	else 
	{
		pManager->dltfig(selectedFig);//bey delete el fig 
		pManager->setSelectedFig(NULL);//bey unselect
		pOut->PrintMessage("figure is deleted");

		selectedFig->SetSelected(false); //bey unselect 
		delete selectedFig;
	}
	
}

