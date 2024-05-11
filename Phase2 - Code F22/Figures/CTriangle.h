#ifndef CTRIANGLE_H
#define CTRIANGLE_H
#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point P1;
	Point P2;
	Point P3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool PointIn(Point p);
	virtual void PrintInfo(Output* pOut);
	virtual void Save(ofstream& OutFile);
	virtual int ShapeCounter();
	virtual void movecrdnts(Point pClicked, Point p2, Point p3)=0;

};
#endif
