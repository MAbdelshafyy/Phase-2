#include "CSquare.h"

CSquare::CSquare(Point, GfxInfo FigureGfxInfo)
{
	Center1 = Center;
}

void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSquare to draw a square on the screen
	pOut->DrawSquare(Center1, FigGfxInfo, Selected);
}
