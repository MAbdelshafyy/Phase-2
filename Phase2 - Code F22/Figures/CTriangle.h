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
	CTriangle(Point,Point,Point,GfxInfo FigGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void movecrdnts(Point pClicked, Point p2, Point p3) ;
};
#endif
