#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s;
}

bool CFigure::IsSelected() const
{	return Selected; }

double CFigure::getTriangleArea(Point A, Point B, Point C)
{
	return abs((A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)) / 2);
}

void CFigure::DeleteFigure(CFigure* pFig)
{
	delete pFig;
}

int CFigure::GetID()
{
	return ID;
}

void CFigure::SetID(int id)
{
	ID = id;
}

string CFigure::GetColorType(color type)
{
	if (type == RED)
	{
		return "RED";
	}

	if (type == BLUE)
	{
		return "BLUE";
	}

	if (type == BLACK)
	{
		return "BLACK";
	}

	if (type == YELLOW)
	{
		return "YELLOW";
	}

	if (type == ORANGE)
	{
		return "ORANGE";
	}

	if (type == DARKGREEN)
	{
		return "GREEN";
	}
}
color CFigure::getColorObj(string obj) const
{
	if (obj == "RED")
	{
		return RED;
	}

	if (obj == "BLUE")
	{
		return BLUE;
	}

	if (obj == "BLACK")
	{
		return BLACK;
	}

	if (obj == "YELLOW")
	{
		return YELLOW;
	}

	if (obj == "ORANGE")
	{
		return ORANGE;
	}

	if (obj == "GREEN")
	{
		return GREEN;
	}
	
}

color CFigure::GetDrawClr()
{
	return FigGfxInfo.DrawClr;
}

color CFigure::GetFillClr()
{
	return FigGfxInfo.FillClr;
}

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

