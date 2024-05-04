#include "CHexagon.h"

CHexagon::CHexagon(Point Center, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	P1 = Center;
}

void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHexagon to draw a square on the screen
	pOut->DrawHexagon(P1, FigGfxInfo, Selected);
}
