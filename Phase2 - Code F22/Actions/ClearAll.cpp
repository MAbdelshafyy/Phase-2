#include"ClearAll.h"
#include"ApplicationManager.h"
#include"SelectAction.h"

ClearAll::ClearAll(ApplicationManager* pApp) :Action(pApp) {}

void ClearAll::ReadActionParameters() {}

void ClearAll::Execute()
{
	for (int i = 0; i < pManager->GetFigCount();i++)
	{
		delete pManager->GetFigList(i);
		CFigure* FigList = NULL;
		CFigure* FigCount = 0;
		CFigure* Clipboard = NULL;
	}
}
	
	
