#include "CRectangle.h"
#include <fstream>


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

bool CRectangle::PointIn(Point p)
{
	if ((p.x >= Corner1.x && p.x <= Corner2.x) && (p.y >= Corner1.y && p.y <= Corner2.y))
		return true;
	else
		return false;
}
void CRectangle::movecrdnts(Point pClicked, Point p2, Point p3)
{
	p2.x = Corner2.x - Corner1.x + pClicked.x;
	p2.y = Corner2.y - Corner1.y + pClicked.y;
}
void CRectangle::PrintInfo(Output* pOut)
{
	string s = ("ID: " + to_string(ID) + ", Rectangle, Border color: " + GetColorType(GetDrawClr())) + ", Filling color: ";
	if (FigGfxInfo.isFilled)
		s += GetColorType(GetFillClr());
	else
		s += "not filled";
	pOut->PrintMessage(s);
}

void CRectangle::Save(ofstream& OutFile)
{
	/// Get Parameters ///
	string DrawCOLOR = GetColorType(FigGfxInfo.DrawClr);
	/// Save parameters and the format is ( "RECT"    "ID of rect"   "Corner 1"    "Corner 2"   "Draw color"   "Fill color if filled" )

	if (FigGfxInfo.isFilled == true)
	{
		string FillCOLOR = GetColorType(FigGfxInfo.FillClr);
		OutFile << "RECT" << '\t' << ID << '\t' << Corner1.x << '\t' << Corner1.y << '\t' << Corner2.x << '\t' << Corner2.y << '\t' << DrawCOLOR << '\t' << FillCOLOR << endl;
	}
	else
	{
		OutFile << "RECT" << '\t' << ID << '\t' << Corner1.x << '\t' << Corner1.y << '\t' << Corner2.x << '\t' << Corner2.y << '\t' << DrawCOLOR << '\t' << "NO FILL" << endl;
	}
}
void CRectangle::Load(ifstream& InFile)
{
	string DrawCOLOR;
	string FillCOLOR;
	InFile >> ID >> Corner1 >> Corner2;
	InFile >> DrawCOLOR;
	FigGfxInfo.DrawClr = getColorObj(DrawCOLOR);
	InFile >> FillCOLOR;
	if (FillCOLOR == "NO_FILL")
	{
		FigGfxInfo.isFilled = false;
	}
	else {
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = getColorObj(FillCOLOR);
	}
	///set the border width and calc the radius
	FigGfxInfo.BorderWdth = UI.PenWidth;
	SetID(ID);
}

int CRectangle::ShapeCounter()
{
	return 0;
}
