#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	int IDCount;

	CFigure* SelectedFig;
	CFigure* SelectedFigList[10];

	color Color;

	int SelectedFigCount = 0;
	

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

	CFigure* Clipboard;  //Pointer to copied/cut figure

public:	
	ApplicationManager(); 
	~ApplicationManager();
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	int GetFigCount();
	CFigure* GetFigList(int i);
	CFigure *GetFigure(Point p) const; //Search for a figure given a point inside the figure

	void setClipboard(CFigure* ptr);
	CFigure* getClipboard(CFigure* ptr);

	void SelectFig(CFigure* pFig);
	void UnselectFig(CFigure* pFig);
	void UnselectAll();
	int GetSelectedFigCount();
	CFigure* GetSelectedFigs(int i);

	void SaveAll(ofstream& OutFile);

	void dltfig(CFigure* selectedFig) {}//delete el figure el selected

	color GetColor();
		
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
};

#endif