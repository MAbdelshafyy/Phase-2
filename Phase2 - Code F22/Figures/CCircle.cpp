#include "CCircle.h"
#include <cmath>
#include "CCircle.h"


CCircle::CCircle(Point Point1,Point Point2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo) ///Initializer for constructor "inherited class"
{
	P1 = Point1;
	P2 = Point2;
}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCirc to draw a circle on the screen
	pOut->DrawCirc(P1, P2, FigGfxInfo, Selected);
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

void CCircle::movecrdnts(Point pClicked, Point p2, Point p3)
{
}
