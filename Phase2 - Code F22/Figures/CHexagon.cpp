#include"CHexagon.h"
#include <cmath>
#include "DEFS.h"
#include"GUI/Output.h"
#include"Figures/CFigure.h"
#include "CHexagon.h"
#include <string>



CHexagon::CHexagon(Point Center,GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
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

void CHexagon::Save(ofstream& OutFile)
{
	/// Get parameters  ///
	string DrawCOLOR = getColorType(FigGfxInfo.DrawClr);


	/// save format is ( "HEX"    "ID of hex"     "Center"      "Drawing color"    "fillcolor if filled" ///
	if (FigGfxInfo.isFilled == true)
	{
		string FillCOLOR = getColorType(FigGfxInfo.FillClr);
		OutFile << "HEX" << '\t' << ID << '\t' << P1 << '\t' << DrawCOLOR << '\t' << FillCOLOR << endl;
	}
	else
	{
		OutFile << "HEX" << '\t' << ID << '\t' << P1 << '\t' << DrawCOLOR << '\t' << "NO FILL" << endl;

	}
}

void CHexagon::movecrdnts(Point pClicked, Point p2, Point p3)
{

}
