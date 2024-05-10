#include "CTriangle.h"
#include <fstream>


CTriangle::CTriangle(Point Corner1, Point Corner2, Point Corner3, GfxInfo FigGfxInfo) :CFigure(FigGfxInfo)
{
	P1 = Corner1;
	P2 = Corner2;
	P3 = Corner3;
}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTri to draw a square on the screen
	pOut->DrawTri(P1, P2, P3, FigGfxInfo, Selected);
}

bool CTriangle::PointIn(Point p)
{
	double A = getTriangleArea(P1, P2, P3);
	double A1 = getTriangleArea(p, P2, P3);
	double A2 = getTriangleArea(P1, p, P3);
	double A3 = getTriangleArea(P1, P2, p);
	return (A == A1 + A2 + A3);
}

void CTriangle::PrintInfo(Output* pOut)
{
	string s = ("ID: " + to_string(ID) + ", Triangle, Border color: " + GetColorType(GetDrawClr())) + ", Filling color: ";
	if (FigGfxInfo.isFilled)
		s += GetColorType(GetFillClr());
	else
		s += "not filled";
	pOut->PrintMessage(s);
}

void CTriangle::Save(ofstream& OutFile)
{
	/// Getting color and fillcolor
	string DrawCOLOR = GetColorType(FigGfxInfo.DrawClr);


	///Saving parameters in file as follows ( TRIANGLE    "Corner 1"    "Corner 2"    "Corner 3"    "Drawing color"   "Filling color if filled" ////

	if (FigGfxInfo.isFilled == true)
	{
		string FillCOLOR = GetColorType(FigGfxInfo.FillClr);
		OutFile << "TRIANGLE" << '\t' << P1.x << '\t' << P1.y << '\t' << P2.x << '\t' << P2.y << '\t' << P3.x << '\t' << P3.y << '\t' << DrawCOLOR << '\t' << FillCOLOR << endl;
	}
	else
	{
		OutFile << "TRIANGLE" << '\t' << P1.x << '\t' << P1.y << '\t' << P2.x << '\t' << P2.y << '\t' << P3.x << '\t' << P3.y << '\t' << DrawCOLOR << '\t' << "NO FILL" << endl;

	}

}

int CTriangle::ShapeCounter()
{
	return 0;
}


