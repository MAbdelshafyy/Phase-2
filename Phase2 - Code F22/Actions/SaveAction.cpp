#include "SaveAction.h"
#include <fstream>
#include "Action.h"
#include "Figures\CFigure.h"
#include "Output.h"
#include "Input.h"
#include "ApplicationManager.h"
#include <string>


string SaveAction::GetColorType(color type) const
{
	if (type == RED)
	{
		return "RED";
	}

	if (type == BLUE)
	{
		return "BLUE";
	}

	if (type == BLACK)
	{
		return "BLACK";
	}

	if (type == YELLOW)
	{
		return "YELLOW";
	}

	if (type == ORANGE)
	{
		return "ORANGE";
	}

	if (type == DARKGREEN)
	{
		return "GREEN";
	}
}

SaveAction::SaveAction(ApplicationManager* pApp) :Action(pApp)
{}

void SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput(); //Points to output
	Input* pIn = pManager->GetInput();    //Points to input

	pOut->PrintMessage("Enter File name (No Spaces)");  //gets desired filename from user
	FileName = pIn->GetSrting(pOut) + ".txt";  //sets the file name and adjusts it to .txt form

}

void SaveAction::Execute() {

	ReadActionParameters();
	Output* pOut = pManager->GetOutput(); //Points to output
	Input* pIn = pManager->GetInput();    //Points to input

	OutFile.open(FileName); /// open file

	/// Check if file is opened ///

	if (OutFile.is_open())
	{
		int numfig = pManager->GetFigCount();  /// Number of figures by the appmanager pointer

		///Getting the draw color from the UI and putting it as the no.1 line
		string DrawCOLOR = GetColorType(UI.DrawColor);
		OutFile << DrawCOLOR;

		///Getting the fill color from the UI and putting it as the no.2 line
		string FillCOLOR = GetColorType(UI.FillColor);
		OutFile << '\t' << FillCOLOR << endl;

		///Getting the number of figures and putting it as the no.3 line
		OutFile << '\t' << numfig << endl;

		///Using the saveall function from app manager for every figure to save itself 
		pManager->SaveAll(OutFile);

		string s = "File: " + FileName + ".txt" + " " + " has been saved successfully";
		pOut->PrintMessage(s);
		OutFile.close();

	}
	else
	{
		pOut->PrintMessage("File Can't be Saved");
	}








}