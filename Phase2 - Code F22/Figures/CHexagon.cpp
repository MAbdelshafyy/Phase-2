#include "CHexagon.h"
#include <cmath>
#include <fstream>


CHexagon::CHexagon(Point Center, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	P1 = Center;
}

void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHexagon to draw a square on the screen
	pOut->DrawHexagon(P1, FigGfxInfo, Selected);
}

bool CHexagon::PointIn(Point p)
{
	Point P11, P12, P13, P21, P22, P23; //vertices of hexagon
	P11.x = P1.x - 100;
	P12.x = P1.x - 50;
	P21.x = P1.x + 50;
	P22.x = P1.x + 100;
	P23.x = P1.x + 50;
	P13.x = P1.x - 50;
	P11.y = P1.y;
	P12.y = P1.y - (sqrt(3) * 50);
	P21.y = P1.y - (sqrt(3) * 50);
	P22.y = P1.y;
	P23.y = P1.y + (sqrt(3) * 50);
	P13.y = P1.y + (sqrt(3) * 50);



	if ((p.x >= P1.x - 50) && (p.x <= P1.x + 50) && (p.y >= P1.y - (sqrt(3) * 50)) && (p.y <= P1.y + (sqrt(3) * 50)))
		return true;
	else if ((p.x < P1.x - 50) && (p.x >= P1.x - 100)) {
		double A = getTriangleArea(P11, P12, P13);
		double A1 = getTriangleArea(p, P12, P13);
		double A2 = getTriangleArea(P11, p, P13);
		double A3 = getTriangleArea(P11, P12, p);
		return (A == A1 + A2 + A3);
	}
	else if ((p.x > P1.x + 50) && (p.x <= P1.x + 100)) {
		double A = getTriangleArea(P21, P22, P23);
		double A1 = getTriangleArea(p, P22, P23);
		double A2 = getTriangleArea(P21, p, P23);
		double A3 = getTriangleArea(P21, P22, p);
		return (A == A1 + A2 + A3);
	}
	else
		return false;
}
void CHexagon::movecrdnts(Point pClicked, Point p2, Point Center2)
{
	p2.x = Center2.x - P1.x + pClicked.x;
	p2.y = Center2.y - P1.y + pClicked.y;
}
void CHexagon::PrintInfo(Output* pOut)
{
	string s = ("ID: " + to_string(ID) + ", Hexagon, Border color: " + GetColorType(GetDrawClr())) + ", Filling color: ";
	if (FigGfxInfo.isFilled)
		s += GetColorType(GetFillClr());
	else
		s += "not filled";
	pOut->PrintMessage(s);
}

void CHexagon::Save(ofstream& OutFile)
{
	/// Get parameters  ///
	string DrawCOLOR = GetColorType(FigGfxInfo.DrawClr);


	/// save format is ( "HEX"    "ID of hex"     "Center"      "Drawing color"    "fillcolor if filled" ///
	if (FigGfxInfo.isFilled == true)
	{
		string FillCOLOR = GetColorType(FigGfxInfo.FillClr);
		OutFile << "HEX" << '\t' << ID << '\t' << P1.x << '\t' << P1.y << '\t' << DrawCOLOR << '\t' << FillCOLOR << endl;
	}
	else
	{
		OutFile << "HEX" << '\t' << ID << '\t' << P1.x << '\t' << P1.y << '\t' << DrawCOLOR << '\t' << "NO FILL" << endl;

	}
}
void CHexagon::Load(ifstream& InFile)
{
	string DrawCOLOR;
	string FillCOLOR;
	InFile >> ID >> P1.x>>P1.y;
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

int CHexagon::ShapeCounter()
{
	return 0;
}

