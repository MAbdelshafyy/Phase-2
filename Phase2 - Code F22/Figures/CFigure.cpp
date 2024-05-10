#include "CFigure.h"
#include <fstream>
#include <string>

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }
void CFigure::getCopy()
{}

void CFigure::SetID(int id)
{
	ID = id;
}

int CFigure::GetID() const
{
	return ID;
}

string CFigure::getColorType(color type) const
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
		return "ORANGE"
	}

	if (type == GREEN)
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

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
GfxInfo CFigure::getGfxInfo() const
{
	return GfxInfo();
}

void CFigure::Delete(CFigure* SelectedFig) {
}

