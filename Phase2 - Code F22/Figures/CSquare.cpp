#include "CSquare.h"
#include <fstream>


CSquare::CSquare(Point Center, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center1 = Center;
}

void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSquare to draw a square on the screen
	pOut->DrawSquare(Center1, FigGfxInfo, Selected);
}

bool CSquare::PointIn(Point p)
{
	return ((p.x >= Center1.x - 100) && (p.x <= Center1.x + 100) && (p.y >= Center1.y - 100) && (p.y <= Center1.y + 100));
}
void CSquare::movecrdnts(Point pClicked, Point p2, Point Center2)
{
	p2.x = Center2.x - Center1.x + pClicked.x;
	p2.y = Center2.y - Center1.y + pClicked.y;
}

void CSquare::PrintInfo(Output* pOut)
{
	string s = ("ID: " + to_string(ID) + ", Square, Border color: " + GetColorType(GetDrawClr())) + ", Filling color: ";
	if (FigGfxInfo.isFilled)
		s += GetColorType(GetFillClr());
	else
		s += "not filled";
	pOut->PrintMessage(s);
}

void CSquare::Save(ofstream& OutFile)
{
	//// saving parameters
	string DrawCOLOR = GetColorType(FigGfxInfo.DrawClr);


	/// Format of saved parameters ( Square   "ID of square"   "Center of square"    "Draw color of square"  "Fill color if filled"  
	if (FigGfxInfo.isFilled == true)
	{
		string FillCOLOR = GetColorType(FigGfxInfo.FillClr);
		OutFile << "SQUARE" << '\t' << ID << '\t' << Center1.x << '\t' << Center1.y << '\t' << DrawCOLOR << '\t' << FillCOLOR << endl;
	}
	else
	{
		OutFile << "SQUARE" << '\t' << ID << '\t' << Center1.x << '\t' << Center1.y << '\t' << DrawCOLOR << '\t' << "NO FILL" << endl;

	}
}
void CSquare::Load(ifstream& InFile)
{   
	/// Initialize colors///
	string DrawCOLOR;
	string FillCOLOR;
	/// read id and point///
	InFile >> ID >> Center1.x>>Center1.y;
	/// set draw color///
	InFile >> DrawCOLOR;
	FigGfxInfo.DrawClr = getColorObj(DrawCOLOR);
	InFile >> FillCOLOR;
	//if filled set the fill clr
	if (FillCOLOR == "NO_FILL")
	{
		FigGfxInfo.isFilled = false;
	}
	else {
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = getColorObj(FillCOLOR);
	}
	///set the border width
	FigGfxInfo.BorderWdth = UI.PenWidth;
	SetID(ID);
}

int CSquare::ShapeCounter()
{
	return 0;
}
