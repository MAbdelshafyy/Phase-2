#include "CSquare.h"
#include "CSquare.h"

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

void CSquare::movecrdnts(Point pClicked, Point p2, Point p3)
{

}
