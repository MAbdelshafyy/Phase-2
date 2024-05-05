#include "Copy.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"

Copy::Copy(ApplicationManager* pApp):Action(pApp) {}

void Copy::ReadActionParameters() {}

void Copy::Execute() {
	Output* pOut = pManager->GetOutput();
	CFigure* selectedFig = pManager->getSelectedFig(selectedFig);


	if(selectedFig == NULL) //beyshof hwa fe selected figure wala la
	{
			pOut->PrintMessage("No figure is selected to copy");
	}
	else
	{
		pManager->setClipboard(selectedFig);
		pOut->PrintMessage("Selected figure is copied");

		pManager->setSelectedFig(NULL);
		selectedFig->SetSelected(false); //bey unselect el fig 	
	}
	
}
