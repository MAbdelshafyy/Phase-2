#include "CCircle.h"
#include <cmath>
#include <fstream>
#include <string>


CCircle::CCircle(Point Point1, Point Point2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo) ///Initializer for constructor "inherited class"
{
	P1 = Point1;
	P2 = Point2;
}

void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCirc to draw a circle on the screen
	pOut->DrawCirc(P1, P2, FigGfxInfo, Selected);
}
void CCircle::movecrdnts(Point pClicked, Point p2, Point p3) {

	p2.x = P2.x - P1.x + pClicked.x;
	p2.y = P2.y - P1.y + pClicked.y;
}

bool CCircle::PointIn(Point p)
{
	Point C;
	C.x = (P1.x + P2.x) / 2;
	C.y = (P1.y + P2.y) / 2;
	double d = sqrt((p.x - C.x) * (p.x - C.x) + (p.y - C.y) * (p.y - C.y));
	double r =sqrt( ((P2.x - P1.x) * (P2.x - P1.x) + (P2.y - P1.y) * (P2.y - P1.y)))/2;
	if (d <= r)
		return true;
	else
		return false;
}

void CCircle::PrintInfo(Output* pOut)
{
	string s = ("ID: " + to_string(ID) + ", Circle, Border color: " + GetColorType(GetDrawClr())) + ", Filling color: ";
	if (FigGfxInfo.isFilled)
		s += GetColorType(GetFillClr());
	else
		s += "not filled";
	pOut->PrintMessage(s);
}

void CCircle::Save(ofstream& OutFile)
{
	Point Center;
	Center.x = (P1.x + P2.x) / 2;
	Center.y = (P1.y + P2.y) / 2;
	double radius = sqrt(pow(P2.x - P1.x, 2) + pow(P2.y - P1.y, 2)) / 2.0;
	/// Saving parameters
	string DrawCOLOR = GetColorType(FigGfxInfo.DrawClr);


	/// Format of saved parameters: Circ  "ID of circ"    "x coord of center"    "y coord of center"   "radius"    "Drawing color"    "if filled filling color"
	if (FigGfxInfo.isFilled == true)
	{
		string FillCOLOR = GetColorType(FigGfxInfo.FillClr);
		OutFile << "CIRC" << '\t' << ID << '\t' << Center.x << '\t' << Center.y << '\t' << radius << '\t' << DrawCOLOR << '\t' << FillCOLOR << endl;
	}
	else
	{
		OutFile << "CIRC" << '\t' << ID << '\t' << Center.x << '\t' << Center.y << '\t' << radius << '\t' << DrawCOLOR << '\t' << "NO FILL" << endl;

	}
}
void CCircle::Load(ifstream& Infile)
{
	Point Center;
	Center.x = (P1.x + P2.x) / 2;
	Center.y = (P1.y + P2.y) / 2;
	double radius = sqrt(pow(P2.x - P1.x, 2) + pow(P2.y - P1.y, 2)) / 2.0;
	string DrawCOLOR;
	string FillCOLOR;
	Infile >> ID >> Center.x >> Center.y >> radius;
	Infile >> DrawCOLOR;
	FigGfxInfo.DrawClr = getColorObj(DrawCOLOR);
	if (FillCOLOR = "NO FILL")
	{
		FigGfxInfo.isFilled = false;
	}
	else
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = getColorObj(FillCOLOR);
	}
	P1.x = Center.x + radius;
	P1.y = Center.y;
	P2.x = Center.x - radius;
	P2.y = Center.y;
	FigGfxInfo.BorderWdth = UI.PenWidth;
	SetID(ID);
}

