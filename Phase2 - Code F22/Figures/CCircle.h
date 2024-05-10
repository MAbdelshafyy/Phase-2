#ifndef CCIRCLE_H
#define CCIRCLE_H

#include"Figures/CFigure.h"

class CCircle : public CFigure
{
private:
	Point P1;     ///Declare Point 1
	Point P2;     ///Declare Point 2
public:
	CCircle(Point,Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const; ///Draw
	virtual bool PointIn(Point p);
	virtual void movecrdnts(Point pClicked, Point p2, Point p3) = 0;
};

#endif
