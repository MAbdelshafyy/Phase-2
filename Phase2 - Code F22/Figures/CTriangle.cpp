#include "CTriangle.h"

CTriangle::CTriangle(Point, Point, Point, GfxInfo FigGfxInfo):CFigure(FigGfxInfo)
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
