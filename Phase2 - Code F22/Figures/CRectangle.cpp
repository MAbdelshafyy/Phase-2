#include "CRectangle.h"
#include <string>
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

void CRectangle::Save(ofstream& OutFile)
{
	/// Get Parameters ///
	string DrawCOLOR = getColorType(FigGfxInfo.DrawClr);
	/// Save parameters and the format is ( "RECT"    "ID of rect"   "Corner 1"    "Corner 2"   "Draw color"   "Fill color if filled" )

	if (FigGfxInfo.isFilled == true)
	{
		string FillCOLOR = getColorType(FigGfxInfo.FillClr);
		OutFile << "RECT" << '\t' << ID << '\t' << Corner1 << '\t' << Corner2 << '\t' << DrawCOLOR << '\t' << FillCOLOR << endl;
	}
	else
	{
		OutFile << "RECT" << '\t' << ID << '\t' << Corner1 << '\t' << Corner2 << '\t' << DrawCOLOR << '\t' << "NO FILL" << endl;
	}

}
bool CRectangle::PointIn(Point p)
{
	if ((p.x >= Corner1.x && p.x <= Corner2.x) && (p.y >= Corner1.y && p.y <= Corner2.y))
		return true;
	else
		return false;
}
