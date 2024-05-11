#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "SelectAction.h"
#include "AddCircAction.h"
#include "AddHexAction.h"
#include "AddSquareAction.h"
#include "AddTriAction.h"
#include "BorderAction.h"
#include "FillingAction.h"
#include "SaveAction.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	IDCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++) {
		FigList[i] = NULL;
	}
}



//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_HEX:
			pAct = new AddHexAction(this);
			break;

		case DRAW_CIRC:
			pAct = new AddCircAction(this);
			break;

		case DRAW_SQR:
			pAct = new AddSquareAction(this);
			break;

		case DRAW_TRI:
			pAct = new AddTriAction(this);
			break;

		case DO_SLCT:
			pAct = new SelectAction(this);
			break;

		case DO_BRDR:
			pAct = new BorderAction(this);
			break;

		case DO_FILL:
			pAct = new FillingAction(this);
			break;

		case CLR_BLCK:
			pOut->PrintMessage("Select change border or change filling first");
			break;

		case CLR_YLLW:
			pOut->PrintMessage("Select change border or change filling first");
			break;

		case CLR_ORNG:
			pOut->PrintMessage("Select change border or change filling first");
			break;

		case CLR_RED:
			pOut->PrintMessage("Select change border or change filling first");
			break;

		case CLR_GRN:
			pOut->PrintMessage("Select change border or change filling first");
			break;

		case CLR_BLUE:
			pOut->PrintMessage("Select change border or change filling first");
			break;

		case DO_SAVE:
			pAct = new SaveAction(this);
			break;

		case TO_PLAY:
			pOut->CreatePlayToolBar();
			break;

		case EXIT:
			///create ExitAction here
			pOut->PrintMessage("Exiting..");
			UnselectAll();
			for (int i = 0; i < FigCount; i++) {
				delete FigList[i];
			}
			break;

		case TO_DRAW:
			pOut->CreateDrawToolBar();
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount) {
		pFig->SetID(++IDCount);
		FigList[FigCount++] = pFig;
	}
}
int ApplicationManager::GetFigCount()
{
	return FigCount;
}
CFigure* ApplicationManager::GetFigList(int i)
{
	return FigList[i];
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(Point p) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL

	for (int i = FigCount - 1; i >= 0; i--) {
		if (FigList[i]->PointIn(p) == true) {
			return FigList[i];
		}
	}
	return NULL;

	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.
}
void ApplicationManager::ClearFigList()
{
	//Deletes all figures and nullifies the FigList (used with load)
	
		for (int i = 0; i < FigCount; i++)
		{
			delete FigList[i];
			FigList[i] = NULL;
		}
		FigCount = 0;
		UnselectAll();
	

}


CFigure* ApplicationManager::getClipboard(CFigure* Clipboard)
{
	return Clipboard;
}

void ApplicationManager::setClipboard(CFigure* ptr) {

	Clipboard = ptr;

}

void ApplicationManager::SelectFig(CFigure* pFig)
{
	pFig->SetSelected(true);
	SelectedFigList[SelectedFigCount] = pFig;
	SelectedFigCount++;
}

void ApplicationManager::UnselectFig(CFigure* pFig)
{
	pFig->SetSelected(false);
	int c;
	for (int i = 0; i < SelectedFigCount; i++) {
		if (SelectedFigList[i] == pFig) {
			c = i;
		}
	}
	for (int i = c; i < SelectedFigCount - 1; i++) {
		SelectedFigList[i] = SelectedFigList[i + 1];
	}
	SelectedFigCount--;
}

void ApplicationManager::UnselectAll()
{
	for (int i = 0; i < SelectedFigCount; i++) {
		SelectedFigList[i]->SetSelected(false);
		delete SelectedFigList[i];
	}
	SelectedFigCount = 0;
}

int ApplicationManager::GetSelectedFigCount()
{
	return SelectedFigCount;
}

CFigure* ApplicationManager::GetSelectedFigs(int i)
{
	return SelectedFigList[i];
}

void ApplicationManager::SaveAll(ofstream& OutFile)
{
	//Loop on each figure ,then saving it 
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Save(OutFile);
	}
}


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
color ApplicationManager::GetColor()
{
	return Color;
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
