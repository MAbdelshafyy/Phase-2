#include "CSquare.h"
#include <string>

CSquare::CSquare(Point Center ,GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
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

void CSquare::Save(ofstream& OutFile)
{
	//// saving parameters
	string DrawCOLOR = getColorType(FigGfxInfo.DrawClr);
	

	/// Format of saved parameters ( Square   "ID of square"   "Center of square"    "Draw color of square"  "Fill color if filled"  
	if (FigGfxInfo.isFilled == true)
	{
		string FillCOLOR = getColorType(FigGfxInfo.FillClr);
		OutFile << "SQUARE" << '\t' << ID << '\t' << Center1 << '\t' << DrawCOLOR << '\t' << FillCOLOR << endl;
	}
	else
	{
		OutFile << "SQUARE" << '\t' << ID << '\t' << Center1 << '\t' << DrawCOLOR << '\t' << "NO FILL" << endl;

	}
}

void CSquare::movecrdnts(Point pClicked, Point p2, Point p3)
{
}
