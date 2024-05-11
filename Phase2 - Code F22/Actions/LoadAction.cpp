#include "LoadAction.h"
#include <iostream>
#include <fstream>
#include "ApplicationManager.h"
#include <string>
#include "GUI\input.h"
#include "GUI\output.h"
#include "Figures\CFigure.h"
#include "Figures\CRectangle.h"
color LoadAction::GetColorObj(string obj) const
{
	
		if (obj == "RED")
		{
			return RED;
		}

		if (obj == "BLUE")
		{
			return BLUE;
		}

		if (obj == "BLACK")
		{
			return BLACK;
		}

		if (obj == "YELLOW")
		{
			return YELLOW;
		}

		if (obj == "ORANGE")
		{
			return ORANGE;
		}

		if (obj == "GREEN")
		{
			return GREEN;
		}

	
}

LoadAction::LoadAction(ApplicationManager* pApp):Action(pApp)
{}

void LoadAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Enter the name of the file you want to load");

	FileName = pIn->GetSrting(pOut);


}


void LoadAction::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	bool tryAgain = true;

	while (tryAgain)
	{
		ReadActionParameters();

		// Open the file for input
		InFile.open(FileName + ".txt");

		// Check if the file is open
		if (InFile)
		{
			///initialize a pointer from cfigure with null means that it doesn't point to anything
			CFigure* Fig = NULL;
			// File is open, proceed with loading
			pOut->PrintMessage("File found. Loading...");
			// Exit the loop
			tryAgain = false; 
			/// First clear the drawing area
			pOut->ClearDrawArea();  
			///initialize the total number of figures variable, draw color and fill color as variables
			int numfig;
			string DrawCOLOR;
			/// read the first string from the file and store it in drawcolor
			InFile >> DrawCOLOR;
			/// change it from string to an object in color class
			UI.DrawClr() = GetColorObj(DrawCOLOR);
			string FillCOLOR;
			///read the second string from the file & store it in the fillcolor variable  
			InFile >> FillCOLOR;
			///change it from string to an object in color class
			UI.FillClr() = GetColorObj(FillCOLOR);
			/// reads the first integer which is in the save function the total number of figures
			InFile >> numfig;
			///Clearing the figures list///
			pManager->ClearFigList();

			/// looping on the figures///
			string name;
			for (int i = 0; i < numfig; i++)
			{
				if (name == "RECT")
				{
					Fig = new CRectangle;
				}
				else if (name == "CIRC")
				{
					Fig = new CCircle;
				}
				else if (name == "TRIANGLE")
				{
					Fig = new CTriangle
				}
				else if (name == "SQUARE")
				{
					Fig = new CSquare;
				}
				else if (name == "HEX")
				{
					Fig = new CHexagon;
				}
				///Send to load function in cfigure
				Fig->Load(InFile);
				///Sending to app manager 
				pManager->AddFigure(Fig);
			}
			pOut->PrintMessage("File found and loaded with success");

		}
		else
		{
			// File is not open, show error message
			pOut->PrintMessage("File not found.");

			// Ask the user if they want to try again
			pOut->PrintMessage("Do you want to try and enter file name again? (y/any character)");
			string response = pIn->GetSrting(response);

			// Check user response
			if (response != "y" && response != "Y")
			{
				tryAgain = false; // Exit the loop
			}
		}
	}
}
