#include "CCircle.h"

CCircle::CCircle(Point, Point, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo) ///Initializer for constructor "inherited class"
{
	P1 = Point1;
	P2 = Point2;
}

void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCirc to draw a square on the screen
	pOut->DrawCirc(P1, P2, FigGfxInfo, Selected);
}
