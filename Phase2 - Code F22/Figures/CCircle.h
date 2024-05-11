#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point P1;     ///Declare Point 1
	Point P2;     ///Declare Point 2
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const; ///Draw
	virtual bool PointIn(Point p);
	virtual void PrintInfo(Output* pOut);
	virtual void Save(ofstream& OutFile);
        virtual void Load(Ifstream& InFile);
	virtual void movecrdnts(Point pClicked, Point p2, Point p3) ;
};

#endif
